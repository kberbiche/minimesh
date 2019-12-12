#pragma once

#include "options.hpp"
// enum TransformType { Merge, Translate };

// struct Params
// {
//   virtual ~Params(void) = default;
//   <std::string> = name;
// };
//
// struct MergeParams : public Params
// {
//   std::vector<std::string> meshes;
//   bool merge_nodes;
// };
//
// struct TranslationParams : public Params
// {
//   double _X;
//   double _Y;
//   double _Z;
// };

class Transform
{
public :

  Transform(std::shared_ptr<OptionsParser> option_transformation);

  //~Transform(OptionParser* option_transformation) {}

  void merge();
  void translate();

private :
// Type de TRANSFORMATION
  std::string _matransformation;

// Nom fichier output
  std::string _result_file_name;

// Params Merge
  bool _merge_nodes;
  std::vector<std::string> _meshes ;

// Params Translation
  std::vector<double> _coords;
  std::string _mesh;

};
