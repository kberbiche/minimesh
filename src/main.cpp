// Compilation
// cmake3 .. -DCMAKE_STANDARD=11
// make

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <tuple>

#include <vtkXMLUnstructuredGridWriter.h>


#include "options.hpp"
#include "transform.hpp"
#include "quality.hpp"
#include "viewer.hpp"

void print_usage()
{
  std::cout << "A VTK-focused unstructured mesh manipulation mini-app\n";
  std::cout << "Usage:\n";
  std::cout << "  minimesh [OPTION...]\n";
  std::cout << "\n";
  std::cout << "  -v, --view Mesh file            View a mesh\n";
  std::cout << "  -t, --transform Transform file  Transform (merge, translate) a mesh\n";
  std::cout << "  -h, --help                      Print help\n";
}

int main(int argc, char **argv)
{
  std::string command;
  std::string file_name;

  if (argc > 1) {
    command = argv[1];
  }

// HELP
  if ((argc <= 1) || command == "-h" || command == "--help") {
    print_usage();
    return EXIT_SUCCESS;
  }
// VIEWER
  if (command == "-v" || command == "--view") {
    if (argc < 3) {
      std::cerr << "Error: missing file\n";
      print_usage();
      return EXIT_FAILURE;
    }
    file_name = argv[2];

    //auto monviewer = new Viewer(file_name.c_str());
    auto monviewer = new Viewer();
    monviewer -> view();

// TRANSFORMATION MAILLAGE
  } else if (command == "-t" || command == "--transform") {
    if (argc < 3) {
      std::cerr << "Error: missing file\n";
      print_usage();
      return EXIT_FAILURE;
    }
    file_name = argv[2];

    //auto op = new OptionsParser(file_name);
    //*auto params = */op->parse();

    auto op = std::make_shared<OptionsParser>(file_name);
    op->parse();

    auto matransfo = new Transform(op);

    if(file_name == "merge.toml"){
      matransfo -> merge();
      
    } else if (file_name == "translate.toml"){
      matransfo -> translate();
    }
    // Lecture fichier parametre pour choix de la TRANSFORMATION
    // Boucle if
    // creation/appel objet transform

    // auto writer = vtkSmartPointer<vtkXMLUnstructuredGridWriter>::New();
    // writer->SetFileName(filename_output.c_str());
    // writer->SetInputData(unstructuredGrid);
    // writer->Write();



  } else {
    std::cerr << "Error: unknown command\n";
    print_usage();
    return EXIT_FAILURE;
  }
  // delete monviewer;
  // delete matransfo;
  // delete op;

  return EXIT_SUCCESS;
}
