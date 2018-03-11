#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cassert>
#include "element.h"
#include "matrix.h"


int main(int argc, char const *argv[]) {

Matrix<int, -1> matrix;
assert(matrix.size() == 0);
auto a = matrix[0][0];
assert(a == -1);
assert(matrix.size() == 0);
matrix[100][100] = 314;
assert(matrix[100][100] == 314);
assert(matrix.size() == 1);

for(auto i = 0; i<10;i++){
    matrix[i][i] = 88;
}


  return 0;
}
