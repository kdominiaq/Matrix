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
            Matrix<T> operator*(Matrix<T>& rhs);


            /**
             * Compute matrix derivative with respect of matrix, dZ/dA and dZ/dB -> Z = A * B;
             *
             * @param A The first Matrix to multiply and calculations dZ/dA
             * @param B The second Matrix to multiply and calculations dZ/dB
             * @return Matrix dZ/dA
             */
            static Matrix<T> compute_grad(Matrix<T>& A, Matrix<T>& B);



            /**
             * Fills the matrix with values from user
             */
            void init_value_by_user();

            /**
             * Fills the matrix with values
             */
            void init_value();

            /**
             * Prints the matrix
             */
            void print();



        };

#endif //MATRIX_MATRIX_H
