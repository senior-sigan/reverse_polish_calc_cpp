#include "double_node.hpp"
#include <iostream>

void DoubleNode::Act(std::stack<double> &s) const {
  s.push(value_);
}
DoubleNode::~DoubleNode() {
  std::cout << "~DoubleNode" << std::endl;
}
