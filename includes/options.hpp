#pragma once

#include <memory>

#include "cpptoml.h"

class OptionsParser
{
public:
  OptionsParser(const std::string&);
  ~OptionsParser(void) {}

  // TODO: modifier le type de retour en cohérence
  // avec la structure de données renvoyée.

  void parse();

//Fonctions pour récupérer type de transformation
  std::string Get_transformation() const { return _matransformation;}

// Fonction pour récupérer nom de l'output
  std::string Get_name_output() const { return _result_file_name;}

// Fonctions pour la fusion de maillages
  bool Get_merge_nodes() const { return _merge_nodes;}
  std::vector<std::string> Get_merge_meshes() const { return _meshes;}

// Fonctions pour translation
  std::vector<double> Get_translate_coords() const { return _coords ;}
  std::string Get_translate_mesh() const { return _mesh;}

// Fonctions pour la qualité du maillage
  bool Get_mesh_quality() const { return _compute_quality;}

private:
  std::string m_file_name;
  std::shared_ptr<cpptoml::table> m_data;

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

// Params Quality
  bool _compute_quality;

};
