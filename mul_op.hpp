#pragma once

#include "i_operation.hpp"
class MulOp: public IOperation {
public:
  std::string GetName() const override;
  double Apply(const std::vector<double> &args) const override;
  unsigned int GetArity() const override;
  virtual ~MulOp();
};
