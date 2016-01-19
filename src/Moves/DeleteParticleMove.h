#pragma once

#include "Move.h"
#include "../Utils/Helpers.h"
#include "../Utils/Rand.h"
#include "../Worlds/WorldManager.h"
#include "../ForceFields/ForceFieldManager.h"
#include "../DensityOfStates/DOSOrderParameter.h"

namespace SAPHRON
{
	// Class for particle deletion move.
	class DeleteParticleMove : public Move
	{
	private: 
		Rand _rand;
		int _rejected;
		int _performed;
		std::vector<int> _species;
		bool _prefac;
		bool _multi_delete;
		int _seed;

	public:
		DeleteParticleMove(const std::vector<int>& species, 
						   bool multi_delete, int seed = 45843) :
		_rand(seed), _rejected(0), _performed(0), _species(0), 
		_prefac(true), _multi_insertion(multi_delete), _seed(seed)
		{
			// Verify species list and add to local vector.
			auto& list = Particle::GetSpeciesList();
			for(auto& id : species)
			{
				if(id >= (int)list.size())
				{
					std::cerr << "Species ID \"" 
							  << id << "\" provided does not exist." 
							  << std::endl;
					exit(-1);
				}
				_species.push_back(id);
			}
		}

		DeleteParticleMove(const std::vector<std::string>& species, 
						   int seed = 45843) : 
						   bool multi_delete, int seed = 45843) :
		_rand(seed), _rejected(0), _performed(0), _species(0), 
		_prefac(true), _multi_delete(multi_delete), _seed(seed)
		{
			// Verify species list and add to local vector.
			auto& list = Particle::GetSpeciesList();
			for(auto& id : species)
			{
				auto it = std::find(list.begin(), list.end(), id);
				if(it == list.end())
				{
					std::cerr << "Species ID \""
							  << id << "\" provided does not exist."
							  << std::endl;
					exit(-1);
				}
				_species.push_back(it - list.begin());
			}
		}

		virtual void Perform(WorldManager* wm, 
							 ForceFieldManager* ffm, 
							 const MoveOverride& override) override
		{
			// Get random world.
			World* w = wm->GetRandomWorld();

			Particle* plist[32];

			int NumberofParticles=1;

			// Unstash into particle list or single particle
			if(_multi_insertion)
			{
				auto& comp = w->GetComposition();
				NumberofParticles=_species.size();
				for (int i = 0; i < _species.size(); i++)
				{
					if(comp[_species[i]] == 0)
						return;
					plist[i] = w->DrawRandomParticleBySpecies(_species[i]);
					if(plist[i] == nullptr) // Safety check.
						return;
				}
			}
			else
			{
				size_t n = _species.size();
				assert(n > 0);
				auto type = _rand.int32() % n;
				auto& comp = w->GetComposition();
				if(comp[type] == 0)
					return;
				plist[0] = w->DrawRandomParticleBySpecies(_species[type]);
				if(plist[0] == nullptr) // Safety check.
					return;
			}

			double Prefactor = 1;
			auto& sim = SimInfo::Instance();
			auto beta = 1.0/(sim.GetkB()*w->GetTemperature());
			auto V = w->GetVolume();
			EPTuple ei;

			for (int i = 0; i < NumberofParticles; i++)
			{
				auto& p = plist[i];

				auto id = p->GetSpeciesID();
				auto& comp = w->GetComposition();
				auto N = comp[id];
				auto mu = w->GetChemicalPotential(id);
				auto lambda = w->GetWavelength(id);

				Prefactor*=(lambda*lambda*lambda*N)/V*exp(-beta*mu);

				// Evaluate old energy. For multi deletion moves
				// Need to remove particle one by one so energy
				// is not double counted.
				auto ei += ffm->EvaluateHamiltonian(*p, comp, V);
				w->RemoveParticle(p);
			}

			++_performed;

			// The acceptance rule is from Frenkel & Smit Eq. 5.6.9.
			auto pacc = Prefactor*exp(beta*ei.energy.total());
			pacc = pacc > 1.0 ? 1.0 : pacc;

			if(!(override == ForceAccept) && (pacc < _rand.doub() || override == ForceReject))
			{
				// Add it back to the world.
				for (int i = 0; i < NumberofParticles; i++)
				{
					auto& p = plist[i];
					w->AddParticle(p);
				}
				++_rejected;
			}
			else
			{
				// Stash the particle which actually removes it from the world. 
				for (int i = 0; i < NumberofParticles; i++)
				{
					auto& p = plist[i];
					w->StashParticle(p);
				}

				// Update energies and pressures.
				w->IncrementEnergy(-1.0*ei.energy);
				w->IncrementPressure(-1.0*ei.pressure);
			}
		}

