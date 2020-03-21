#include "operator_node.hpp"
#include <iostream>

void OperatorNode::Act(std::stack<double> &s) const {
  std::vector<double> args{};
  for (int i = 0; i < operation_->GetArity(); i++) {
    // TODO: check stack. If it's empty - throw exception.
    args.push_back(s.top());
    s.pop();
  }
  auto res = operation_->Apply(args);
  s.push(res);
}

OperatorNode::OperatorNode(IOperation *operation) : operation_(operation) {}
OperatorNode::~OperatorNode() {
  std::cout << "~OperatorNode" << std::endl;
}
