#include "quality.hpp"

QualityChecker::QualityChecker(OptionParser* option_quality) :
  _compute_quality(option_quality->Get_mesh_quality())
{}

double QualityChecker::check(const std::string& file_name))
{
  auto readerQ = vtkSmartPointer<vtkXMLUnstructuredGridReader>::New();
  readerQ->SetFileName(file_name);

  auto qualityFilter = vtkSmartPointer<vtkMeshQuality>::New();
  qualityFilter->SetInputData(readerQ);
  qualityFilter->SetTriangleQualityMeasureToArea();
  qualityFilter->Update();

  vtkDataSet* qualityMesh = qualityFilter->GetOutput();
  auto qualityArray =
    dynamic_cast<vtkDoubleArray*>(qualityMesh->GetCellData()->GetArray("Quality"));
  return qualityArray->GetNumberOfTuples();
}

//MeshQuality
//setTriangle
//Update
