#pragma once

enum TransformType
{
  // TODO
};

struct Params
{
  virtual ~Params(void) = default;
  <std::string> = name;

};

struct MergeParams : public Params
{
  std::vector<std::string> meshes;
  bool merge_nodes;
};

struct TranslationParams : public Params
{
  double X;
  double Y;
  double Z;
};

class Transform
{
public:
  Transform(void) {}
  ~Transform(void) {}

  // TODO
};
