#pragma once

#include "vtkSmartPointer.h"
#include "vtkDataSet.h"

class Viewer
{
public:
  Viewer(void) {}
  ~Viewer(void) {}

  void view (vtkSmartPointer<vtkDataSet>);
};
