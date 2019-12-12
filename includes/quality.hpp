#pragma once

// Struct


class QualityChecker
{
public:
  QualityChecker(std::shared_ptr<OptionsParser> option_quality);
  //~QualityChecker(void) {}
  double check();


private:
// Params Quality
  bool _compute_quality;

};
