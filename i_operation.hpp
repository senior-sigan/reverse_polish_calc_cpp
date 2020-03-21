#pragma once

#include <vector>
#include <string>

class IOperation {
public:
  virtual std::string GetName() const = 0;
  virtual double Apply(const std::vector<double>& args) const = 0;
  virtual unsigned int GetArity() const = 0;
  virtual ~IOperation() = default;
};
