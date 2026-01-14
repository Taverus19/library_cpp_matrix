#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

TEST(MatrixTest, SetRows) {
  S21Matrix matrix1(2, 2);

  matrix1(0, 0) = 1.0;
  matrix1(0, 1) = 2.0;
  matrix1(1, 0) = 3.0;
  matrix1(1, 1) = 4.0;

  matrix1.set_rows(3);

  EXPECT_DOUBLE_EQ(matrix1(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(matrix1(0, 1), 2.0);
  EXPECT_DOUBLE_EQ(matrix1(1, 0), 3.0);
  EXPECT_DOUBLE_EQ(matrix1(1, 1), 4.0);
  EXPECT_DOUBLE_EQ(matrix1(2, 0), 0.0);
  EXPECT_DOUBLE_EQ(matrix1(2, 1), 0.0);

  EXPECT_EQ(matrix1.get_rows(), 3);
  EXPECT_EQ(matrix1.get_cols(), 2);
}

TEST(MatrixTest, SetRowsIncrease) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(1, 0) = 3.0;
  matrix(1, 1) = 4.0;

  matrix.set_rows(4);

  EXPECT_DOUBLE_EQ(matrix(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(matrix(1, 1), 4.0);

  EXPECT_DOUBLE_EQ(matrix(2, 0), 0.0);
  EXPECT_DOUBLE_EQ(matrix(3, 1), 0.0);

  EXPECT_EQ(matrix.get_rows(), 4);
  EXPECT_EQ(matrix.get_cols(), 2);
}

TEST(MatrixTest, SetRowsDecrease) {
  S21Matrix matrix(3, 2);
  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(1, 0) = 3.0;
  matrix(1, 1) = 4.0;
  matrix(2, 0) = 5.0;
  matrix(2, 1) = 6.0;

  matrix.set_rows(2);

  EXPECT_DOUBLE_EQ(matrix(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(matrix(1, 1), 4.0);

  EXPECT_THROW(matrix(2, 0), std::out_of_range);

  EXPECT_EQ(matrix.get_rows(), 2);
  EXPECT_EQ(matrix.get_cols(), 2);
}

TEST(MatrixTest, SetRowsSameSize) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;

  matrix.set_rows(2);

  EXPECT_DOUBLE_EQ(matrix(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(matrix(0, 1), 2.0);
  EXPECT_EQ(matrix.get_rows(), 2);
}

TEST(MatrixTest, SetRowsInvalid) {
  S21Matrix matrix(2, 2);

  EXPECT_THROW(matrix.set_rows(0), std::invalid_argument);
  EXPECT_THROW(matrix.set_rows(-1), std::invalid_argument);
}

TEST(MatrixTest, SetCols) {
  S21Matrix matrix(2, 2);

  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(1, 0) = 3.0;
  matrix(1, 1) = 4.0;

  matrix.set_cols(3);

  EXPECT_DOUBLE_EQ(matrix(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(matrix(0, 1), 2.0);
  EXPECT_DOUBLE_EQ(matrix(0, 2), 0.0);
  EXPECT_DOUBLE_EQ(matrix(1, 0), 3.0);
  EXPECT_DOUBLE_EQ(matrix(1, 1), 4.0);
  EXPECT_DOUBLE_EQ(matrix(1, 2), 0.0);

  EXPECT_EQ(matrix.get_rows(), 2);
  EXPECT_EQ(matrix.get_cols(), 3);
}

TEST(MatrixTest, SetColsDecrease) {
  S21Matrix matrix(2, 3);

  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(1, 0) = 3.0;
  matrix(1, 1) = 4.0;

  matrix.set_cols(2);

  EXPECT_DOUBLE_EQ(matrix(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(matrix(0, 1), 2.0);
  EXPECT_DOUBLE_EQ(matrix(1, 0), 3.0);
  EXPECT_DOUBLE_EQ(matrix(1, 1), 4.0);

  EXPECT_THROW(matrix(2, 0), std::out_of_range);

  EXPECT_EQ(matrix.get_rows(), 2);
  EXPECT_EQ(matrix.get_cols(), 2);
}

TEST(MatrixTest, SetColsSameSize) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;

  matrix.set_cols(2);

  EXPECT_DOUBLE_EQ(matrix(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(matrix(0, 1), 2.0);
  EXPECT_EQ(matrix.get_cols(), 2);
}

TEST(MatrixTest, SetColsInvalid) {
  S21Matrix matrix(2, 2);

  EXPECT_THROW(matrix.set_cols(0), std::invalid_argument);
  EXPECT_THROW(matrix.set_cols(-1), std::invalid_argument);
}

TEST(MatrixTest, GetRowsGetColsDefaultConstructor) {
  S21Matrix matrix;

  EXPECT_EQ(matrix.get_rows(), 3);
  EXPECT_EQ(matrix.get_cols(), 3);
}

TEST(MatrixTest, GetRowsGetColsParameterizedConstructor) {
  S21Matrix matrix(5, 7);

  EXPECT_EQ(matrix.get_rows(), 5);
  EXPECT_EQ(matrix.get_cols(), 7);
}

TEST(MatrixTest, GetRowsGetColsAfterSetRows) {
  S21Matrix matrix(2, 3);

  matrix.set_rows(5);
  EXPECT_EQ(matrix.get_rows(), 5);
  EXPECT_EQ(matrix.get_cols(), 3);

  matrix.set_rows(1);
  EXPECT_EQ(matrix.get_rows(), 1);
}

TEST(MatrixTest, GetRowsGetColsAfterSetCols) {
  S21Matrix matrix(4, 2);

  matrix.set_cols(6);
  EXPECT_EQ(matrix.get_rows(), 4);
  EXPECT_EQ(matrix.get_cols(), 6);

  matrix.set_cols(1);
  EXPECT_EQ(matrix.get_cols(), 1);
}

TEST(MatrixTest, GetRowsGetColsCopyConstructor) {
  S21Matrix original(3, 4);
  S21Matrix copy(original);

  EXPECT_EQ(copy.get_rows(), 3);
  EXPECT_EQ(copy.get_cols(), 4);
}

TEST(MatrixTest, GetRowsGetColsMoveConstructor) {
  S21Matrix original(2, 5);
  S21Matrix moved(std::move(original));

  EXPECT_EQ(moved.get_rows(), 2);
  EXPECT_EQ(moved.get_cols(), 5);
  EXPECT_EQ(original.get_rows(), 0);
  EXPECT_EQ(original.get_cols(), 0);
}

TEST(MatrixTest, GetRowsGetColsAssignmentOperator) {
  S21Matrix matrix1(3, 3);
  S21Matrix matrix2(1, 1);

  matrix2 = matrix1;

  EXPECT_EQ(matrix2.get_rows(), 3);
  EXPECT_EQ(matrix2.get_cols(), 3);
}

TEST(MatrixTest, GetRowsGetColsConsistency) {
  S21Matrix matrix(3, 4);

  EXPECT_EQ(matrix.get_rows(), matrix.get_rows());
  EXPECT_EQ(matrix.get_cols(), matrix.get_cols());

  matrix.set_rows(5);
  EXPECT_EQ(matrix.get_rows(), 5);
  EXPECT_EQ(matrix.get_rows(), 5);

  matrix.set_cols(6);
  EXPECT_EQ(matrix.get_cols(), 6);
  EXPECT_EQ(matrix.get_cols(), 6);
}

TEST(MatrixTest, EqMatrix) {
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(3, 3);
  bool res;

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 4;
  matrix1(1, 0) = 2;
  matrix1(1, 1) = 5;

  matrix2(0, 0) = 1;
  matrix2(0, 1) = -1;
  matrix2(1, 0) = 1;
  matrix2(1, 1) = 2;

  res = matrix1.EqMatrix(matrix2);

  EXPECT_FALSE(res);
}

TEST(EqMatrixTest, EqualMatricesTrue) {
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(2, 2);

  matrix1(0, 0) = 1.0;
  matrix1(0, 1) = 2.0;
  matrix1(1, 0) = 3.0;
  matrix1(1, 1) = 4.0;

  matrix2(0, 0) = 1.0;
  matrix2(0, 1) = 2.0;
  matrix2(1, 0) = 3.0;
  matrix2(1, 1) = 4.0;

  EXPECT_TRUE(matrix1.EqMatrix(matrix2));
  EXPECT_TRUE(matrix2.EqMatrix(matrix1));
}

TEST(EqMatrixTest, DifferentSizes) {
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(3, 3);
  S21Matrix matrix3(2, 3);

  EXPECT_FALSE(matrix1.EqMatrix(matrix2));
  EXPECT_FALSE(matrix1.EqMatrix(matrix3));
  EXPECT_FALSE(matrix2.EqMatrix(matrix3));
}

TEST(EqMatrixTest, DifferentValues) {
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(2, 2);

  matrix1(0, 0) = 1.0;
  matrix1(0, 1) = 2.0;
  matrix1(1, 0) = 3.0;
  matrix1(1, 1) = 4.0;

  matrix2(0, 0) = 1.0;
  matrix2(0, 1) = 2.0;
  matrix2(1, 0) = 3.0;
  matrix2(1, 1) = 5.0;

  EXPECT_FALSE(matrix1.EqMatrix(matrix2));
}

TEST(EqMatrixTest, FloatingPointPrecision) {
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(2, 2);

  matrix1(0, 0) = 1.0000001;
  matrix2(0, 0) = 1.0000002;

  matrix1(0, 1) = 0.0000005;
  matrix2(0, 1) = 0.0000006;

  EXPECT_TRUE(matrix1.EqMatrix(matrix2));
}

TEST(EqMatrixTest, FloatingPointDifference) {
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(2, 2);

  matrix1(0, 0) = 1.0;
  matrix2(0, 0) = 1.000001;

  matrix1(0, 1) = 0.000001;
  matrix2(0, 1) = 0.000002;

  EXPECT_FALSE(matrix1.EqMatrix(matrix2));
}

TEST(EqMatrixTest, SelfComparison) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 5.0;
  matrix(1, 1) = 10.0;

  EXPECT_TRUE(matrix.EqMatrix(matrix));
}

TEST(EqMatrixTest, NegativeValues) {
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(2, 2);

  matrix1(0, 0) = -1.5;
  matrix1(0, 1) = -2.5;
  matrix1(1, 0) = -3.5;
  matrix1(1, 1) = -4.5;

  matrix2(0, 0) = -1.5;
  matrix2(0, 1) = -2.5;
  matrix2(1, 0) = -3.5;
  matrix2(1, 1) = -4.5;

  EXPECT_TRUE(matrix1.EqMatrix(matrix2));
}

TEST(MatrixTest, SumMatrix) {
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(2, 2);

  matrix1(0, 0) = 1.0;
  matrix1(0, 1) = 2.0;
  matrix1(1, 0) = 3.0;
  matrix1(1, 1) = 4.0;

  matrix2(0, 0) = 5.0;
  matrix2(0, 1) = 6.0;
  matrix2(1, 0) = 7.0;
  matrix2(1, 1) = 8.0;

  matrix1.SumMatrix(matrix2);

  EXPECT_DOUBLE_EQ(matrix1(0, 0), 6.0);
  EXPECT_DOUBLE_EQ(matrix1(0, 1), 8.0);
  EXPECT_DOUBLE_EQ(matrix1(1, 0), 10.0);
  EXPECT_DOUBLE_EQ(matrix1(1, 1), 12.0);
}

TEST(SumMatrixTest, AdditionWithNegativeNumbers) {
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(2, 2);

  matrix1(0, 0) = -1.0;
  matrix1(0, 1) = -2.0;
  matrix1(1, 0) = -3.0;
  matrix1(1, 1) = -4.0;

  matrix2(0, 0) = 5.0;
  matrix2(0, 1) = -6.0;
  matrix2(1, 0) = -7.0;
  matrix2(1, 1) = 8.0;

  matrix1.SumMatrix(matrix2);

  EXPECT_DOUBLE_EQ(matrix1(0, 0), 4.0);
  EXPECT_DOUBLE_EQ(matrix1(0, 1), -8.0);
  EXPECT_DOUBLE_EQ(matrix1(1, 0), -10.0);
  EXPECT_DOUBLE_EQ(matrix1(1, 1), 4.0);
}

TEST(SumMatrixTest, AdditionWithZero) {
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(2, 2);

  matrix1(0, 0) = 1.5;
  matrix1(0, 1) = 2.5;
  matrix1(1, 0) = 3.5;
  matrix1(1, 1) = 4.5;

  matrix1.SumMatrix(matrix2);

  EXPECT_DOUBLE_EQ(matrix1(0, 0), 1.5);
  EXPECT_DOUBLE_EQ(matrix1(0, 1), 2.5);
  EXPECT_DOUBLE_EQ(matrix1(1, 0), 3.5);
  EXPECT_DOUBLE_EQ(matrix1(1, 1), 4.5);
}

TEST(SumMatrixTest, AdditionWithDecimalNumbers) {
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(2, 2);

  matrix1(0, 0) = 1.1;
  matrix1(0, 1) = 2.2;
  matrix1(1, 0) = 3.3;
  matrix1(1, 1) = 4.4;

  matrix2(0, 0) = 0.1;
  matrix2(0, 1) = 0.2;
  matrix2(1, 0) = 0.3;
  matrix2(1, 1) = 0.4;

  matrix1.SumMatrix(matrix2);

  EXPECT_DOUBLE_EQ(matrix1(0, 0), 1.2);
  EXPECT_DOUBLE_EQ(matrix1(0, 1), 2.4);
  EXPECT_DOUBLE_EQ(matrix1(1, 0), 3.6);
  EXPECT_DOUBLE_EQ(matrix1(1, 1), 4.8);
}

TEST(SumMatrixTest, DifferentRowsThrowsException) {
  S21Matrix matrix1(2, 3);
  S21Matrix matrix2(3, 3);

  EXPECT_THROW(matrix1.SumMatrix(matrix2), std::out_of_range);
}

TEST(SumMatrixTest, DifferentColsThrowsException) {
  S21Matrix matrix1(3, 2);
  S21Matrix matrix2(3, 3);

  EXPECT_THROW(matrix1.SumMatrix(matrix2), std::out_of_range);
}

TEST(SumMatrixTest, BothDifferentSizesThrowsException) {
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(3, 4);

  EXPECT_THROW(matrix1.SumMatrix(matrix2), std::out_of_range);
}

TEST(SumMatrixTest, SelfAddition) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(1, 0) = 3.0;
  matrix(1, 1) = 4.0;

  matrix.SumMatrix(matrix);

  EXPECT_DOUBLE_EQ(matrix(0, 0), 2.0);
  EXPECT_DOUBLE_EQ(matrix(0, 1), 4.0);
  EXPECT_DOUBLE_EQ(matrix(1, 0), 6.0);
  EXPECT_DOUBLE_EQ(matrix(1, 1), 8.0);
}

TEST(SubMatrixTest, BasicSubtraction) {
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(2, 2);

  matrix1(0, 0) = 10.0;
  matrix1(0, 1) = 8.0;
  matrix1(1, 0) = 6.0;
  matrix1(1, 1) = 4.0;

  matrix2(0, 0) = 5.0;
  matrix2(0, 1) = 6.0;
  matrix2(1, 0) = 7.0;
  matrix2(1, 1) = 8.0;

  matrix1.SubMatrix(matrix2);

  EXPECT_DOUBLE_EQ(matrix1(0, 0), 5.0);
  EXPECT_DOUBLE_EQ(matrix1(0, 1), 2.0);
  EXPECT_DOUBLE_EQ(matrix1(1, 0), -1.0);
  EXPECT_DOUBLE_EQ(matrix1(1, 1), -4.0);
}

TEST(SubMatrixTest, SubtractionWithNegativeNumbers) {
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(2, 2);

  matrix1(0, 0) = -1.0;
  matrix1(0, 1) = -2.0;
  matrix1(1, 0) = -3.0;
  matrix1(1, 1) = -4.0;

  matrix2(0, 0) = 5.0;
  matrix2(0, 1) = -6.0;
  matrix2(1, 0) = -7.0;
  matrix2(1, 1) = 8.0;

  matrix1.SubMatrix(matrix2);

  EXPECT_DOUBLE_EQ(matrix1(0, 0), -6.0);
  EXPECT_DOUBLE_EQ(matrix1(0, 1), 4.0);
  EXPECT_DOUBLE_EQ(matrix1(1, 0), 4.0);
  EXPECT_DOUBLE_EQ(matrix1(1, 1), -12.0);
}

TEST(SubMatrixTest, SubtractionWithZero) {
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(2, 2);

  matrix1(0, 0) = 1.5;
  matrix1(0, 1) = 2.5;
  matrix1(1, 0) = 3.5;
  matrix1(1, 1) = 4.5;

  matrix1.SubMatrix(matrix2);

  EXPECT_DOUBLE_EQ(matrix1(0, 0), 1.5);
  EXPECT_DOUBLE_EQ(matrix1(0, 1), 2.5);
  EXPECT_DOUBLE_EQ(matrix1(1, 0), 3.5);
  EXPECT_DOUBLE_EQ(matrix1(1, 1), 4.5);
}

TEST(SubMatrixTest, SubtractionFromZero) {
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(2, 2);

  matrix2(0, 0) = 1.0;
  matrix2(0, 1) = 2.0;
  matrix2(1, 0) = 3.0;
  matrix2(1, 1) = 4.0;

  matrix1.SubMatrix(matrix2);

  EXPECT_DOUBLE_EQ(matrix1(0, 0), -1.0);
  EXPECT_DOUBLE_EQ(matrix1(0, 1), -2.0);
  EXPECT_DOUBLE_EQ(matrix1(1, 0), -3.0);
  EXPECT_DOUBLE_EQ(matrix1(1, 1), -4.0);
}

TEST(SubMatrixTest, SubtractionWithDecimalNumbers) {
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(2, 2);

  matrix1(0, 0) = 5.5;
  matrix1(0, 1) = 4.4;
  matrix1(1, 0) = 3.3;
  matrix1(1, 1) = 2.2;

  matrix2(0, 0) = 1.1;
  matrix2(0, 1) = 2.2;
  matrix2(1, 0) = 3.3;
  matrix2(1, 1) = 4.4;

  matrix1.SubMatrix(matrix2);

  EXPECT_DOUBLE_EQ(matrix1(0, 0), 4.4);
  EXPECT_DOUBLE_EQ(matrix1(0, 1), 2.2);
  EXPECT_DOUBLE_EQ(matrix1(1, 0), 0.0);
  EXPECT_DOUBLE_EQ(matrix1(1, 1), -2.2);
}

TEST(SubMatrixTest, DifferentRowsThrowsException) {
  S21Matrix matrix1(2, 3);
  S21Matrix matrix2(3, 3);

  EXPECT_THROW(matrix1.SubMatrix(matrix2), std::out_of_range);
}

TEST(SubMatrixTest, DifferentColsThrowsException) {
  S21Matrix matrix1(3, 2);
  S21Matrix matrix2(3, 3);

  EXPECT_THROW(matrix1.SubMatrix(matrix2), std::out_of_range);
}

TEST(SubMatrixTest, BothDifferentSizesThrowsException) {
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(3, 4);

  EXPECT_THROW(matrix1.SubMatrix(matrix2), std::out_of_range);
}

TEST(SubMatrixTest, SelfSubtraction) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 5.0;
  matrix(0, 1) = 10.0;
  matrix(1, 0) = 15.0;
  matrix(1, 1) = 20.0;

  matrix.SubMatrix(matrix);

  EXPECT_DOUBLE_EQ(matrix(0, 0), 0.0);
  EXPECT_DOUBLE_EQ(matrix(0, 1), 0.0);
  EXPECT_DOUBLE_EQ(matrix(1, 0), 0.0);
  EXPECT_DOUBLE_EQ(matrix(1, 1), 0.0);
}

TEST(MulNumberTest, MultiplyByPositiveNumber) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(1, 0) = 3.0;
  matrix(1, 1) = 4.0;

  matrix.MulNumber(2.0);

  EXPECT_DOUBLE_EQ(matrix(0, 0), 2.0);
  EXPECT_DOUBLE_EQ(matrix(0, 1), 4.0);
  EXPECT_DOUBLE_EQ(matrix(1, 0), 6.0);
  EXPECT_DOUBLE_EQ(matrix(1, 1), 8.0);
}

TEST(MulNumberTest, MultiplyByNegativeNumber) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(1, 0) = 3.0;
  matrix(1, 1) = 4.0;

  matrix.MulNumber(-2.0);

  EXPECT_DOUBLE_EQ(matrix(0, 0), -2.0);
  EXPECT_DOUBLE_EQ(matrix(0, 1), -4.0);
  EXPECT_DOUBLE_EQ(matrix(1, 0), -6.0);
  EXPECT_DOUBLE_EQ(matrix(1, 1), -8.0);
}

TEST(MulNumberTest, MultiplyByZero) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 5.0;
  matrix(0, 1) = 10.0;
  matrix(1, 0) = 15.0;
  matrix(1, 1) = 20.0;

  matrix.MulNumber(0.0);

  EXPECT_DOUBLE_EQ(matrix(0, 0), 0.0);
  EXPECT_DOUBLE_EQ(matrix(0, 1), 0.0);
  EXPECT_DOUBLE_EQ(matrix(1, 0), 0.0);
  EXPECT_DOUBLE_EQ(matrix(1, 1), 0.0);
}

TEST(MulNumberTest, MultiplyByOne) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1.5;
  matrix(0, 1) = 2.5;
  matrix(1, 0) = 3.5;
  matrix(1, 1) = 4.5;

  matrix.MulNumber(1.0);

  EXPECT_DOUBLE_EQ(matrix(0, 0), 1.5);
  EXPECT_DOUBLE_EQ(matrix(0, 1), 2.5);
  EXPECT_DOUBLE_EQ(matrix(1, 0), 3.5);
  EXPECT_DOUBLE_EQ(matrix(1, 1), 4.5);
}

TEST(MulNumberTest, MultiplyByFraction) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 4.0;
  matrix(0, 1) = 8.0;
  matrix(1, 0) = 12.0;
  matrix(1, 1) = 16.0;

  matrix.MulNumber(0.5);

  EXPECT_DOUBLE_EQ(matrix(0, 0), 2.0);
  EXPECT_DOUBLE_EQ(matrix(0, 1), 4.0);
  EXPECT_DOUBLE_EQ(matrix(1, 0), 6.0);
  EXPECT_DOUBLE_EQ(matrix(1, 1), 8.0);
}

TEST(MulNumberTest, MultiplyByDecimal) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(1, 0) = 3.0;
  matrix(1, 1) = 4.0;

  matrix.MulNumber(1.5);

  EXPECT_DOUBLE_EQ(matrix(0, 0), 1.5);
  EXPECT_DOUBLE_EQ(matrix(0, 1), 3.0);
  EXPECT_DOUBLE_EQ(matrix(1, 0), 4.5);
  EXPECT_DOUBLE_EQ(matrix(1, 1), 6.0);
}

TEST(MulMatrixTest, BasicMultiplication) {
  S21Matrix matrix1(2, 3);
  S21Matrix matrix2(3, 2);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(0, 2) = 3;
  matrix1(1, 0) = 4;
  matrix1(1, 1) = 5;
  matrix1(1, 2) = 6;

  matrix2(0, 0) = 7;
  matrix2(0, 1) = 8;
  matrix2(1, 0) = 9;
  matrix2(1, 1) = 10;
  matrix2(2, 0) = 11;
  matrix2(2, 1) = 12;

  matrix1.MulMatrix(matrix2);

  EXPECT_EQ(matrix1.get_rows(), 2);
  EXPECT_EQ(matrix1.get_cols(), 2);

  EXPECT_DOUBLE_EQ(matrix1(0, 0), 58.0);
  EXPECT_DOUBLE_EQ(matrix1(0, 1), 64.0);
  EXPECT_DOUBLE_EQ(matrix1(1, 0), 139.0);
  EXPECT_DOUBLE_EQ(matrix1(1, 1), 154.0);
}

TEST(MulMatrixTest, SquareMatrices) {
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(2, 2);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  matrix2(0, 0) = 5;
  matrix2(0, 1) = 6;
  matrix2(1, 0) = 7;
  matrix2(1, 1) = 8;

  matrix1.MulMatrix(matrix2);

  EXPECT_EQ(matrix1.get_rows(), 2);
  EXPECT_EQ(matrix1.get_cols(), 2);

  EXPECT_DOUBLE_EQ(matrix1(0, 0), 19.0);
  EXPECT_DOUBLE_EQ(matrix1(0, 1), 22.0);
  EXPECT_DOUBLE_EQ(matrix1(1, 0), 43.0);
  EXPECT_DOUBLE_EQ(matrix1(1, 1), 50.0);
}

TEST(MulMatrixTest, IncompatibleSizesThrowsException) {
  S21Matrix matrix1(2, 3);
  S21Matrix matrix2(2, 2);

  EXPECT_THROW(matrix1.MulMatrix(matrix2), std::invalid_argument);
}

TEST(MulMatrixTest, AnotherIncompatibleSizes) {
  S21Matrix matrix1(3, 2);
  S21Matrix matrix2(3, 3);

  EXPECT_THROW(matrix1.MulMatrix(matrix2), std::invalid_argument);
}

TEST(TransposeTest, SquareMatrix) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(1, 0) = 3.0;
  matrix(1, 1) = 4.0;

  S21Matrix transposed = matrix.Transpose();

  EXPECT_EQ(transposed.get_rows(), 2);
  EXPECT_EQ(transposed.get_cols(), 2);

  EXPECT_DOUBLE_EQ(transposed(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(transposed(0, 1), 3.0);
  EXPECT_DOUBLE_EQ(transposed(1, 0), 2.0);
  EXPECT_DOUBLE_EQ(transposed(1, 1), 4.0);
}

TEST(TransposeTest, RectangularMatrix) {
  S21Matrix matrix(2, 3);
  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(0, 2) = 3.0;
  matrix(1, 0) = 4.0;
  matrix(1, 1) = 5.0;
  matrix(1, 2) = 6.0;

  S21Matrix transposed = matrix.Transpose();

  EXPECT_EQ(transposed.get_rows(), 3);
  EXPECT_EQ(transposed.get_cols(), 2);

  EXPECT_DOUBLE_EQ(transposed(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(transposed(0, 1), 4.0);
  EXPECT_DOUBLE_EQ(transposed(1, 0), 2.0);
  EXPECT_DOUBLE_EQ(transposed(1, 1), 5.0);
  EXPECT_DOUBLE_EQ(transposed(2, 0), 3.0);
  EXPECT_DOUBLE_EQ(transposed(2, 1), 6.0);
}

TEST(TransposeTest, SingleRowMatrix) {
  S21Matrix matrix(1, 3);
  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(0, 2) = 3.0;

  S21Matrix transposed = matrix.Transpose();

  EXPECT_EQ(transposed.get_rows(), 3);
  EXPECT_EQ(transposed.get_cols(), 1);

  EXPECT_DOUBLE_EQ(transposed(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(transposed(1, 0), 2.0);
  EXPECT_DOUBLE_EQ(transposed(2, 0), 3.0);
}

TEST(TransposeTest, SingleColumnMatrix) {
  S21Matrix matrix(3, 1);
  matrix(0, 0) = 1.0;
  matrix(1, 0) = 2.0;
  matrix(2, 0) = 3.0;

  S21Matrix transposed = matrix.Transpose();

  EXPECT_EQ(transposed.get_rows(), 1);
  EXPECT_EQ(transposed.get_cols(), 3);

  EXPECT_DOUBLE_EQ(transposed(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(transposed(0, 1), 2.0);
  EXPECT_DOUBLE_EQ(transposed(0, 2), 3.0);
}

TEST(TransposeTest, SingleElementMatrix) {
  S21Matrix matrix(1, 1);
  matrix(0, 0) = 5.0;

  S21Matrix transposed = matrix.Transpose();

  EXPECT_EQ(transposed.get_rows(), 1);
  EXPECT_EQ(transposed.get_cols(), 1);
  EXPECT_DOUBLE_EQ(transposed(0, 0), 5.0);
}

TEST(TransposeTest, DefaultConstructorMatrix) {
  S21Matrix matrix;

  S21Matrix transposed = matrix.Transpose();

  EXPECT_EQ(transposed.get_rows(), 3);
  EXPECT_EQ(transposed.get_cols(), 3);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      EXPECT_DOUBLE_EQ(transposed(i, j), 0.0);
    }
  }
}

TEST(TransposeTest, DoubleTranspose) {
  S21Matrix matrix(2, 3);
  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(0, 2) = 3.0;
  matrix(1, 0) = 4.0;
  matrix(1, 1) = 5.0;
  matrix(1, 2) = 6.0;

  S21Matrix double_transposed = matrix.Transpose().Transpose();

  EXPECT_EQ(double_transposed.get_rows(), 2);
  EXPECT_EQ(double_transposed.get_cols(), 3);

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      EXPECT_DOUBLE_EQ(double_transposed(i, j), matrix(i, j));
    }
  }
}

TEST(MatrixTest, Determinant) {
  S21Matrix matrix(3, 3);

  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(0, 2) = 3;
  matrix(1, 0) = 4;
  matrix(1, 1) = 5;
  matrix(1, 2) = 6;
  matrix(2, 0) = 7;
  matrix(2, 1) = 8;
  matrix(2, 2) = 10;

  double det = matrix.Determinant();
  EXPECT_DOUBLE_EQ(det, -3.0);
}

TEST(DeterminantTest, OneByOneMatrix) {
  S21Matrix matrix(1, 1);
  matrix(0, 0) = 5.0;

  double det = matrix.Determinant();
  EXPECT_DOUBLE_EQ(det, 5.0);
}

TEST(DeterminantTest, TwoByTwoMatrix) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(1, 0) = 3.0;
  matrix(1, 1) = 4.0;

  double det = matrix.Determinant();
  EXPECT_DOUBLE_EQ(det, 1 * 4 - 2 * 3);
}

TEST(DeterminantTest, ThreeByThreeMatrix) {
  S21Matrix matrix(3, 3);
  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(0, 2) = 3;
  matrix(1, 0) = 4;
  matrix(1, 1) = 5;
  matrix(1, 2) = 6;
  matrix(2, 0) = 7;
  matrix(2, 1) = 8;
  matrix(2, 2) = 9;

  double det = matrix.Determinant();
  EXPECT_DOUBLE_EQ(det, 0.0);
}

TEST(DeterminantTest, NonSingularMatrix) {
  S21Matrix matrix(3, 3);
  matrix(0, 0) = 2;
  matrix(0, 1) = 5;
  matrix(0, 2) = 7;
  matrix(1, 0) = 6;
  matrix(1, 1) = 3;
  matrix(1, 2) = 4;
  matrix(2, 0) = 5;
  matrix(2, 1) = -2;
  matrix(2, 2) = -3;

  double det = matrix.Determinant();
  EXPECT_DOUBLE_EQ(det, -1.0);
}

TEST(DeterminantTest, RectangularMatrixThrowsException) {
  S21Matrix matrix1(2, 3);
  S21Matrix matrix2(3, 2);
  S21Matrix matrix3(1, 2);

  EXPECT_THROW(matrix1.Determinant(), std::invalid_argument);
  EXPECT_THROW(matrix2.Determinant(), std::invalid_argument);
  EXPECT_THROW(matrix3.Determinant(), std::invalid_argument);
}

TEST(CalcComplementsTest, OneByOneMatrix) {
  S21Matrix matrix(1, 1);
  matrix(0, 0) = 5.0;

  S21Matrix complements = matrix.CalcComplements();

  EXPECT_EQ(complements.get_rows(), 1);
  EXPECT_EQ(complements.get_cols(), 1);
  EXPECT_DOUBLE_EQ(complements(0, 0), 1.0);
}

TEST(CalcComplementsTest, TwoByTwoMatrix) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(1, 0) = 3;
  matrix(1, 1) = 4;

  S21Matrix complements = matrix.CalcComplements();

  EXPECT_EQ(complements.get_rows(), 2);
  EXPECT_EQ(complements.get_cols(), 2);

  EXPECT_DOUBLE_EQ(complements(0, 0), 4.0);
  EXPECT_DOUBLE_EQ(complements(0, 1), -3.0);
  EXPECT_DOUBLE_EQ(complements(1, 0), -2.0);
  EXPECT_DOUBLE_EQ(complements(1, 1), 1.0);
}

TEST(CalcComplementsTest, ThreeByThreeMatrix) {
  S21Matrix matrix(3, 3);
  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(0, 2) = 3;
  matrix(1, 0) = 0;
  matrix(1, 1) = 4;
  matrix(1, 2) = 2;
  matrix(2, 0) = 5;
  matrix(2, 1) = 2;
  matrix(2, 2) = 1;

  S21Matrix complements = matrix.CalcComplements();

  EXPECT_EQ(complements.get_rows(), 3);
  EXPECT_EQ(complements.get_cols(), 3);

  EXPECT_DOUBLE_EQ(complements(0, 0), 0.0);
  EXPECT_DOUBLE_EQ(complements(0, 1), 10.0);
  EXPECT_DOUBLE_EQ(complements(0, 2), -20.0);
}

TEST(CalcComplementsTest, RectangularMatrixThrowsException) {
  S21Matrix matrix1(2, 3);
  S21Matrix matrix2(3, 2);
  S21Matrix matrix3(1, 2);

  EXPECT_THROW(matrix1.CalcComplements(), std::invalid_argument);
  EXPECT_THROW(matrix2.CalcComplements(), std::invalid_argument);
  EXPECT_THROW(matrix3.CalcComplements(), std::invalid_argument);
}

TEST(CalcComplementsTest, ExceptionMessage) {
  S21Matrix matrix(2, 3);

  try {
    matrix.CalcComplements();
    FAIL() << "Expected std::invalid_argument";
  } catch (const std::invalid_argument& e) {
    EXPECT_STREQ(e.what(),
                 "matrix_ must be square for complements calculation");
  }
}

TEST(CalcComplementsTest, IdentityMatrix) {
  S21Matrix matrix(3, 3);
  matrix(0, 0) = 1;
  matrix(1, 1) = 1;
  matrix(2, 2) = 1;

  S21Matrix complements = matrix.CalcComplements();

  EXPECT_DOUBLE_EQ(complements(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(complements(0, 1), 0.0);
  EXPECT_DOUBLE_EQ(complements(0, 2), 0.0);
  EXPECT_DOUBLE_EQ(complements(1, 1), 1.0);
}

TEST(CalcComplementsTest, DiagonalMatrix) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 3;
  matrix(1, 1) = 5;

  S21Matrix complements = matrix.CalcComplements();

  EXPECT_DOUBLE_EQ(complements(0, 0), 5.0);
  EXPECT_DOUBLE_EQ(complements(0, 1), 0.0);
  EXPECT_DOUBLE_EQ(complements(1, 0), 0.0);
  EXPECT_DOUBLE_EQ(complements(1, 1), 3.0);
}

TEST(CalcComplementsTest, WithNegativeNumbers) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = -1;
  matrix(0, 1) = -2;
  matrix(1, 0) = -3;
  matrix(1, 1) = -4;

  S21Matrix complements = matrix.CalcComplements();

  EXPECT_DOUBLE_EQ(complements(0, 0), -4.0);
  EXPECT_DOUBLE_EQ(complements(0, 1), 3.0);
  EXPECT_DOUBLE_EQ(complements(1, 0), 2.0);
  EXPECT_DOUBLE_EQ(complements(1, 1), -1.0);
}

TEST(CalcComplementsTest, WithDecimalNumbers) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1.5;
  matrix(0, 1) = 2.5;
  matrix(1, 0) = 3.5;
  matrix(1, 1) = 4.5;

  S21Matrix complements = matrix.CalcComplements();

  EXPECT_DOUBLE_EQ(complements(0, 0), 4.5);
  EXPECT_DOUBLE_EQ(complements(0, 1), -3.5);
  EXPECT_DOUBLE_EQ(complements(1, 0), -2.5);
  EXPECT_DOUBLE_EQ(complements(1, 1), 1.5);
}

TEST(CalcComplementsTest, OriginalMatrixUnaffected) {
  S21Matrix original(2, 2);
  original(0, 0) = 1;
  original(0, 1) = 2;
  original(1, 0) = 3;
  original(1, 1) = 4;

  S21Matrix complements = original.CalcComplements();

  EXPECT_DOUBLE_EQ(original(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(original(0, 1), 2.0);
  EXPECT_DOUBLE_EQ(original(1, 0), 3.0);
  EXPECT_DOUBLE_EQ(original(1, 1), 4.0);
}

TEST(InverseMatrixTest, InverseMatrixUnaffected) {
  S21Matrix original(3, 3);
  original(0, 0) = 2;
  original(0, 1) = 5;
  original(0, 2) = 7;
  original(1, 0) = 6;
  original(1, 1) = 3;
  original(1, 2) = 4;
  original(2, 0) = 5;
  original(2, 1) = -2;
  original(2, 2) = -3;

  S21Matrix complements = original.InverseMatrix();

  EXPECT_EQ(complements.get_rows(), 3);
  EXPECT_EQ(complements.get_cols(), 3);

  EXPECT_DOUBLE_EQ(complements(0, 0), 1);
  EXPECT_DOUBLE_EQ(complements(0, 1), -1);
  EXPECT_DOUBLE_EQ(complements(0, 2), 1);
  EXPECT_DOUBLE_EQ(complements(1, 0), -38);
  EXPECT_DOUBLE_EQ(complements(1, 1), 41);
  EXPECT_DOUBLE_EQ(complements(1, 2), -34);
  EXPECT_DOUBLE_EQ(complements(2, 0), 27);
  EXPECT_DOUBLE_EQ(complements(2, 1), -29);
  EXPECT_DOUBLE_EQ(complements(2, 2), 24);
}

TEST(InverseMatrixTest, OneByOneMatrix) {
  S21Matrix matrix(1, 1);
  matrix(0, 0) = 5.0;

  S21Matrix inverse = matrix.InverseMatrix();

  EXPECT_EQ(inverse.get_rows(), 1);
  EXPECT_EQ(inverse.get_cols(), 1);
  EXPECT_DOUBLE_EQ(inverse(0, 0), 0.2);
}

TEST(InverseMatrixTest, TwoByTwoMatrix) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 4;
  matrix(0, 1) = 7;
  matrix(1, 0) = 2;
  matrix(1, 1) = 6;

  S21Matrix inverse = matrix.InverseMatrix();

  EXPECT_EQ(inverse.get_rows(), 2);
  EXPECT_EQ(inverse.get_cols(), 2);

  EXPECT_DOUBLE_EQ(inverse(0, 0), 0.6);
  EXPECT_DOUBLE_EQ(inverse(0, 1), -0.7);
  EXPECT_DOUBLE_EQ(inverse(1, 0), -0.2);
  EXPECT_DOUBLE_EQ(inverse(1, 1), 0.4);
}

TEST(InverseMatrixTest, RectangularMatrixThrowsException) {
  S21Matrix matrix1(2, 3);
  S21Matrix matrix2(3, 2);

  EXPECT_THROW(matrix1.InverseMatrix(), std::invalid_argument);
  EXPECT_THROW(matrix2.InverseMatrix(), std::invalid_argument);
}

TEST(InverseMatrixTest, SingularMatrixThrowsException) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(1, 0) = 2;
  matrix(1, 1) = 4;

  EXPECT_THROW(matrix.InverseMatrix(), std::invalid_argument);
}

TEST(InverseMatrixTest, ZeroDeterminantMatrix) {
  S21Matrix matrix(3, 3);

  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(0, 2) = 3;
  matrix(1, 0) = 2;
  matrix(1, 1) = 4;
  matrix(1, 2) = 6;
  matrix(2, 0) = 3;
  matrix(2, 1) = 6;
  matrix(2, 2) = 9;

  EXPECT_THROW(matrix.InverseMatrix(), std::invalid_argument);
}

TEST(InverseMatrixTest, DiagonalMatrix) {
  S21Matrix matrix(3, 3);
  matrix(0, 0) = 2;
  matrix(1, 1) = 3;
  matrix(2, 2) = 4;

  S21Matrix inverse = matrix.InverseMatrix();

  EXPECT_DOUBLE_EQ(inverse(0, 0), 0.5);
  EXPECT_DOUBLE_EQ(inverse(1, 1), 1.0 / 3);
  EXPECT_DOUBLE_EQ(inverse(2, 2), 0.25);

  EXPECT_DOUBLE_EQ(inverse(0, 1), 0.0);
  EXPECT_DOUBLE_EQ(inverse(1, 0), 0.0);
}

TEST(InverseMatrixTest, OriginalMatrixUnaffected) {
  S21Matrix original(2, 2);
  original(0, 0) = 1;
  original(0, 1) = 2;
  original(1, 0) = 3;
  original(1, 1) = 4;

  S21Matrix inverse = original.InverseMatrix();

  EXPECT_DOUBLE_EQ(original(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(original(0, 1), 2.0);
  EXPECT_DOUBLE_EQ(original(1, 0), 3.0);
  EXPECT_DOUBLE_EQ(original(1, 1), 4.0);
}

TEST(InverseMatrixTest, VerySmallDeterminant) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1e-8;
  matrix(0, 1) = 0;
  matrix(1, 0) = 0;
  matrix(1, 1) = 1e-8;

  EXPECT_THROW(matrix.InverseMatrix(), std::invalid_argument);
}

TEST(InverseMatrixTest, Inverse2x2Matrix) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 4;
  matrix(0, 1) = 7;
  matrix(1, 0) = 2;
  matrix(1, 1) = 6;

  S21Matrix inverse = matrix.InverseMatrix();

  EXPECT_EQ(inverse.get_rows(), 2);
  EXPECT_EQ(inverse.get_cols(), 2);

  EXPECT_NEAR(inverse(0, 0), 0.6, 1e-6);
  EXPECT_NEAR(inverse(0, 1), -0.7, 1e-6);
  EXPECT_NEAR(inverse(1, 0), -0.2, 1e-6);
  EXPECT_NEAR(inverse(1, 1), 0.4, 1e-6);
}

TEST(InverseMatrixTest, Inverse3x3Matrix) {
  S21Matrix matrix(3, 3);
  matrix(0, 0) = 2;
  matrix(0, 1) = 5;
  matrix(0, 2) = 7;
  matrix(1, 0) = 6;
  matrix(1, 1) = 3;
  matrix(1, 2) = 4;
  matrix(2, 0) = 5;
  matrix(2, 1) = -2;
  matrix(2, 2) = -3;

  S21Matrix inverse = matrix.InverseMatrix();

  EXPECT_EQ(inverse.get_rows(), 3);
  EXPECT_EQ(inverse.get_cols(), 3);

  EXPECT_NEAR(inverse(0, 0), 1, 1e-6);
  EXPECT_NEAR(inverse(0, 1), -1, 1e-6);
  EXPECT_NEAR(inverse(0, 2), 1, 1e-6);
  EXPECT_NEAR(inverse(1, 0), -38, 1e-6);
  EXPECT_NEAR(inverse(1, 1), 41, 1e-6);
  EXPECT_NEAR(inverse(1, 2), -34, 1e-6);
  EXPECT_NEAR(inverse(2, 0), 27, 1e-6);
  EXPECT_NEAR(inverse(2, 1), -29, 1e-6);
  EXPECT_NEAR(inverse(2, 2), 24, 1e-6);
}

TEST(InverseMatrixTest, Inverse1x1Matrix) {
  S21Matrix matrix(1, 1);
  matrix(0, 0) = 5;

  S21Matrix inverse = matrix.InverseMatrix();

  EXPECT_EQ(inverse.get_rows(), 1);
  EXPECT_EQ(inverse.get_cols(), 1);
  EXPECT_DOUBLE_EQ(inverse(0, 0), 0.2);
}

TEST(InverseMatrixTest, IdentityMatrixInverse) {
  S21Matrix matrix(3, 3);
  matrix(0, 0) = 1;
  matrix(1, 1) = 1;
  matrix(2, 2) = 1;

  S21Matrix inverse = matrix.InverseMatrix();

  EXPECT_EQ(inverse.get_rows(), 3);
  EXPECT_EQ(inverse.get_cols(), 3);

  EXPECT_DOUBLE_EQ(inverse(0, 0), 1);
  EXPECT_DOUBLE_EQ(inverse(1, 1), 1);
  EXPECT_DOUBLE_EQ(inverse(2, 2), 1);
}

TEST(InverseMatrixTest, InverseMatrixMultiplicationGivesIdentity) {
  S21Matrix matrix(3, 3);
  matrix(0, 0) = 2;
  matrix(0, 1) = -1;
  matrix(0, 2) = 0;
  matrix(1, 0) = 0;
  matrix(1, 1) = 1;
  matrix(1, 2) = 2;
  matrix(2, 0) = 1;
  matrix(2, 1) = 1;
  matrix(2, 2) = 1;

  S21Matrix inverse = matrix.InverseMatrix();
  S21Matrix identity = matrix * inverse;

  EXPECT_EQ(identity.get_rows(), 3);
  EXPECT_EQ(identity.get_cols(), 3);

  EXPECT_NEAR(identity(0, 0), 1, 1e-6);
  EXPECT_NEAR(identity(0, 1), 0, 1e-6);
  EXPECT_NEAR(identity(0, 2), 0, 1e-6);
  EXPECT_NEAR(identity(1, 0), 0, 1e-6);
  EXPECT_NEAR(identity(1, 1), 1, 1e-6);
  EXPECT_NEAR(identity(1, 2), 0, 1e-6);
  EXPECT_NEAR(identity(2, 0), 0, 1e-6);
  EXPECT_NEAR(identity(2, 1), 0, 1e-6);
  EXPECT_NEAR(identity(2, 2), 1, 1e-6);
}

TEST(InverseMatrixTest, NonSquareMatrixThrowsException) {
  S21Matrix matrix(2, 3);

  EXPECT_THROW(matrix.InverseMatrix(), std::invalid_argument);
}