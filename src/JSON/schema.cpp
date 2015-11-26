#include "schema.h"

namespace SAPHRON
{
	//INSERT_DEF_HERE
	std::string SAPHRON::JsonSchema::ElasticCoeffOP = "{\"type\": \"object\", \"additionalProperties\": false, \"properties\": {\"type\": {\"type\": \"string\", \"enum\": [\"ElasticCoeff\"]}, \"world\": {\"type\": \"integer\", \"minimum\": 0}, \"mode\": {\"type\": \"string\", \"enum\": [\"twist\"]}, \"xrange\": {\"type\": \"array\", \"maxItems\": 2, \"minItems\": 2, \"items\": {\"type\": \"number\"}}}, \"required\": [\"type\", \"mode\", \"xrange\", \"world\"]}";
	std::string SAPHRON::JsonSchema::WangLandauOP = "{\"type\": \"object\", \"additionalProperties\": false, \"properties\": {\"type\": {\"type\": \"string\", \"enum\": [\"WangLandau\"]}}, \"required\": [\"type\"]}";
	std::string SAPHRON::JsonSchema::Histogram = "{\"type\": \"object\", \"additionalProperties\": false, \"properties\": {\"values\": {\"type\": \"array\", \"items\": {\"type\": \"number\"}}, \"bincount\": {\"type\": \"integer\", \"minimum\": 1}, \"counts\": {\"type\": \"array\", \"items\": {\"type\": \"integer\", \"minimum\": 0}}, \"min\": {\"type\": \"number\"}, \"binwidth\": {\"type\": \"number\", \"minimum\": 0, \"exclusiveMinimum\": true}, \"max\": {\"type\": \"number\"}}, \"required\": [\"min\", \"max\"]}";
	std::string SAPHRON::JsonSchema::DOSSimulation = "{\"type\": \"object\", \"additionalProperties\": false, \"properties\": {\"convergence_factor\": {\"type\": \"number\", \"minimum\": 0, \"exclusiveMinimum\": true}, \"reset_freq\": {\"type\": \"integer\", \"minimum\": 0}, \"target_flatness\": {\"type\": \"number\", \"minimum\": 0, \"maximum\": 1, \"exclusiveMaximum\": true, \"exclusiveMinimum\": true}}}";
	std::string SAPHRON::JsonSchema::Simulation = "{\"type\": \"object\", \"properties\": {\"simtype\": {\"type\": \"string\", \"enum\": [\"standard\", \"DOS\"]}, \"iterations\": {\"type\": \"integer\", \"minimum\": 1}, \"units\": {\"type\": \"string\", \"enum\": [\"real\", \"reduced\"]}, \"mpi\": {\"type\": \"integer\", \"minimum\": 1}}, \"required\": [\"simtype\", \"iterations\"]}";
	std::string SAPHRON::JsonSchema::ForceFields = "{\"type\": \"object\", \"additionalProperties\": false, \"properties\": {\"bonded\": {\"type\": \"array\"}, \"nonbonded\": {\"type\": \"array\"}, \"electrostatic\": {\"type\": \"array\"}}}";
	std::string SAPHRON::JsonSchema::DebyeHuckelFF = "{\"type\": \"object\", \"additionalProperties\": false, \"properties\": {\"rcut\": {\"type\": \"array\", \"minItems\": 1, \"items\": {\"type\": \"number\", \"minimum\": 0, \"exclusiveMinimum\": true}}, \"type\": {\"type\": \"string\", \"enum\": [\"DebyeHuckel\"]}, \"species\": {\"additionalItems\": false, \"type\": \"array\", \"maxItems\": 2, \"minItems\": 2, \"items\": {\"type\": \"string\"}}, \"kappa\": {\"type\": \"number\", \"minimum\": 0}}, \"required\": [\"type\", \"kappa\", \"species\", \"rcut\"]}";
	std::string SAPHRON::JsonSchema::DSFFF = "{\"type\": \"object\", \"additionalProperties\": false, \"properties\": {\"rcut\": {\"type\": \"array\", \"minItems\": 1, \"items\": {\"type\": \"number\", \"minimum\": 0, \"exclusiveMinimum\": true}}, \"type\": {\"type\": \"string\", \"enum\": [\"DSF\"]}, \"species\": {\"additionalItems\": false, \"type\": \"array\", \"maxItems\": 2, \"minItems\": 2, \"items\": {\"type\": \"string\"}}, \"alpha\": {\"type\": \"number\", \"minimum\": 0}}, \"required\": [\"type\", \"alpha\", \"species\", \"rcut\"]}";
	std::string SAPHRON::JsonSchema::LebwholLasherFF = "{\"type\": \"object\", \"additionalProperties\": false, \"properties\": {\"type\": {\"type\": \"string\", \"enum\": [\"LebwohlLasher\"]}, \"epsilon\": {\"type\": \"number\"}, \"gamma\": {\"type\": \"number\"}, \"species\": {\"additionalItems\": false, \"type\": \"array\", \"maxItems\": 2, \"minItems\": 2, \"items\": {\"type\": \"string\"}}}, \"required\": [\"type\", \"epsilon\", \"gamma\", \"species\"]}";
	std::string SAPHRON::JsonSchema::LennardJonesFF = "{\"type\": \"object\", \"additionalProperties\": false, \"properties\": {\"sigma\": {\"type\": \"number\", \"minimum\": 0, \"exclusiveMinimum\": true}, \"type\": {\"type\": \"string\", \"enum\": [\"LennardJones\"]}, \"epsilon\": {\"type\": \"number\", \"minimum\": 0}, \"species\": {\"additionalItems\": false, \"type\": \"array\", \"maxItems\": 2, \"minItems\": 2, \"items\": {\"type\": \"string\"}}, \"rcut\": {\"type\": \"array\", \"minItems\": 1, \"items\": {\"type\": \"number\", \"minimum\": 0, \"exclusiveMinimum\": true}}}, \"required\": [\"type\", \"sigma\", \"epsilon\", \"species\", \"rcut\"]}";
	std::string SAPHRON::JsonSchema::Components = "{\"components\": {\"type\": \"object\", \"minProperties\": 1, \"patternProperties\": {\"^[A-z][A-z0-9]+$\": {\"type\": \"object\", \"properties\": {\"count\": {\"type\": \"integer\", \"minimum\": 1}}, \"required\": [\"count\"]}}, \"additionalProperties\": false}}";
	std::string SAPHRON::JsonSchema::Worlds = "{\"type\": \"array\", \"minItems\": 1, \"items\": {\"type\": \"object\", \"additionalProperties\": false, \"properties\": {\"particles\": {\"type\": \"array\"}, \"type\": {\"type\": \"string\", \"enum\": [\"Simple\"]}, \"temperature\": {\"type\": \"number\", \"minimum\": 0}, \"components\": {\"components\": {\"type\": \"object\", \"minProperties\": 1, \"patternProperties\": {\"^[A-z][A-z0-9]+$\": {\"type\": \"object\", \"properties\": {\"count\": {\"type\": \"integer\", \"minimum\": 1}}, \"required\": [\"count\"]}}, \"additionalProperties\": false}}, \"skin_thickness\": {\"type\": \"number\", \"minimum\": 0}, \"pack\": {\"type\": \"object\", \"properties\": {\"count\": {\"type\": \"integer\", \"minimum\": 1}, \"density\": {\"type\": \"number\", \"minimum\": 0, \"exclusiveMinimum\": true}, \"composition\": {\"type\": \"object\", \"patternProperties\": {\"^[A-z][A-z0-9]+$\": {\"type\": \"number\", \"minimum\": 0.0, \"maximum\": 1.0, \"exclusiveMinimum\": true}}}}}, \"seed\": {\"type\": \"integer\", \"minimum\": 0}, \"nlist_cutoff\": {\"type\": \"number\", \"minimum\": 0, \"exclusiveMinimum\": true}, \"dimensions\": {\"additionalItems\": false, \"type\": \"array\", \"maxItems\": 3, \"minItems\": 3, \"items\": {\"type\": \"number\", \"minimum\": 0}}, \"chemical_potential\": {\"type\": \"object\", \"patternProperties\": {\"^[A-z][A-z0-9]+$\": {\"type\": \"number\"}}}}, \"required\": [\"type\", \"dimensions\", \"nlist_cutoff\", \"skin_thickness\", \"components\"]}}";
	std::string SAPHRON::JsonSchema::SimpleWorld = "{\"type\": \"object\", \"additionalProperties\": false, \"properties\": {\"particles\": {\"type\": \"array\"}, \"type\": {\"type\": \"string\", \"enum\": [\"Simple\"]}, \"temperature\": {\"type\": \"number\", \"minimum\": 0}, \"components\": {\"components\": {\"type\": \"object\", \"minProperties\": 1, \"patternProperties\": {\"^[A-z][A-z0-9]+$\": {\"type\": \"object\", \"properties\": {\"count\": {\"type\": \"integer\", \"minimum\": 1}}, \"required\": [\"count\"]}}, \"additionalProperties\": false}}, \"skin_thickness\": {\"type\": \"number\", \"minimum\": 0}, \"pack\": {\"type\": \"object\", \"properties\": {\"count\": {\"type\": \"integer\", \"minimum\": 1}, \"density\": {\"type\": \"number\", \"minimum\": 0, \"exclusiveMinimum\": true}, \"composition\": {\"type\": \"object\", \"patternProperties\": {\"^[A-z][A-z0-9]+$\": {\"type\": \"number\", \"minimum\": 0.0, \"maximum\": 1.0, \"exclusiveMinimum\": true}}}}}, \"seed\": {\"type\": \"integer\", \"minimum\": 0}, \"nlist_cutoff\": {\"type\": \"number\", \"minimum\": 0, \"exclusiveMinimum\": true}, \"dimensions\": {\"additionalItems\": false, \"type\": \"array\", \"maxItems\": 3, \"minItems\": 3, \"items\": {\"type\": \"number\", \"minimum\": 0}}, \"chemical_potential\": {\"type\": \"object\", \"patternProperties\": {\"^[A-z][A-z0-9]+$\": {\"type\": \"number\"}}}}, \"required\": [\"type\", \"dimensions\", \"nlist_cutoff\", \"skin_thickness\", \"components\"]}";
	std::string SAPHRON::JsonSchema::Particles = "{\"additionalItems\": false, \"type\": \"array\", \"minItems\": 1, \"items\": {\"additionalItems\": false, \"type\": \"array\", \"maxItems\": 4, \"minItems\": 3, \"items\": [{\"type\": \"integer\", \"minimum\": 1}, {\"type\": \"string\"}, {\"additionalItems\": false, \"type\": \"array\", \"maxItems\": 3, \"minItems\": 3, \"items\": {\"type\": \"number\", \"minimum\": 0}}, {\"additionalItems\": false, \"type\": \"array\", \"maxItems\": 3, \"minItems\": 3, \"items\": {\"type\": \"number\"}}, {\"type\": \"string\"}]}}";
	std::string SAPHRON::JsonSchema::Site = "{\"additionalItems\": false, \"type\": \"array\", \"maxItems\": 4, \"minItems\": 3, \"items\": [{\"type\": \"integer\", \"minimum\": 1}, {\"type\": \"string\"}, {\"additionalItems\": false, \"type\": \"array\", \"maxItems\": 3, \"minItems\": 3, \"items\": {\"type\": \"number\", \"minimum\": 0}}, {\"additionalItems\": false, \"type\": \"array\", \"maxItems\": 3, \"minItems\": 3, \"items\": {\"type\": \"number\"}}, {\"type\": \"string\"}]}";
	std::string SAPHRON::JsonSchema::Blueprints = "{\"type\": \"object\", \"minProperties\": 1, \"patternProperties\": {\"^[A-z][A-z0-9]+$\": {\"type\": \"object\", \"minProperties\": 1, \"properties\": {\"count\": {\"type\": \"integer\", \"minimum\": 1}, \"charge\": {\"type\": \"number\"}, \"mass\": {\"type\": \"number\", \"minimum\": 0}, \"children\": {\"type\": \"array\", \"minItems\": 1, \"items\": {\"type\": \"object\", \"properties\": {\"charge\": {\"type\": \"number\"}, \"mass\": {\"type\": \"number\", \"minimum\": 0}, \"species\": {\"type\": \"string\"}}, \"required\": [\"species\"]}}, \"bonds\": {\"type\": \"array\", \"items\": {\"type\": \"array\", \"maxItems\": 2, \"minItems\": 2, \"items\": {\"type\": \"number\", \"minimum\": 0}}}}, \"additionalProperties\": false, \"required\": [\"count\"]}}, \"additionalProperties\": false}";
	std::string SAPHRON::JsonSchema::Selector = "{}";
	std::string SAPHRON::JsonSchema::Director = "{\"additionalItems\": false, \"type\": \"array\", \"maxItems\": 3, \"minItems\": 3, \"items\": {\"type\": \"number\"}}";
	std::string SAPHRON::JsonSchema::Observers = "{\"type\": \"array\"}";
	std::string SAPHRON::JsonSchema::JSONObserver = "{\"additionalProperties\": false, \"properties\": {\"prefix\": {\"type\": \"string\"}, \"type\": {\"type\": \"string\", \"enum\": [\"JSON\"]}, \"frequency\": {\"type\": \"integer\", \"minimum\": 1}}, \"required\": [\"type\", \"prefix\", \"frequency\"]}";
	std::string SAPHRON::JsonSchema::DLMFileObserver = "{\"additionalProperties\": false, \"properties\": {\"type\": {\"type\": \"string\", \"enum\": [\"DLMFile\"]}, \"frequency\": {\"type\": \"integer\", \"minimum\": 1}, \"delimiter\": {\"type\": \"string\"}, \"colwidth\": {\"type\": \"integer\", \"minimum\": 1}, \"fixedwmode\": {\"type\": \"boolean\"}, \"prefix\": {\"type\": \"string\"}, \"flags\": {\"type\": \"object\", \"properties\": {\"hist_lower_outliers\": {\"type\": \"integer\", \"minimum\": 0, \"maximum\": 1}, \"hist_interval\": {\"type\": \"integer\", \"minimum\": 0, \"maximum\": 1}, \"particle_parent_species\": {\"type\": \"integer\", \"minimum\": 0, \"maximum\": 1}, \"particle_species\": {\"type\": \"integer\", \"minimum\": 0, \"maximum\": 1}, \"dos_flatness\": {\"type\": \"integer\", \"minimum\": 0, \"maximum\": 1}, \"world_density\": {\"type\": \"integer\", \"minimum\": 0, \"maximum\": 1}, \"energy_components\": {\"type\": \"integer\", \"minimum\": 0, \"maximum\": 1}, \"world_composition\": {\"type\": \"integer\", \"minimum\": 0, \"maximum\": 1}, \"hist_values\": {\"type\": \"integer\", \"minimum\": 0, \"maximum\": 1}, \"particle_species_id\": {\"type\": \"integer\", \"minimum\": 0, \"maximum\": 1}, \"world_chem_pot\": {\"type\": \"integer\", \"minimum\": 0, \"maximum\": 1}, \"energy_intervdw\": {\"type\": \"integer\", \"minimum\": 0, \"maximum\": 1}, \"pressure_ideal\": {\"type\": \"integer\", \"minimum\": 0, \"maximum\": 1}, \"particle_director\": {\"type\": \"integer\", \"minimum\": 0, \"maximum\": 1}, \"particle_id\": {\"type\": \"integer\", \"minimum\": 0, \"maximum\": 1}, \"pressure_tail\": {\"type\": \"integer\", \"minimum\": 0, \"maximum\": 1}, \"energy_intravdw\": {\"type\": \"integer\", \"minimum\": 0, \"maximum\": 1}, \"pressure_pxy\": {\"type\": \"integer\", \"minimum\": 0, \"maximum\": 1}, \"iteration\": {\"type\": \"integer\", \"minimum\": 0, \"maximum\": 1}, \"particle_parent_id\": {\"type\": \"integer\", \"minimum\": 0, \"maximum\": 1}, \"move_acceptances\": {\"type\": \"integer\", \"minimum\": 0, \"maximum\": 1}, \"pressure_pzz\": {\"type\": \"integer\", \"minimum\": 0, \"maximum\": 1}, \"pressure_pxx\": {\"type\": \"integer\", \"minimum\": 0, \"maximum\": 1}, \"world\": {\"type\": \"integer\", \"minimum\": 0, \"maximum\": 1}, \"world_energy\": {\"type\": \"integer\", \"minimum\": 0, \"maximum\": 1}, \"pressure_pyy\": {\"type\": \"integer\", \"minimum\": 0, \"maximum\": 1}, \"dos_factor\": {\"type\": \"integer\", \"minimum\": 0, \"maximum\": 1}, \"particle_neighbors\": {\"type\": \"integer\", \"minimum\": 0, \"maximum\": 1}, \"hist_counts\": {\"type\": \"integer\", \"minimum\": 0, \"maximum\": 1}, \"world_temperature\": {\"type\": \"integer\", \"minimum\": 0, \"maximum\": 1}, \"energy_connectivity\": {\"type\": \"integer\", \"minimum\": 0, \"maximum\": 1}, \"histogram\": {\"type\": \"integer\", \"minimum\": 0, \"maximum\": 1}, \"pressure_tensor\": {\"type\": \"integer\", \"minimum\": 0, \"maximum\": 1}, \"energy_interelect\": {\"type\": \"integer\", \"minimum\": 0, \"maximum\": 1}, \"world_pressure\": {\"type\": \"integer\", \"minimum\": 0, \"maximum\": 1}, \"particle_position\": {\"type\": \"integer\", \"minimum\": 0, \"maximum\": 1}, \"hist_bin_count\": {\"type\": \"integer\", \"minimum\": 0, \"maximum\": 1}, \"hist_upper_outliers\": {\"type\": \"integer\", \"minimum\": 0, \"maximum\": 1}, \"world_volume\": {\"type\": \"integer\", \"minimum\": 0, \"maximum\": 1}, \"pressure_pxz\": {\"type\": \"integer\", \"minimum\": 0, \"maximum\": 1}, \"energy_bonded\": {\"type\": \"integer\", \"minimum\": 0, \"maximum\": 1}, \"pressure_pyz\": {\"type\": \"integer\", \"minimum\": 0, \"maximum\": 1}, \"energy_intraelect\": {\"type\": \"integer\", \"minimum\": 0, \"maximum\": 1}, \"simulation\": {\"type\": \"integer\", \"minimum\": 0, \"maximum\": 1}, \"particle\": {\"type\": \"integer\", \"minimum\": 0, \"maximum\": 1}}}, \"extension\": {\"type\": \"string\"}}, \"required\": [\"type\", \"prefix\", \"frequency\", \"flags\"]}";
	std::string SAPHRON::JsonSchema::DeleteParticleMove = "{\"type\": \"object\", \"additionalProperties\": false, \"properties\": {\"weight\": {\"type\": \"integer\", \"minimum\": 1}, \"type\": {\"type\": \"string\", \"enum\": [\"DeleteParticle\"]}, \"op_prefactor\": {\"tyoe\": \"boolean\"}, \"species\": {\"type\": \"array\", \"minimumItems\": 1, \"items\": {\"type\": \"string\"}}, \"seed\": {\"type\": \"integer\", \"minimum\": 0}}, \"required\": [\"type\", \"species\"]}";
	std::string SAPHRON::JsonSchema::InsertParticleMove = "{\"type\": \"object\", \"additionalProperties\": false, \"properties\": {\"weight\": {\"type\": \"integer\", \"minimum\": 1}, \"stash_count\": {\"type\": \"integer\", \"minimum\": 1}, \"op_prefactor\": {\"tyoe\": \"boolean\"}, \"species\": {\"type\": \"array\", \"minimumItems\": 1, \"items\": {\"type\": \"string\"}}, \"type\": {\"type\": \"string\", \"enum\": [\"InsertParticle\"]}, \"seed\": {\"type\": \"integer\", \"minimum\": 0}}, \"required\": [\"type\", \"stash_count\", \"species\"]}";
	std::string SAPHRON::JsonSchema::VolumeSwapMove = "{\"type\": \"object\", \"additionalProperties\": false, \"properties\": {\"weight\": {\"type\": \"integer\", \"minimum\": 1}, \"type\": {\"type\": \"string\", \"enum\": [\"VolumeSwap\"]}, \"dv\": {\"type\": \"number\", \"minimum\": 0}, \"seed\": {\"type\": \"integer\", \"minimum\": 0}}, \"required\": [\"type\", \"dv\"]}";
	std::string SAPHRON::JsonSchema::RotateMove = "{\"type\": \"object\", \"additionalProperties\": false, \"properties\": {\"maxangle\": {\"type\": \"number\", \"minimum\": 0, \"maximum\": 6.283185307179586, \"exclusiveMinimum\": true}, \"type\": {\"type\": \"string\", \"enum\": [\"Rotate\"]}, \"weight\": {\"type\": \"integer\", \"minimum\": 1}, \"seed\": {\"type\": \"integer\", \"minimum\": 0}}, \"required\": [\"type\", \"maxangle\"]}";
	std::string SAPHRON::JsonSchema::TranslateMove = "{\"type\": \"object\", \"additionalProperties\": false, \"properties\": {\"dx\": {\"type\": \"number\", \"minimum\": 0}, \"type\": {\"type\": \"string\", \"enum\": [\"Translate\"]}, \"weight\": {\"type\": \"integer\", \"minimum\": 1}, \"seed\": {\"type\": \"integer\", \"minimum\": 0}}, \"required\": [\"type\", \"dx\"]}";
	std::string SAPHRON::JsonSchema::DirectorRotateMove = "{\"type\": \"object\", \"additionalProperties\": false, \"properties\": {\"weight\": {\"type\": \"integer\", \"minimum\": 1}, \"type\": {\"type\": \"string\", \"enum\": [\"DirectorRotate\"]}, \"seed\": {\"type\": \"integer\", \"minimum\": 0}}, \"required\": [\"type\"]}";
	std::string SAPHRON::JsonSchema::SpeciesSwapMove = "{\"type\": \"object\", \"additionalProperties\": false, \"properties\": {\"weight\": {\"type\": \"integer\", \"minimum\": 1}, \"type\": {\"type\": \"string\", \"enum\": [\"SpeciesSwap\"]}, \"seed\": {\"type\": \"integer\", \"minimum\": 0}}, \"required\": [\"type\"]}";
	std::string SAPHRON::JsonSchema::ParticleSwapMove = "{\"type\": \"object\", \"additionalProperties\": false, \"properties\": {\"weight\": {\"type\": \"integer\", \"minimum\": 1}, \"type\": {\"type\": \"string\", \"enum\": [\"ParticleSwap\"]}, \"seed\": {\"type\": \"integer\", \"minimum\": 0}}, \"required\": [\"type\"]}";
	std::string SAPHRON::JsonSchema::Moves = "{\"type\": \"array\"}";
	std::string SAPHRON::JsonSchema::RandomIdentityMove = "{\"type\": \"object\", \"additionalProperties\": false, \"properties\": {\"weight\": {\"type\": \"integer\", \"minimum\": 1}, \"type\": {\"type\": \"string\", \"enum\": [\"RandomIdentity\"]}, \"identities\": {\"type\": \"array\", \"uniqueItems\": true, \"minIems\": 1, \"items\": {\"type\": \"string\"}}, \"seed\": {\"type\": \"integer\", \"minimum\": 0}}, \"required\": [\"type\", \"identities\"]}";
	std::string SAPHRON::JsonSchema::FlipSpinMove = "{\"type\": \"object\", \"additionalProperties\": false, \"properties\": {\"weight\": {\"type\": \"integer\", \"minimum\": 1}, \"type\": {\"type\": \"string\", \"enum\": [\"FlipSpin\"]}, \"seed\": {\"type\": \"integer\", \"minimum\": 0}}, \"required\": [\"type\"]}";
	std::string SAPHRON::JsonSchema::P2SAConnectivity = "{\"type\": \"object\", \"additionalProperties\": false, \"properties\": {\"type\": {\"type\": \"string\", \"enum\": [\"P2SA\"]}, \"coefficient\": {\"type\": \"number\"}, \"selector\": {}, \"director\": {\"additionalItems\": false, \"type\": \"array\", \"maxItems\": 3, \"minItems\": 3, \"items\": {\"type\": \"number\"}}}, \"required\": [\"type\", \"coefficient\", \"director\", \"selector\"]}";
	std::string SAPHRON::JsonSchema::Connectivities = "{\"type\": \"array\", \"items\": {\"oneOf\": [{\"type\": \"object\", \"additionalProperties\": false, \"properties\": {\"type\": {\"type\": \"string\", \"enum\": [\"P2SA\"]}, \"coefficient\": {\"type\": \"number\"}, \"selector\": {}, \"director\": {\"additionalItems\": false, \"type\": \"array\", \"maxItems\": 3, \"minItems\": 3, \"items\": {\"type\": \"number\"}}}, \"required\": [\"type\", \"coefficient\", \"director\", \"selector\"]}]}}";
	
}