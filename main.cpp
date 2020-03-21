#include <iostream>

#include "add_op.hpp"
#include "calc.hpp"
#include "div_op.hpp"
#include "mul_op.hpp"
#include "sub_op.hpp"
#include "tokenizer.hpp"
#include "utils.hpp"
#include <cmath>

Parser *DefaultParser() {
  auto p = new Parser();
  p->RegisterOp(new AddOp());
  p->RegisterOp(new MulOp());
  p->RegisterOp(new SubOp());
  p->RegisterOp(new DivOp());
  return p;
}

Calc *DefaultCalc() {
  auto t = new Tokenizer(' ');
  return new Calc(t, DefaultParser());
}

void AssertEqD(double a, double b, int line) {
  if (std::abs(a - b) < 0.0001) {
    // OK
  } else {
    std::cout << line << "] FAIL " << a << " != " << b << std::endl;
    exit(-1);
  }
}

void AssertTrue(bool b) {
  if (!b) {
    std::cout << "FAIL expected true but got false";
    exit(-1);
  }
}

void test_0() {
  auto calc = DefaultCalc();
  AssertEqD(calc->eval("0"), 0.0, __LINE__);
  delete calc;
}

void test_1() {
  auto calc = DefaultCalc();
  AssertEqD(calc->eval("1 2 3 42"), 42.0, __LINE__);
  delete calc;
}

void test_2() {
  auto calc = DefaultCalc();
  AssertEqD(calc->eval("1 2 +"), 3, __LINE__);
  delete calc;
}

void test_arithmetic() {
  auto calc = DefaultCalc();
  AssertEqD(calc->eval("5 1 2 + 4 * + 3 -"), 14.0, __LINE__);
  // 15 7 1 1 + - / 3 * 2 1 1 + + 1
  AssertEqD(calc->eval("15 7 1 1 + - / 3 * 2 1 1 + + -"), 5.0, __LINE__);
  delete calc;
}

void test_tokenizer() {
  Tokenizer t(' ');
  auto res = t.tokenize("1 2 3 4 5");
  std::vector<std::string> expected{"1", "2", "3", "4", "5"};
  for (int i = 0; i < expected.size(); i++) {
    if (res[i] != expected[i]) {
      std::cout << "FAIL at i=" << i << " res[i]='" << res[i] << "' exp[i]"
                << expected[i] << std::endl;
      exit(-1);
    }
  }
}

void test_number_parser() {
  AssertTrue(IsNumber("42.13"));
  AssertTrue(IsNumber("-1"));
  AssertTrue(IsNumber("+42"));

  AssertTrue(!IsNumber("+"));
  AssertTrue(!IsNumber("-"));
  AssertTrue(!IsNumber("a42"));

  // TODO: these lines should fail, BUT std::stod is not so strict as we wanted
  AssertTrue(IsNumber("42b"));
  AssertTrue(IsNumber("42.a"));
}

int main() {
  test_number_parser();
  test_tokenizer();
  test_0();
  test_1();
  test_2();
  test_arithmetic();

  std::cout << "OK" << std::endl;
  return 0;
}
