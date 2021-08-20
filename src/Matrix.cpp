//
// Created by kdominiaq on 10.08.2021.
//


#include "Matrix.h"


template<class T>
        Matrix<T>::Matrix(unsigned int rows, unsigned int cols)
        {
            try {
                if (rows < 2) {
                    throw std::invalid_argument("initialization(): incorrect matrix dimensions -> rows");
                }
                else if (cols < 2) {
                    throw std::invalid_argument("initialization(): incorrect matrix dimensions -> cols");
                }
            }
            catch (std::invalid_argument &e) {
                std::cerr << e.what() << std::endl;
            }

            rows_ = rows;
            cols_ = cols;
            data_.resize(rows_);

            for (size_t r = 0; r < rows_; r++) {
                data_[r].resize(cols_);
            }
        }

        template<typename T>
        Matrix<T> Matrix<T>::operator*(Matrix<T>& rhs) {
            try {
                if (this->cols_ != rhs.rows_) {
                    throw std::logic_error("multiply(): incorrect matrix dimensions");
                }
            }
            catch (std::logic_error &e) {
                std::cerr << e.what() << std::endl;
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
        Matrix<T> Matrix<T>::compute_grad(Matrix<T>& A, Matrix<T>& B, bool derivative_by_first_matrix) {
            Matrix<T> Z = A * B;

            Matrix<T> dA_final(A.rows_ * Z.rows_, A.cols_ * Z.cols_);
            Matrix<T> dB_final(B.rows_ * Z.rows_, B.cols_ * Z.cols_);

            // Values are needed for saving variables in the final matrix
            size_t r_temp = 0;
            size_t c_temp = 0;



            if(derivative_by_first_matrix){
                // dZ/dA
                for (size_t r = 0; r < A.rows_; r++) {
                    for (size_t c = 0; c < A.cols_; c++) {
                        Matrix<T> dA_itr(A.rows_, A.cols_);
                        Matrix<T> dA_itr_partial(Z.rows_, Z.cols_);
                        // Preparing Matrix for partial derivative, check README for more schematic of derivative matrix.
                        dA_itr.data_[r][c] = 1;
                        dA_itr_partial = dA_itr * B;

                        // Saving the obtained results to the final matrix
                        r_temp = r * A.rows_;
                        for (size_t r_final = 0; r_final < dA_itr_partial.rows_; r_final++) {
                            c_temp = c * B.cols_;
                            for (size_t c_final = 0; c_final < dA_itr_partial.cols_; c_final++) {

                                dA_final.data_[r_temp][c_temp] = dA_itr_partial.data_[r_final][c_final];
                                c_temp++;
                            }
                            r_temp++;
                        }
                    }
                }
                return dA_final;
            }
            else{
                // dZ/dB
                for (size_t r = 0; r < B.rows_; r++) {
                    for (size_t c = 0; c < B.cols_; c++) {

                        Matrix<T> dB_itr(B.rows_, B.cols_);
                        Matrix<T> dB_itr_partial(Z.rows_, Z.cols_);
                        dB_itr.data_[r][c] = 1;

                        // Partial derivative
                        dB_itr_partial = A * dB_itr;

                        // Saving the obtained results to the final
                        r_temp = r * A.rows_;
                        for (size_t r_final = 0; r_final < dB_itr_partial.rows_; r_final++) {
                            c_temp = c * B.cols_;
                            for (size_t c_final = 0; c_final < dB_itr_partial.cols_; c_final++) {

                                dB_final.data_[r_temp][c_temp] = dB_itr_partial.data_[r_final][c_final];
                                c_temp++;
                            }

                            r_temp++;
                        }
                    }
                }
                return dB_final;
            }
        }


        template<typename T>
        void Matrix<T>::init_value_by_user() {

            T temp;
            bool correct_type;

            std::cout << "Define Matrix value by value" << std::endl;
            for (size_t r = 0; r < this->rows_; r++)
            {
                for (size_t c = 0; c < this->cols_; c++) {
                    correct_type = false;
                    while (!correct_type)
                    {
                        std::cout << "Row:" << r + 1 << ", Col: " << c + 1 << ": ";
                        std::cin >> temp;

                        if (std::cin.fail()) {
                            std::cout << "Incorrect type of value!" << std::endl;
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                        else {
                            correct_type = true;
                        }

                    }
                    data_[r][c] = temp;
                }
            }
        }


        template<typename T>
        void Matrix<T>::init_value()
        {
            T itr = 0.1;
            for (size_t r = 0; r < rows_; r++) {
                for (size_t c = 0; c < cols_; c++) {
                    data_[r][c] = itr;
                    itr+=0.1;
                }
            }
        }


        template<typename T>
        void Matrix<T>::print()
        {
            std::cout << "[[";
            for (size_t r = 0; r < data_.size(); r++) {
                if (r > 0) {
                    std::cout << " [";
                }
                for (size_t c = 0; c < data_[r].size(); c++) {
                    printf("%4.1f", data_[r][c]);
                    if (c < data_[r].size() - 1) {
                        std::cout << ", ";
                    }
                }
                if (r < data_.size() - 1) {
                    std::cout << "]," << std::endl;
                }
            }
            std::cout << "]]" << std::endl;
        }


        template<typename T>
        Matrix<T>::~Matrix<T>() 
        {
            for (size_t r = 0; r < rows_; r++) {
                std::vector<T>().swap(data_[r]);
                data_[r].clear();
            }
        std::vector<std::vector<T>>().swap(data_);
        data_.clear();
}


template class Matrix<double>;
template class Matrix<float>;
