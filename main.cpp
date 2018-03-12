#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cassert>
#include <tuple>
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

for(auto c : matrix){
    int x;
    int y;
    int v;
    std::tie(x, y, v) = c;
    std::cout << x << y << v << std::endl;
}


  return 0;
}
