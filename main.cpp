#include <iostream>
#include "include/Matrix.h"


int main() {

    srand(time(NULL));
    Matrix<int> a(2,2);
    Matrix<int> b(2, 2);
    a.rand();
    a.print();
    b.rand();
    b.print();
    Matrix<int> c(2, 2);

    c = a * b;

    c.print();



    return 0;
}
