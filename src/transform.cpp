#include <memory>

#include "transform.hpp"

Transform::Transform(OptionParser* option_transformation)
  : _result_file_name(option_transformation->Get_name_output())
  _matransformation(option_transformation->Get_transformation())

{
  if(_matransformation == "merge"){
    _merge_nodes = option_transformation->Get_merge_nodes();
    _meshes = option_transformation->Get_merge_meshes();
  }
  else if (_matransformation == "translate"){
    _mesh = option_transformation->Get_translate_mesh();
    _coords = option_transformation->Get_translate_coords();
    _X = _coords[0];
    _Y = _coords[1];
    _Z = _coords[2];
  }
}
//Transform::Transform(const std::string& file_name)
//  : m_file_name(file_name)
//{
//}


void Transform::merge()
{
  auto reader1 = vtkSmartPointer<vtkXMLUnstructuredGridReader>::New();
  reader1->SetFileName(_meshes[0]);

  auto reader2 = vtkSmartPointer<vtkXMLUnstructuredGridReader>::New();
  reader2->SetFileName(_meshes[1]);

  auto appendFilter = vtkSmartPointer<vtkAppendFilter>::New();
  appendFilter->AddInputData(reader1);
  appendFilter->Update();
  appendFilter->AddInputData(reader2);
  appendFilter->Update();

  auto unstructuredGrid = vtkSmartPointer<vtkUnstructuredGrid>::New();
  unstructuredGrid->ShallowCopy(appendFilter->GetOutput());

  auto writerM = vtkSmartPointer<vtkXMLUnstructuredGridWriter>::New();
  writerM->SetFileName(_result_file_name());
  writerM->SetInputData(unstructuredGrid);
  writerM->Write();

}


void Transform::translate()
{
  auto reader0 = vtkSmartPointer<vtkXMLUnstructuredGridReader>::New();
  reader0->SetFileName(_meshes);

  auto translation = vtkSmartPointer<vtkTransform>::New();
  translation -> Translate(_X, _Y, _Z);

  auto translationFilter = vtkSmartPointer<vtkTransformFilter>::New();
  translationFilter -> SetInputConnection(reader0);
  translationFilter -> SetTransform(translation);
  translationFilter -> Update();

  auto unstructuredGrid = vtkSmartPointer<vtkUnstructuredGrid>::New();
  unstructuredGrid->ShallowCopy(translationFilter->GetOutput());

  auto writerT = vtkSmartPointer<vtkXMLUnstructuredGridWriter>::New();
  writerT->SetFileName(_result_file_name());
  writerT->SetInputData(unstructuredGrid);
  writerT->Write();

}
