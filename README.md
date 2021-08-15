# Matrix

Matrix class implementation with template base, which allows using float and double variable types. Also, the class provides a mathematic multiplication operator $$"\cdot"$$.
## Main goal
Matrix class has a static function: "compute_grad" to compute partial derivatives of matrices multiplication operation in regard to the first input of matrix multiplication and in regard to the second argument of Matrix multiplication e.g. Z = X* Y and goal is to compute "*" .

### Implementation of the static function: "compute_grad"
Well, simply speaking, it's just an derivative matrix with respect to matrix.
#### Example Matrixes with value:

![](https://i.ibb.co/F5qttK3/matrix-example.png)


#### The "compute_grad" implementation is based on an appropriate matrix multiplication:

![](https://i.ibb.co/Zzz3qzF/matrix.png)

## Steps for running code
#### Prepare
```bash
$ git clone https://github.com/kdominiaq/Matrix.git
```
#### Setup
```bash
$ cmake CMakeLists.txt -B build/
$ cd build/
$ make
```
#### Run
```bash
$ ./exe
```
## Layout conventions
Denominator-layout notation
