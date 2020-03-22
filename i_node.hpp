#pragma once

#include <stack>

class INode {
 public:
  virtual void Act(std::stack<double>& s) const = 0;
  virtual ~INode() = default;
};
