#include "quality.hpp"

QualityChecker::QualityChecker(OptionParser* option_quality) :
  _compute_quality(option_quality->Get_mesh_quality())
{}


//MeshQuality
//satTriangle
//Update
