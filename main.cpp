#include <iostream>
#include <string>
#include <vector>
#include "element.h"
#include "matrix.h"


int main(int argc, char const *argv[]) {
  Matrix<int, -1> matrix;

auto a = matrix[100][100];
std::cout<<a;

  return 0;
}
