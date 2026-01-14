#ifndef __S21MATRIX_H__
#define __S21MATRIX_H__

#include <stdexcept>

class S21Matrix {
 private:
  int rows_, cols_;
  double** matrix_;

 public:
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other);
  ~S21Matrix();

  S21Matrix operator+(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other);
  S21Matrix operator*(double num);
  S21Matrix operator*(const S21Matrix& other);
  bool operator==(const S21Matrix& other) const;
  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix& operator*=(double num);
  S21Matrix& operator*=(const S21Matrix& other);
  double& operator()(int row, int col);
  const double& operator()(int row, int col) const;

  void set_rows(int rows);
  void set_cols(int cols);
  int get_rows();
  int get_cols();

  bool EqMatrix(const S21Matrix& other);
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

  void allocate_memory(int rows, int cols);
  void free_memory();
};

#endif