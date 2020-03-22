#pragma once

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "i_node.hpp"
#include "i_operation.hpp"

class Parser {
  std::map<std::string, std::unique_ptr<IOperation>> operations_{};

  bool IsOperator(const std::string &token) const;

 public:
  std::vector<std::unique_ptr<INode>> parse(const std::vector<std::string> &tokens) const;

  template<typename TOperation, typename... Args>
  void Register(Args &&... args) {
    auto op = new TOperation(std::forward<Args>(args)...);
    operations_[op->GetName()] = std::unique_ptr<IOperation>(op);
  }
};
