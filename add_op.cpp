#include "add_op.hpp"
#include <iostream>

std::string AddOp::GetName() const {
  return "+";
}
double AddOp::Apply(const std::vector<double> &args) const {
  return args.at(0) + args.at(1);
}
unsigned int AddOp::GetArity() const {
  return 2;
}
AddOp::~AddOp() {
  std::cout << "~AddOp" << std::endl;
}
