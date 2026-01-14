#include <cstring>

#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() : rows_(3), cols_(3) { allocate_memory(rows_, cols_); }

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  if (rows <= 0 || cols <= 0) {
    throw std::invalid_argument("Rows and cols must be positive");
  }
  allocate_memory(rows_, cols_);
}

S21Matrix::S21Matrix(const S21Matrix& other)
    : rows_(other.rows_), cols_(other.cols_) {
  matrix_ = new double*[rows_]();
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_]();
    std::memcpy(matrix_[i], other.matrix_[i], cols_ * sizeof(double));
  }
}

S21Matrix::S21Matrix(S21Matrix&& other) {
  if (this != &other) {
    rows_ = other.rows_;
    cols_ = other.cols_;
    matrix_ = other.matrix_;
    other.matrix_ = nullptr;
    other.rows_ = 0;
    other.cols_ = 0;
  }
}

S21Matrix::~S21Matrix() { free_memory(); }
