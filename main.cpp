#include <iostream>
#include "include/Matrix.h"


int main() {

    srand(time(NULL));
    Matrix<double> a(2,2);
    Matrix<double> b(2, 2);
    a.rand();
    a.print();
    b.rand();
    b.print();
    Matrix<double> c(2, 2);

    c = a * b;
    c.input();
    c.print();



    return 0;
}
