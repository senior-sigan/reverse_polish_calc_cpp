#pragma once

#include "i_node.hpp"

class DoubleNode : public INode {
  const double value_;

 public:
  explicit DoubleNode(double value) : value_(value) {}
  void Act(std::stack<double> &s) const override;
  virtual ~DoubleNode();
};
