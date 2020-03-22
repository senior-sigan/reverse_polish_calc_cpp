#pragma once

#include <string>
#include <vector>

class IOperation {
 public:
  virtual std::string GetName() const = 0;
  virtual double Apply(const std::vector<double>& args) const = 0;
  virtual unsigned int GetArity() const = 0;
  virtual ~IOperation() = default;
};
