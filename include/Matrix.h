//
// Created by kdominiaq on 10.08.2021.
//
#pragma once
#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H



#include <iostream>
#include <vector>
#include <cstdlib>





template <typename T>
class Matrix
{
public:
    Matrix<T>() = default;
    Matrix<T>(int rows, int cols);

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

    /**
     * Fills the matrix with random values of range [-1.0; 1.0]
     */
    void rand();

    /**
     * Prints the matrix
     */
    void print();

private:
    std::vector<std::vector<T>> data_;
};



template<class T>
Matrix<T>::Matrix(int rows, int cols)
{
    data_.resize(rows);
    for (size_t r = 0; r < rows; r++) {
        data_[r].resize(cols);
    }
}


template<typename T>
inline void Matrix<T>::rand()
{
    for (size_t r = 0; r < rows(); r++) {
        for (size_t c = 0; c < cols(); c++) {
            data_[r][c] = T(std::rand() % 11) ;
        }
    }
}

template<typename T>
inline void Matrix<T>::print()
{
    for (size_t r = 0; r < data_.size(); r++) {
        for (size_t c = 0; c < data_[r].size(); c++) {
            std::cout << data_[r][c]<< " ";
        }
        std::cout << std::endl;
    }
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix &rhs) {
    if (this->cols() != rhs.rows()) {
        std::cerr << "multiply(): incorrect matrix dimensions" << std::endl;
        return Matrix<T>();
    }

    Matrix<T> result(2, 2);
    for (size_t r = 0; r < result.rows(); r++)
    {
        for (size_t c = 0; c < result.cols(); c++) {
            result.data_[r][c] = 0;
            for (size_t i = 0; i < this->cols(); i++) {
                result.data_[r][c] += this->data_[r][i] * rhs.data_[i][c];
            }
        }
    }

    return result;
}


#endif //MATRIX_MATRIX_H
