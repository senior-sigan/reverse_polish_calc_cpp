#include "mul_op.hpp"

#include <iostream>
std::string MulOp::GetName() const {
  return "*";
}
double MulOp::Apply(const std::vector<double> &args) const {
  return args[0] * args[1];
}
unsigned int MulOp::GetArity() const {
  return 2;
}
MulOp::~MulOp() {
  std::cout << "~MulOp" << std::endl;
}
