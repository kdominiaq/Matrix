//
// Created by kdominiaq on 10.08.2021.
//
#pragma once
#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <limits>


template <typename T>
class Matrix
{
private:
    std::vector<std::vector<T>> data_;

    unsigned int rows_{};
    unsigned int cols_{};
public:

    /**
     * Default constructor without parameters
     */
    Matrix<T>() = default;

    /**
     * Creating a Matrix by rows and cols values
     *
     * @param rows Number of rows in the matrix
     * @param cols Number of columns in the matrix
     */
    Matrix<T>(unsigned int rows, unsigned int cols);

    /**
     * Matrix Multiplication by operator *, number of columns in the first matrix must be equal to number of rows
     * in the "rhs" Matrix
     *
     * @param rhs Second matrix to multiply
     * @return Matrix multiplication result
     */
    Matrix<T> operator*(const Matrix& rhs);


    /**
     * Fills the matrix with values from user
     */
    void input();

    /**
     * Fills the matrix with random values
     */
    void rand();

    /**
     * Prints the matrix
     */
    void print();



};

#endif //MATRIX_MATRIX_H
