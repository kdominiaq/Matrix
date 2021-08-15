# Matrix

Matrix class implementation with template base, which allows using float and double variable types. Also, the class provides a mathematic multiplication operator $$"\cdot"$$.
## Main goal
Matrix class has a static function: "compute_grad" to compute partial derivatives of matrices multiplication operation in regard to the first input of matrix multiplication and in regard to the second argument of Matrix multiplication e.g. Z = X* Y and goal is to compute dZ/dX and dZ/dY .

### Implementation of the static function: "compute_grad"
Well, simply speaking, it's just an derivative matrix with respect to matrix.
#### Example Matrixes with value:

$$A_{i\times j} = \begin{bmatrix}
a_{1\times1} & \cdots & a_{1 \times j} \\
\vdots & \ddots& \vdots  \\
a_{i \times 1} & \cdots & a_{i \times j} 
\end{bmatrix}$$


$$B_{j \times k} = \begin{bmatrix}
b_{1\times1} & \cdots & b_{1 \times k} \\
\vdots & \ddots& \vdots  \\
b_{j \times 1} & \cdots & b_{j \times k} 
\end{bmatrix}$$


$$Z_{i \times k} = A_{i\times j} \cdot B_{j \times k}$$

#### The "compute_grad" implementation is based on an appropriate matrix multiplication:

$$\frac{\delta Z_{i \times k}}{\delta A_{i\times j}}=\begin{bmatrix}
\begin{bmatrix}
1 & \cdots & 0 \\
\vdots & \ddots& \vdots  \\
0 & \cdots &0 
\end{bmatrix} \cdot\begin{bmatrix}
b_{1\times1} & \cdots & b_{1 \times k} \\
\vdots & \ddots& \vdots  \\
b_{j \times 1} & \cdots & b_{j \times k} 
\end{bmatrix} & \cdots & \begin{bmatrix}
0 & \cdots & 1 \\
\vdots & \ddots& \vdots  \\
0 & \cdots &0 
\end{bmatrix} \cdot \begin{bmatrix}
b_{1\times1} & \cdots & b_{1 \times k} \\
\vdots & \ddots& \vdots  \\
b_{j \times 1} & \cdots & b_{j \times k} 
\end{bmatrix} \\
\vdots & \ddots& \vdots  \\
\begin{bmatrix}
0 & \cdots & 0 \\
\vdots & \ddots& \vdots  \\
1 & \cdots &0 
\end{bmatrix} \cdot \begin{bmatrix}
b_{1\times1} & \cdots & b_{1 \times k} \\
\vdots & \ddots& \vdots  \\
b_{j \times 1} & \cdots & b_{j \times k} 
\end{bmatrix}& \cdots & \begin{bmatrix}
0 & \cdots & 0 \\
\vdots & \ddots& \vdots  \\
0 & \cdots &1 
\end{bmatrix} \cdot \begin{bmatrix}
b_{1\times1} & \cdots & b_{1 \times k} \\
\vdots & \ddots& \vdots  \\
b_{j \times 1} & \cdots & b_{j \times k} 
\end{bmatrix}
\end{bmatrix}$$


$$\frac{\delta Z_{i \times k}}{\delta A_{i\times j}}=\begin{bmatrix}
\begin{matrix}
b_{1\times1} & \cdots & b_{1 \times k} \\
\vdots & \ddots& \vdots  \\
0 & \cdots & 0
\end{matrix} & \cdots & \begin{matrix}
b_{j\times1} & \cdots & b_{j \times k} \\
\vdots & \ddots& \vdots  \\
0 & \cdots & 0
\end{matrix} \\
\vdots & \ddots& \vdots  \\
\begin{matrix}
0 & \cdots & 0 \\
\vdots & \ddots& \vdots  \\
b_{1\times1}& \cdots & b_{1 \times k}
\end{matrix} & \cdots & \begin{matrix}
0 & \cdots & 0 \\
\vdots & \ddots& \vdots  \\
b_{j\times1}& \cdots & b_{j \times k}
\end{matrix}
\end{bmatrix}$$

$$\frac{\delta Z_{i \times k}}{\delta B_{j\times k}}=\begin{bmatrix}
\begin{bmatrix}
a_{1\times1} & \cdots & a_{1 \times j} \\
\vdots & \ddots& \vdots  \\
a_{i \times 1} & \cdots & a_{i \times j} 
\end{bmatrix} \cdot \begin{bmatrix}
1 & \cdots & 0 \\
\vdots & \ddots& \vdots  \\
0 & \cdots &0 
\end{bmatrix}& \cdots & \begin{bmatrix}
a_{1\times1} & \cdots & a_{1 \times j} \\
\vdots & \ddots& \vdots  \\
a_{i \times 1} & \cdots & a_{i \times j} 
\end{bmatrix} \cdot \begin{bmatrix}
0 & \cdots & 1 \\
\vdots & \ddots& \vdots  \\
0 & \cdots &0 
\end{bmatrix} \\
\vdots & \ddots& \vdots  \\
\begin{bmatrix}
a_{1\times1} & \cdots & a_{1 \times j} \\
\vdots & \ddots& \vdots  \\
a_{i \times 1} & \cdots & a_{i \times j} 
\end{bmatrix} \cdot \begin{bmatrix}
0 & \cdots & 0 \\
\vdots & \ddots& \vdots  \\
1 & \cdots &0 
\end{bmatrix}& \cdots & \begin{bmatrix}
a_{1\times1} & \cdots & a_{1 \times j} \\
\vdots & \ddots& \vdots  \\
a_{i \times 1} & \cdots & a_{i \times j} 
\end{bmatrix} \cdot \begin{bmatrix}
0 & \cdots & 0 \\
\vdots & \ddots& \vdots  \\
0 & \cdots &1
\end{bmatrix}
\end{bmatrix}$$


$$\frac{\delta Z_{i \times k}}{\delta B_{j\times k}}=\begin{bmatrix}
\begin{matrix}
a_{1\times1}& \cdots & 0 \\
\vdots & \ddots& \vdots  \\
a_{i \times 1} & \cdots & 0
\end{matrix} & \cdots & \begin{matrix}
0 & \cdots & a_{1\times1}\\
\vdots & \ddots& \vdots  \\
0 & \cdots & a_{i \times1}
\end{matrix} \\
\vdots & \ddots& \vdots  \\
\begin{matrix}
a_{1 \times j} & \cdots & 0 \\
\vdots & \ddots& \vdots  \\
a_{1 \times j}& \cdots & 0
\end{matrix} & \cdots & \begin{matrix}
0 & \cdots & a_{1 \times j} \\
\vdots & \ddots& \vdots  \\
0& \cdots & a_{i \times j}
\end{matrix}
\end{bmatrix}$$

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
