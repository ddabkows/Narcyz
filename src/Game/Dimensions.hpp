/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Struct of dimensions
*/


#ifndef _DIMENSIONS_H_
#define _DIMENSIONS_H_


struct Dimensions {
  Dimensions(int x_to_be, int y_to_be) : x(x_to_be), y(y_to_be) {}
  int x;
  int y;
};
#endif 