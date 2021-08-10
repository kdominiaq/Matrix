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
public:

    Matrix<T>() = default;
    Matrix<T>(unsigned int rows, unsigned int cols);


private:
    std::vector<std::vector<T>> data_;

public:
    Matrix<T> operator*(const Matrix& rhs);

    /**
     * Returns number of rows
     */
    int rows() const {
        return (int)data_.size();
    }

    /**
     * Returns number of columns
     */
    int cols() const {
        return !data_.empty() ? (int) data_[0].size() : 0;
    }


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
