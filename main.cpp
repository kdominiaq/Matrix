#include <iostream>
#include "include/Matrix.h"


int main() {

    Matrix<double> a(3, 6);
    Matrix<double> b(6, 3);
    Matrix<double> z;

    a.init_value();
    b.init_value();

    std::cout << "Matrix A" << std::endl;
    a.print();
    std::cout << "Matrix B" << std::endl;
    b.print();

    std::cout << "The result of matrix multiplication: A*B" << std::endl;
    z = a * b;
    z.print();

    std::cout << "The result of derivative matrix with respect to matrix: dZ/dA,  Z = A*B" << std::endl;
    z = Matrix<double>::compute_grad(a, b, true);
    z.print();

    return 0;
}
