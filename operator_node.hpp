#pragma once

#include "i_node.hpp"
#include "i_operation.hpp"

class OperatorNode: public INode {
  IOperation* operation_;
public:
  explicit OperatorNode(IOperation* operation);
  void Act(std::stack<double> &s) const override;
  virtual ~OperatorNode();
};
