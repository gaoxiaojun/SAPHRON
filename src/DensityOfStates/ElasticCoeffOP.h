#pragma once 

#include <armadillo>
#include <functional>
#include <map>

#include "DOSOrderParameter.h"
#include "../Particles/ParticleObserver.h"
#include "../Worlds/World.h"
#include "../Simulation/SimInfo.h"

namespace SAPHRON
{
	typedef std::function<bool(const Particle*)> EFilterFunc;

	// Class for elastic coefficient order parameter of liquid crystals, based on the 
	// Frank-Oseen elastic free energy. 
	class ElasticCoeffOP : public DOSOrderParameter, public ParticleObserver
	{
	private:
		Matrix3D _Q;
		EFilterFunc _efunc;
		arma::cx_colvec3 _eigval;
		arma::cx_mat33 _eigvec;
		arma::uword _imax;
		
		// Particle count for averaging.
		int _pcount;

		// Delta distance for elastic coefficient calculation.
		double _dxj;

	protected:
		
		// Calculate acceptance probability.
		virtual double CalcAcceptanceProbability(const Energy& ei, 
												 const Energy& ef, 
												 double opi, 
												 double opf,
												 const World& w) const override
		{
			auto& sim = SimInfo::Instance();
			auto de = ef.total() - ei.total();
			double p = exp(-de/(sim.GetkB()*w.GetTemperature()) + opi - opf);
			return p > 1.0 ? 1.0 : p;
		}

	public:

		// Initialize ElasticCoeffOP class. A user supplied filter function will determine which 
		// particles will contribute to the elastic order parameter (true for include, false otherwise).
		// The value h represents the length over which to compute the derivative (dni/dxj).
		ElasticCoeffOP(const Histogram& hist, World* world, double dxj, EFilterFunc efunc) : 
			DOSOrderParameter(hist), _Q(arma::fill::zeros), _efunc(efunc), _eigval(arma::fill::zeros), 
			_eigvec(arma::fill::zeros), _imax(0), _pcount(0), _dxj(dxj)
		{

			for (int i = 0; i < world->GetParticleCount(); ++i)
			{
				auto* p = world->SelectParticle(i);
				p->AddObserver(this);

				// Particle is counted.
				if(_efunc(p))
				{
					++_pcount;
					auto& dir = p->GetDirector();
					_Q += arma::kron(dir.t(), dir) - 1.0/3.0*arma::eye(3,3);
				}
			}

			// Average.
			_Q *= 3.0/(2.0*_pcount);
		}


		// Evaluate the order parameter.
		virtual double EvaluateOrderParameter(const World&) const override
		{
			double dny = _eigvec(1, _imax).real();
			
			// Return dny/dx. (this is twist, hardcoded for now). 
			return dny/_dxj;

		}

		// Update Q tensor on particle director change.
		virtual void ParticleUpdate(const ParticleEvent& pEvent) override
		{
			if(!pEvent.director)
				return;

			auto* p = pEvent.GetParticle();
			if(!_efunc(p))
				return;

			const auto& pdir = pEvent.GetOldDirector();
			const auto& dir = p->GetDirector();
			_Q += 3.0/(2.0*_pcount)*(arma::kron(dir.t(), dir) - arma::kron(pdir.t(), pdir));

			// Eager decomposition. Only on appropriate update.
			if(!arma::eig_gen(_eigval, _eigvec, _Q))
			   std::cerr << "Eigenvalue decomposition failed!!" << std::endl;

			_eigval.max(_imax);
		}

		// Serialize.
		virtual void Serialize(Json::Value& json) const override
		{
			json["type"] = "ElasticCoeff";
			json["mode"] = "twist";
			json["xrange"] = _dxj;
			
			// TODO: fix this.
			json["world"] = 0;
		}

		// Get layer director.
		Director GetDirector()
		{
			return arma::real(_eigvec.col(_imax));
		}

	};
}