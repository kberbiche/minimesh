#include <memory>

#include "viewer.hpp"

Viewer::Viewer()
//const std::string& file_name
//: m_file_name(file_name)
{

}

void Viewer::view()
{
  //read all the data from the file
  auto reader = vtkSmartPointer<vtkXMLUnstructuredGridReader>::New();
  reader->SetFileName(file_name.c_str());
  reader->Update();

  auto colors = vtkSmartPointer<vtkNamedColors>::New();

  //Create a mapper and actor
  auto mapper = vtkSmartPointer<vtkDataSetMapper>::New();
  mapper->SetInputConnection(reader->GetOutputPort());

  auto actor = vtkSmartPointer<vtkActor>::New();
  actor->SetMapper(mapper);

  //Create a renderer, render window, and interactor
  auto renderer = vtkSmartPointer<vtkRenderer>::New();
  auto renderWindow = vtkSmartPointer<vtkRenderWindow>::New();
  renderWindow->AddRenderer(renderer);

  auto renderWindowInteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
  renderWindowInteractor->SetRenderWindow(renderWindow);

  //Add the actor to the scene
  renderer->AddActor(actor);
  //renderer->SetBackground(colors->GetColor3d("Wheat").GetData());

  //Render and interact
  renderWindow->SetSize(640, 480);

  renderWindow->Render();
  renderWindowInteractor->Start();

  return EXIT_SUCCESS;
}
