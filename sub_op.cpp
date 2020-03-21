#include "sub_op.hpp"
std::string SubOp::GetName() const { return "-"; }
double SubOp::Apply(const std::vector<double> &args) const {
  return args[1] - args[0];
}
unsigned int SubOp::GetArity() const { return 2; }
