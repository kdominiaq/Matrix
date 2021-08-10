//
// Created by kdominiaq on 10.08.2021.
//

#include "Matrix.h"

template<class T>
Matrix<T>::Matrix(unsigned int rows,unsigned int cols)
{
    data_.resize(rows);
    for (size_t r = 0; r < rows; r++) {
        data_[r].resize(cols);
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


template<typename T>
void Matrix<T>::input() {

    T temp;
    bool correct_type;

    std::cout << "Define Matrix value by value" << std::endl;
    for (size_t r = 0; r < this->rows(); r++)
    {
        for (size_t c = 0; c < this->cols(); c++) {
            correct_type = false;
            while(!correct_type)
            {
                std::cout << "Row:" << r + 1 << ", Col: " << c + 1 << ": ";
                std::cin >> temp;

                if(std::cin.fail()){
                    std::cout<<"Incorrect type of value!"<< std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                else{
                    correct_type = true;
                }

            }
            data_[r][c] = temp;
        }
    }
}


template<typename T>
void Matrix<T>::rand()
{
    for (size_t r = 0; r < rows(); r++) {
        for (size_t c = 0; c < cols(); c++) {
            data_[r][c] = T(std::rand() % 101) /10 ;
        }
    }
}

template<typename T>
void Matrix<T>::print()
{
    for (size_t r = 0; r < data_.size(); r++) {
        for (size_t c = 0; c < data_[r].size(); c++) {
            std::cout << data_[r][c]<< " ";
        }
        std::cout << std::endl;
    }
}





template class Matrix<double>;
template class Matrix<float>;