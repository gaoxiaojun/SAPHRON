#include "Ensembles/NVTEnsemble.h"
#include "Loggers/CSVLogger.h"
#include "Loggers/ConsoleLogger.h"
#include "Models/LebwohlLasherModel.h"
#include "Moves/SphereUnitVectorMove.h"
#include <iostream>
#include <sstream>

using namespace std;

int main (int argc, char const* argv[])
{
	if(argc != 6)
	{
		cerr << "Program syntax:" << argv[0] <<
		" lattice-size temperature iterations model-outputfile site-outputfile" << endl;
		return 0;
	}

	int latticeSize;
	int iterations;
	double temperature;
	string outputModel, outputSites;
	stringstream ss;

	// Parse input
	ss.clear();
	ss.str(argv[1]);
	if(!(ss >> latticeSize))
		cerr << "Invalid lattice size. Must be an integer." << endl;

	ss.clear();
	ss.str(argv[2]);
	if(!(ss >> temperature))
		cerr << "Invalid temperature. Must be a double." << endl;

	ss.clear();
	ss.str(argv[3]);
	if(!(ss >> iterations))
		cerr << "Invalid iterations. Must be an integer." << endl;

	ss.clear();
	ss.str(argv[4]);
	if(!(ss >> outputModel))
		cerr << "Invalid output file. Must be a string." << endl;

	ss.clear();
	ss.str(argv[5]);
	if(!(ss >> outputSites))
		cerr << "Invalid output file. Must be a string." << endl;

	// Initialize model.
	Models::LebwohlLasherModel model(latticeSize);
	Moves::SphereUnitVectorMove move;
	Loggers::ConsoleLogger logger(100);
	Ensembles::NVTEnsemble<Site> ensemble(model, temperature);

	// Energy
	auto energy = [] (BaseModel& model) {
		double u = 0;
		int c = model.GetSiteCount();
		for(int i = 0; i < c; i++)
			u += model.EvaluateHamiltonian(i);
		u /= 2*c;
		return u;
	};
	// Add loggable data
	logger.AddModelProperty("Energy", energy);

	// Add logger and move to ensemble.
	ensemble.AddLogger(logger);
	ensemble.AddMove(move);

	// Iterate
	for(int i = 0; i < iterations; i++)
		ensemble.Sweep();

	return 0;
}
