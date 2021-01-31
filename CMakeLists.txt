cmake_minimum_required(VERSION 3.16)


set(CMAKE_CXX_STANDARD 17)
add_subdirectory(tests)

project(ParaCL)

add_executable(ParaCL main.cpp  Nodes/Node.cpp  Nodes/driver.cpp  Build/lex.yy.cc Build/numgrammar.tab.cc Nodes/MyLexer.cpp)