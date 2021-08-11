#include <iostream>
#include "include/Matrix.h"


int main() {

    srand(time(NULL));


    Matrix<double> a(3,2);
    Matrix<double> b(2, 3);
    a.rand();
    a.print();
    b.rand();
    b.print();
    Matrix<double> c(2, 2);
    c =a*b;

    c.print();

    c = Matrix<double>::compute_grad(a,b);

    c.print();

    return 0;
}
