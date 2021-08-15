#include <iostream>
#include "include/Matrix.h"


int main() {

    Matrix<double> a(2,7);
    Matrix<double> b(7, 2);
    Matrix<double> c;

    a.init_value_by_user();
    b.init_value();


    c = Matrix<double>::compute_grad(a,b);
    c.print();

    return 0;
}
