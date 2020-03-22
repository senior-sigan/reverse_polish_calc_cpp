#include "div_op.hpp"

#include <iostream>

std::string DivOp::GetName() const {
  return "/";
}
double DivOp::Apply(const std::vector<double> &args) const {
  // TODO: check zero-div. Exception?
  return args[1] / args[0];
}
unsigned int DivOp::GetArity() const {
  return 2;
}
DivOp::~DivOp() {
  std::cout << "~DivOp" << std::endl;
}
