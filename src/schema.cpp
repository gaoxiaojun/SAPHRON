#include "schema.h"

namespace SAPHRON
{
	//INSERT_DEF_HERE
	std::string SAPHRON::JsonSchema::ForceFields = "{\"additionalProperties\": false, \"type\": \"object\", \"properties\": {\"electrostatic\": {\"type\": \"array\"}, \"nonbonded\": {\"type\": \"array\"}, \"bonded\": {\"type\": \"array\"}}}";
	std::string SAPHRON::JsonSchema::LebwholLasher = "{\"additionalProperties\": false, \"required\": [\"type\", \"epsilon\", \"gamma\", \"species\"], \"type\": \"object\", \"properties\": {\"gamma\": {\"type\": \"number\"}, \"type\": {\"type\": \"string\", \"enum\": [\"LebwohlLasher\"]}, \"species\": {\"additionalItems\": false, \"type\": \"array\", \"maxItems\": 2, \"items\": {\"type\": \"string\"}, \"minItems\": 2}, \"epsilon\": {\"type\": \"number\"}}}";
	std::string SAPHRON::JsonSchema::LennardJones = "{\"additionalProperties\": false, \"required\": [\"type\", \"sigma\", \"epsilon\", \"rcut\", \"species\"], \"type\": \"object\", \"properties\": {\"species\": {\"additionalItems\": false, \"type\": \"array\", \"maxItems\": 2, \"items\": {\"type\": \"string\"}, \"minItems\": 2}, \"type\": {\"type\": \"string\", \"enum\": [\"LennardJones\"]}, \"sigma\": {\"type\": \"number\", \"minimum\": 0, \"exclusiveMinimum\": true}, \"rcut\": {\"type\": \"number\", \"minimum\": 0, \"exclusiveMinimum\": true}, \"epsilon\": {\"type\": \"number\", \"minimum\": 0}}}";
	std::string SAPHRON::JsonSchema::Worlds = "{\"type\": \"array\", \"minItems\": 1, \"items\": {\"required\": [\"type\", \"dimensions\", \"nlist_cutoff\", \"skin_thickness\"], \"type\": \"object\", \"properties\": {\"nlist_cutoff\": {\"type\": \"number\", \"minimum\": 0, \"exclusiveMinimum\": true}, \"type\": {\"type\": \"string\", \"enum\": [\"Simple\"]}, \"skin_thickness\": {\"type\": \"number\", \"minimum\": 0, \"exclusiveMinimum\": true}, \"seed\": {\"type\": \"integer\", \"minimum\": 0}, \"dimensions\": {\"additionalItems\": false, \"type\": \"array\", \"maxItems\": 3, \"items\": {\"type\": \"number\", \"minimum\": 0}, \"minItems\": 3}}}}";
	std::string SAPHRON::JsonSchema::SimpleWorld = "{\"required\": [\"type\", \"dimensions\", \"nlist_cutoff\", \"skin_thickness\"], \"type\": \"object\", \"properties\": {\"nlist_cutoff\": {\"type\": \"number\", \"minimum\": 0, \"exclusiveMinimum\": true}, \"type\": {\"type\": \"string\", \"enum\": [\"Simple\"]}, \"skin_thickness\": {\"type\": \"number\", \"minimum\": 0, \"exclusiveMinimum\": true}, \"seed\": {\"type\": \"integer\", \"minimum\": 0}, \"dimensions\": {\"additionalItems\": false, \"type\": \"array\", \"maxItems\": 3, \"items\": {\"type\": \"number\", \"minimum\": 0}, \"minItems\": 3}}}";
	std::string SAPHRON::JsonSchema::Particles = "{\"additionalItems\": false, \"type\": \"array\", \"minItems\": 1, \"items\": {\"additionalItems\": false, \"type\": \"array\", \"minItems\": 4, \"items\": [{\"type\": \"integer\", \"minimum\": 1}, {\"type\": \"string\"}, {\"type\": \"string\"}, {\"additionalItems\": false, \"type\": \"array\", \"maxItems\": 3, \"items\": {\"type\": \"number\", \"minimum\": 0}, \"minItems\": 3}, {\"additionalItems\": false, \"type\": \"array\", \"maxItems\": 3, \"items\": {\"type\": \"number\"}, \"minItems\": 3}, {\"type\": \"string\"}]}}";
	std::string SAPHRON::JsonSchema::Site = "{\"additionalItems\": false, \"type\": \"array\", \"minItems\": 4, \"items\": [{\"type\": \"integer\", \"minimum\": 1}, {\"type\": \"string\"}, {\"type\": \"string\"}, {\"additionalItems\": false, \"type\": \"array\", \"maxItems\": 3, \"items\": {\"type\": \"number\", \"minimum\": 0}, \"minItems\": 3}, {\"additionalItems\": false, \"type\": \"array\", \"maxItems\": 3, \"items\": {\"type\": \"number\"}, \"minItems\": 3}, {\"type\": \"string\"}]}";
	std::string SAPHRON::JsonSchema::Components = "{\"patternProperties\": {\"^[A-z][A-z0-9]+$\": {\"additionalProperties\": false, \"required\": [\"count\"], \"type\": \"object\", \"minProperties\": 1, \"properties\": {\"children\": {\"patternProperties\": {\"^[A-z][A-z0-9]+$\": {\"type\": \"object\"}}, \"type\": \"object\"}, \"count\": {\"type\": \"integer\", \"minimum\": 1}}}}, \"type\": \"object\", \"minProperties\": 1, \"additionalProperties\": false}";
	std::string SAPHRON::JsonSchema::Selector = "{}";
	std::string SAPHRON::JsonSchema::Director = "{\"additionalItems\": false, \"type\": \"array\", \"maxItems\": 3, \"items\": {\"type\": \"number\"}, \"minItems\": 3}";
	std::string SAPHRON::JsonSchema::Observer = "{\"oneOf\": [{\"required\": [\"file_prefix\"], \"properties\": {\"file_prefix\": {\"type\": \"string\"}}}], \"type\": \"object\", \"properties\": {\"flags\": {\"type\": \"object\", \"properties\": {\"pressure\": {\"type\": \"integer\", \"minimum\": 0, \"maximum\": 1}, \"world_composition\": {\"type\": \"integer\", \"minimum\": 0, \"maximum\": 1}, \"sweeps\": {\"type\": \"integer\", \"minimum\": 0, \"maximum\": 1}, \"energy\": {\"type\": \"integer\", \"minimum\": 0, \"maximum\": 1}, \"acceptance\": {\"type\": \"integer\", \"minimum\": 0, \"maximum\": 1}, \"world_density\": {\"type\": \"integer\", \"minimum\": 0, \"maximum\": 1}, \"world_count\": {\"type\": \"integer\", \"minimum\": 0, \"maximum\": 1}, \"world_volume\": {\"type\": \"integer\", \"minimum\": 0, \"maximum\": 1}, \"identifier\": {\"type\": \"integer\", \"minimum\": 0, \"maximum\": 1}, \"temperature\": {\"type\": \"integer\", \"minimum\": 0, \"maximum\": 1}}}, \"frequency\": {\"type\": \"integer\", \"minimum\": 1}}}";
	std::string SAPHRON::JsonSchema::CSVObserver = "{\"required\": [\"file_prefix\"], \"properties\": {\"file_prefix\": {\"type\": \"string\"}}}";
	std::string SAPHRON::JsonSchema::TranslateMove = "{\"additionalProperties\": false, \"required\": [\"type\", \"dx\"], \"type\": \"object\", \"properties\": {\"type\": {\"type\": \"string\", \"enum\": [\"Translate\"]}, \"seed\": {\"type\": \"integer\", \"minimum\": 0}, \"dx\": {\"type\": \"number\", \"minimum\": 0}}}";
	std::string SAPHRON::JsonSchema::SphereUnitVectorMove = "{\"additionalProperties\": false, \"required\": [\"type\"], \"type\": \"object\", \"properties\": {\"type\": {\"type\": \"string\", \"enum\": [\"SphereUnitVector\"]}, \"seed\": {\"type\": \"integer\", \"minimum\": 0}}}";
	std::string SAPHRON::JsonSchema::SpeciesSwapMove = "{\"additionalProperties\": false, \"required\": [\"type\"], \"type\": \"object\", \"properties\": {\"type\": {\"type\": \"string\", \"enum\": [\"SpeciesSwap\"]}}}";
	std::string SAPHRON::JsonSchema::ParticleSwapMove = "{\"additionalProperties\": false, \"required\": [\"type\"], \"type\": \"object\", \"properties\": {\"type\": {\"type\": \"string\", \"enum\": [\"ParticleSwap\"]}, \"seed\": {\"type\": \"integer\", \"minimum\": 0}}}";
	std::string SAPHRON::JsonSchema::Moves = "{\"type\": \"array\"}";
	std::string SAPHRON::JsonSchema::IdentityChangeMove = "{\"additionalProperties\": false, \"required\": [\"type\"], \"type\": \"object\", \"properties\": {\"type\": {\"type\": \"string\", \"enum\": [\"IdentityChange\"]}}}";
	std::string SAPHRON::JsonSchema::FlipSpinMove = "{\"additionalProperties\": false, \"required\": [\"type\"], \"type\": \"object\", \"properties\": {\"type\": {\"type\": \"string\", \"enum\": [\"FlipSpin\"]}}}";
	std::string SAPHRON::JsonSchema::GibbsNVTEnsemble = "{\"additionalProperties\": false, \"required\": [\"type\", \"temperature\"], \"type\": \"object\", \"properties\": {\"type\": {\"type\": \"string\", \"enum\": [\"GibbsNVT\"]}, \"sweeps\": {\"type\": \"integer\", \"minimum\": 1}, \"temperature\": {\"type\": \"number\", \"minimum\": 0, \"exclusiveMinimum\": \"true\"}, \"seed\": {\"type\": \"integer\", \"minimum\": 0}}}";
	std::string SAPHRON::JsonSchema::NVTEnsemble = "{\"additionalProperties\": false, \"required\": [\"type\", \"temperature\"], \"type\": \"object\", \"properties\": {\"type\": {\"type\": \"string\", \"enum\": [\"NVT\"]}, \"sweeps\": {\"type\": \"integer\", \"minimum\": 1}, \"temperature\": {\"type\": \"number\", \"minimum\": 0, \"exclusiveMinimum\": \"true\"}, \"seed\": {\"type\": \"integer\", \"minimum\": 0}}}";
	std::string SAPHRON::JsonSchema::Ensembles = "{\"oneOf\": [{\"additionalProperties\": false, \"required\": [\"type\", \"temperature\"], \"type\": \"object\", \"properties\": {\"type\": {\"type\": \"string\", \"enum\": [\"NVT\"]}, \"sweeps\": {\"type\": \"integer\", \"minimum\": 1}, \"temperature\": {\"type\": \"number\", \"minimum\": 0, \"exclusiveMinimum\": \"true\"}, \"seed\": {\"type\": \"integer\", \"minimum\": 0}}}, {\"additionalProperties\": false, \"required\": [\"type\", \"temperature\"], \"type\": \"object\", \"properties\": {\"type\": {\"type\": \"string\", \"enum\": [\"GibbsNVT\"]}, \"sweeps\": {\"type\": \"integer\", \"minimum\": 1}, \"temperature\": {\"type\": \"number\", \"minimum\": 0, \"exclusiveMinimum\": \"true\"}, \"seed\": {\"type\": \"integer\", \"minimum\": 0}}}]}";
	std::string SAPHRON::JsonSchema::P2SAConnectivity = "{\"additionalProperties\": false, \"required\": [\"type\", \"coefficient\", \"director\", \"selector\"], \"type\": \"object\", \"properties\": {\"director\": {\"additionalItems\": false, \"type\": \"array\", \"maxItems\": 3, \"items\": {\"type\": \"number\"}, \"minItems\": 3}, \"type\": {\"type\": \"string\", \"enum\": [\"P2SA\"]}, \"selector\": {}, \"coefficient\": {\"type\": \"number\"}}}";
	std::string SAPHRON::JsonSchema::Connectivities = "{\"type\": \"array\", \"items\": {\"oneOf\": [{\"additionalProperties\": false, \"required\": [\"type\", \"coefficient\", \"director\", \"selector\"], \"type\": \"object\", \"properties\": {\"director\": {\"additionalItems\": false, \"type\": \"array\", \"maxItems\": 3, \"items\": {\"type\": \"number\"}, \"minItems\": 3}, \"type\": {\"type\": \"string\", \"enum\": [\"P2SA\"]}, \"selector\": {}, \"coefficient\": {\"type\": \"number\"}}}]}}";
	
}