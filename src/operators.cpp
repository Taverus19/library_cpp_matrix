#include <cmath>
#include <cstring>

#include "s21_matrix_oop.h"

S21Matrix S21Matrix::operator+(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::out_of_range(
        "Incorrect input, matrices should have the same size");
  }
  S21Matrix res(rows_, cols_);
  for (auto i = 0; i < rows_; i++) {
    for (auto j = 0; j < cols_; j++) {
      res.matrix_[i][j] = matrix_[i][j] + other.matrix_[i][j];
    }
  }
  return res;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::out_of_range(
        "Incorrect input, matrices should have the same size");
  }
  S21Matrix res(rows_, cols_);
  for (auto i = 0; i < rows_; i++) {
    for (auto j = 0; j < cols_; j++) {
      res.matrix_[i][j] = matrix_[i][j] - other.matrix_[i][j];
    }
  }

  return res;
}

S21Matrix S21Matrix::operator*(double num) {
  if (std::isnan(num)) {
    throw std::invalid_argument("Cannot multiply matrix_ by NaN");
  }

  if (std::isinf(num)) {
    throw std::invalid_argument("Cannot multiply matrix_ by infinity");
  }

  S21Matrix res(rows_, cols_);
  for (auto i = 0; i < rows_; i++) {
    for (auto j = 0; j < cols_; j++) {
      res.matrix_[i][j] = num * matrix_[i][j];
    }
  }

  return res;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) {
  if (cols_ != other.rows_) {
    throw std::invalid_argument(
        "Incompatible matrix_ dimensions for multiplication");
  }

  S21Matrix result(rows_, other.cols_);

  for (int i = 0; i < rows_; i++) {
    for (int k = 0; k < cols_; k++) {
      double temp = matrix_[i][k];
      for (int j = 0; j < other.cols_; j++) {
        result.matrix_[i][j] += temp * other.matrix_[k][j];
      }
    }
  }

  return result;
}

bool S21Matrix::operator==(const S21Matrix& other) const {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    return false;
  }

  bool flag = true;
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      if (std::fabs(matrix_[i][j] - other.matrix_[i][j]) >= 1e-6) flag = false;
    }
  }

  return flag;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::out_of_range(
        "Incorrect input, matrices should have the same size");
  }
  for (auto i = 0; i < rows_; i++) {
    for (auto j = 0; j < cols_; j++) {
      matrix_[i][j] += other.matrix_[i][j];
    }
  }
  return *this;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::out_of_range(
        "Incorrect input, matrices should have the same size");
  }
  for (auto i = 0; i < rows_; i++) {
    for (auto j = 0; j < cols_; j++) {
      matrix_[i][j] -= other.matrix_[i][j];
    }
  }

  return *this;
}

S21Matrix& S21Matrix::operator*=(double num) {
  if (std::isnan(num)) {
    throw std::invalid_argument("Cannot multiply matrix_ by NaN");
  }

  if (std::isinf(num)) {
    throw std::invalid_argument("Cannot multiply matrix_ by infinity");
  }

  for (auto i = 0; i < rows_; i++) {
    for (auto j = 0; j < cols_; j++) {
      matrix_[i][j] *= num;
    }
  }

  return *this;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  *this = *this * other;
  return *this;
}

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  if (this == &other) return *this;

  free_memory();
  rows_ = other.rows_;
  cols_ = other.cols_;
  allocate_memory(rows_, cols_);

  for (int i = 0; i < rows_; i++) {
    std::memcpy(matrix_[i], other.matrix_[i], cols_ * sizeof(double));
  }

  return *this;
}

double& S21Matrix::operator()(int row, int col) {
  if (row < 0 || row >= rows_ || col < 0 || col >= cols_) {
    throw std::out_of_range("Incorrect input, index is out of range");
  }
  return matrix_[row][col];
}

const double& S21Matrix::operator()(int row, int col) const {
  if (row < 0 || row >= rows_ || col < 0 || col >= cols_) {
    throw std::out_of_range("Incorrect input, index is out of range");
  }
  return matrix_[row][col];
}