		virtual void Perform(World* w, 
							 ForceFieldManager* ffm, 
							 DOSOrderParameter* op, 
							 const MoveOverride& override) override
		{

			Particle* plist[32];

			int NumberofParticles=1;

						// Unstash into particle list or single particle
			if(_multi_insertion)
			{
				auto& comp = w->GetComposition();
				NumberofParticles=_species.size();
				for (int i = 0; i < _species.size(); i++)
				{
					if(comp[_species[i]] == 0)
						return;
					plist[i] = w->DrawRandomParticleBySpecies(_species[i]);
					if(plist[i] == nullptr) // Safety check.
						return;
				}
			}
			else
			{
				size_t n = _species.size();
				assert(n > 0);
				auto type = _rand.int32() % n;
				auto& comp = w->GetComposition();
				if(comp[type] == 0)
					return;
				plist[0] = w->DrawRandomParticleBySpecies(_species[type]);
				if(plist[0] == nullptr) // Safety check.
					return;
			}

			double Prefactor = 1;
			auto& sim = SimInfo::Instance();
			auto beta = 1.0/(sim.GetkB()*w->GetTemperature());
			auto V = w->GetVolume();
			
			auto opi = op->EvaluateOrderParameter(*w);
			EPTuple ei;

			for (int i = 0; i < NumberofParticles; i++)
			{
				auto& p = plist[i];

				auto id = p->GetSpeciesID();
				auto& comp = w->GetComposition();
				auto N = comp[id];
				auto mu = w->GetChemicalPotential(id);
				auto lambda = w->GetWavelength(id);

				if(_prefac)
					Prefactor*=(lambda*lambda*lambda*N)/V*exp(-beta*mu);

				// Evaluate old energy. For multi deletion moves
				// Need to remove particle one by one so energy
				// is not double counted.
				auto ei += ffm->EvaluateHamiltonian(*p, comp, V);
				w->RemoveParticle(p);
			}

			++_performed;

			w->IncrementEnergy(-1.0*ei.energy);
			w->IncrementPressure(-1.0*ei.pressure);
			auto opf = op->EvaluateOrderParameter(*w);
			auto ef = w->GetEnergy();

			// Acceptance rule.
			double pacc = op->AcceptanceProbability(ei.energy, ef, opi, opf, *w);

			if(_prefac)
			{
				pacc *= Prefactor;
			}

			pacc = pacc > 1.0 ? 1.0 : pacc;

			if(!(override == ForceAccept) && (pacc < _rand.doub() || override == ForceReject))
			{
				// Add it back to the world.
				for (int i = 0; i < NumberofParticles; i++)
				{
					auto& p = plist[i];
					w->AddParticle(p);
				}
				w->IncrementEnergy(ei.energy);
				w->IncrementPressure(ei.pressure);
				++_rejected;
			}
			else
			{
				// Stash the particle which actually removes it from the world. 
				for (int i = 0; i < NumberofParticles; i++)
				{
					auto& p = plist[i];
					w->StashParticle(p);
				}
			}
		}

		// Turn on or off the acceptance rule prefactor 
		// for DOS order parameter.
		void SetOrderParameterPrefactor(bool flag) { _prefac = flag; }

		virtual double GetAcceptanceRatio() const override
		{
			return 1.0-(double)_rejected/_performed;
		};

		virtual void ResetAcceptanceRatio() override
		{
			_performed = 0;
			_rejected = 0;
		}

		// Serialize.
		virtual void Serialize(Json::Value& json) const override
		{
			json["type"] = "DeleteParticle";
			json["seed"] = _seed;
			json["op_prefactor"] = _prefac;

			auto& species = Particle::GetSpeciesList();
			for(auto& s : _species)
				json["species"].append(species[s]);
		}

		virtual std::string GetName() const override { return "DeleteParticle"; }

		// Clone move.
		Move* Clone() const override
		{
			return new DeleteParticleMove(static_cast<const DeleteParticleMove&>(*this));
		}

		~DeleteParticleMove(){}
	};
}