#include "parser.hpp"

#include "double_node.hpp"
#include "iostream"
#include "operator_node.hpp"
#include "utils.hpp"

using namespace std;

vector<INode *> Parser::parse(const vector<string> &tokens) const {
  vector<INode *> nodes{};

  for (const auto& token: tokens) {
    if (IsNumber(token)) {
      auto n = new DoubleNode(ParseDouble(token));
      nodes.push_back(n);
      continue;
    }
    if (IsOperator(token)) {
      auto n = new OperatorNode(operations_.at(token));
      nodes.push_back(n);
      continue;
    }

    std::cerr << "[ERROR] unexpected token " << token << std::endl;
    exit(-1); // TODO: throw exception
  }

  return nodes;
}
void Parser::RegisterOp(IOperation* op) {
  operations_[op->GetName()] = op;
}
bool Parser::IsOperator(const std::string& token) const {
  return operations_.count(token) == 1;
}
Parser::~Parser() {
  cout << "~Parser" << endl;
  for (const auto& kv: operations_) {
    delete kv.second;
  }
}
