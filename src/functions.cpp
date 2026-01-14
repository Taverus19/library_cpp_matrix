#include <cmath>

#include "s21_matrix_oop.h"

void S21Matrix::set_rows(int rows) {
  if (rows <= 0) {
    throw std::invalid_argument("Number of rows must be more than zero");
  }

  if (rows != rows_) {
    S21Matrix tmp_matrix(rows, cols_);
    int min_rows = rows < rows_ ? rows : rows_;
    for (int i = 0; i < min_rows; i++) {
      for (int j = 0; j < cols_; j++) {
        tmp_matrix.matrix_[i][j] = matrix_[i][j];
      }
    }
    *this = std::move(tmp_matrix);
  }
}

void S21Matrix::set_cols(int cols) {
  if (cols <= 0) {
    throw std::invalid_argument("Number of rows must be more than zero");
  }

  if (cols != cols_) {
    S21Matrix tmp_matrix(rows_, cols);
    int min_cols = cols < cols_ ? cols : cols_;
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < min_cols; j++) {
        tmp_matrix.matrix_[i][j] = matrix_[i][j];
      }
    }
    *this = std::move(tmp_matrix);
  }
}

int S21Matrix::get_rows() { return rows_; }

int S21Matrix::get_cols() { return cols_; }

void S21Matrix::allocate_memory(int rows, int cols) {
  if (rows_ <= 0 || cols_ <= 0) {
    throw std::invalid_argument("matrix_ rows and cols must be positive");
  }

  matrix_ = new double*[rows]();
  for (int i = 0; i < rows; i++) {
    matrix_[i] = new double[cols]();
  }
}

void S21Matrix::free_memory() {
  if (matrix_) {
    for (int i = 0; i < rows_; i++) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
    matrix_ = nullptr;
  }
}

bool S21Matrix::EqMatrix(const S21Matrix& other) {
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

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::out_of_range(
        "Incorrect input, matrices should have the same size");
  }

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] += other.matrix_[i][j];
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::out_of_range(
        "Incorrect input, matrices should have the same size");
  }

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] -= other.matrix_[i][j];
    }
  }
}

void S21Matrix::MulNumber(const double num) {
  if (std::isnan(num)) {
    throw std::invalid_argument("Cannot multiply matrix_ by NaN");
  }

  if (std::isinf(num)) {
    throw std::invalid_argument("Cannot multiply matrix_ by infinity");
  }

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] *= num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (cols_ != other.rows_) {
    throw std::invalid_argument(
        "Number of columns of the first matrix must equal number of rows of "
        "the second matrix");
  }

  S21Matrix result(rows_, other.cols_);

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < other.cols_; j++) {
      result.matrix_[i][j] = 0;
      for (int k = 0; k < cols_; k++) {
        result.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
      }
    }
  }

  *this = result;
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix res(cols_, rows_);

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      res.matrix_[j][i] = matrix_[i][j];
    }
  }

  return res;
}

double S21Matrix::Determinant() {
  if (rows_ != cols_) {
    throw std::invalid_argument(
        "matrix_ must be square for determinant calculation");
  }

  if (rows_ == 1) {
    return matrix_[0][0];
  }

  if (rows_ == 2) {
    return matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
  }

  double det = 0;
  int sign = 1;

  for (int j = 0; j < cols_; j++) {
    S21Matrix minor(rows_ - 1, cols_ - 1);

    int minor_row = 0;
    for (int i = 1; i < rows_; i++) {
      int minor_col = 0;
      for (int k = 0; k < cols_; k++) {
        if (k != j) {
          minor.matrix_[minor_row][minor_col] = matrix_[i][k];
          minor_col++;
        }
      }
      minor_row++;
    }

    det += sign * matrix_[0][j] * minor.Determinant();
    sign *= -1;
  }

  return det;
}

S21Matrix S21Matrix::CalcComplements() {
  if (rows_ != cols_) {
    throw std::invalid_argument(
        "matrix_ must be square for complements calculation");
  }

  if (rows_ == 1) {
    S21Matrix result(1, 1);
    result.matrix_[0][0] = 1;
    return result;
  }

  S21Matrix result(rows_, cols_);

  for (int row = 0; row < rows_; row++) {
    for (int col = 0; col < cols_; col++) {
      S21Matrix minor(rows_ - 1, cols_ - 1);

      int minor_i = 0;
      for (int i = 0; i < rows_; i++) {
        if (i == row) continue;

        int minor_j = 0;
        for (int j = 0; j < cols_; j++) {
          if (j == col) continue;

          minor.matrix_[minor_i][minor_j] = matrix_[i][j];
          minor_j++;
        }
        minor_i++;
      }

      double minor_det = minor.Determinant();
      result.matrix_[row][col] = minor_det * std::pow(-1, row + col);
    }
  }

  return result;
}

S21Matrix S21Matrix::InverseMatrix() {
  if (rows_ != cols_) {
    throw std::invalid_argument(
        "matrix_ must be square for inverse calculation");
  }

  double det = Determinant();
  if (fabs(det) < 1e-7) {
    throw std::invalid_argument(
        "matrix_ determinant is zero, inverse does not exist");
  }

  if (rows_ == 1) {
    S21Matrix inverse(1, 1);
    inverse.matrix_[0][0] = 1.0 / matrix_[0][0];
    return inverse;
  }

  S21Matrix complements = CalcComplements();

  S21Matrix adjugate = complements.Transpose();

  S21Matrix inverse = adjugate * (1.0 / det);

  return inverse;
}