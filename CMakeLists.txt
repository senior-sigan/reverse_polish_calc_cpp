cmake_minimum_required(VERSION 3.15)
project(reverse_polish_calc)

set(CMAKE_CXX_STANDARD 17)

add_executable(reverse_polish_calc main.cpp calc.cpp calc.hpp tokenizer.cpp tokenizer.hpp i_node.hpp double_node.cpp double_node.hpp operator_node.cpp operator_node.hpp parser.cpp parser.hpp utils.hpp utils.hpp utils.cpp i_operation.hpp add_op.cpp add_op.hpp mul_op.cpp mul_op.hpp div_op.cpp div_op.hpp sub_op.cpp sub_op.hpp)