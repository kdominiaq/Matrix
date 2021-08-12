//
// Created by kdominiaq on 10.08.2021.
//

#include "Matrix.h"

template<class T>
Matrix<T>::Matrix(unsigned int rows,unsigned int cols)
{
    rows_ = rows;
    cols_ = cols;
    data_.resize(rows_);

    for (size_t r = 0; r < rows_; r++) {
        data_[r].resize(cols_);
    }
}

template<typename T>
Matrix<T> Matrix<T>::operator*(Matrix<T> &rhs) {
    if (this->cols_ != rhs.rows_) {
        std::cerr << "multiply(): incorrect matrix dimensions" << std::endl;
        return Matrix<T>();
    }

    Matrix<T> result(this->rows_, rhs.cols_);
    for (size_t r = 0; r < result.rows_; r++)
    {
        for (size_t c = 0; c < result.cols_; c++) {
            result.data_[r][c] = 0;
            for (size_t i = 0; i < this->cols_; i++) {
                result.data_[r][c] += this->data_[r][i] * rhs.data_[i][c];
            }
        }
    }

    return result;
}


template<typename T>
Matrix<T> Matrix<T>::compute_grad(Matrix<T>& A, Matrix<T>& B){
    Matrix<T> Z = A * B;


            Matrix<T> dB_final(A.rows_*B.rows_, A.cols_*B.cols_);

                for (size_t r = 0; r < B.rows_; r++) {
                    for (size_t c = 0; c < B.cols_; c++) {
                            Matrix<T> dB_itr(B.rows_, B.cols_);
                            Matrix<T> dB_itr_step_result(Z.rows_, Z.cols_);
                            dB_itr.data_[r][c] = 1;

                            dB_itr_step_result = A*dB_itr;

                            dB_itr_step_result.print();
                            std::cout << "-------------------" <<std::endl;

                        }
                    }




            return Z;
}

template<typename T>
void Matrix<T>::input() {

    T temp;
    bool correct_type;

    std::cout << "Define Matrix value by value" << std::endl;
    for (size_t r = 0; r < this->rows_; r++)
    {
        for (size_t c = 0; c < this->cols_; c++) {
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
    for (size_t r = 0; r < rows_; r++) {
        for (size_t c = 0; c < cols_; c++) {
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
