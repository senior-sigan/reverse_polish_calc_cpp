#pragma once

#include "i_node.hpp"
#include "i_operation.hpp"
#include <map>
#include <string>
#include <vector>

class Parser {
  std::map<std::string, IOperation *> operations_{};

  bool IsOperator(const std::string& token) const;
public:
  std::vector<INode *> parse(const std::vector<std::string> &tokens) const;
  void RegisterOp(IOperation* op);

  virtual ~Parser();
};
