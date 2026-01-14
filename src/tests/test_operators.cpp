#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

TEST(OperatorPlus, Addition) {
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

  S21Matrix result = matrix1 + matrix2;

  EXPECT_DOUBLE_EQ(result(0, 0), 6.0);
  EXPECT_DOUBLE_EQ(result(0, 1), 8.0);
  EXPECT_DOUBLE_EQ(result(1, 0), 10.0);
  EXPECT_DOUBLE_EQ(result(1, 1), 12.0);
}

TEST(OperatorPlus, WithNegativeNumbers) {
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

  S21Matrix result = matrix1 + matrix2;

  EXPECT_DOUBLE_EQ(result(0, 0), 4.0);
  EXPECT_DOUBLE_EQ(result(0, 1), -8.0);
  EXPECT_DOUBLE_EQ(result(1, 0), -10.0);
  EXPECT_DOUBLE_EQ(result(1, 1), 4.0);
}

TEST(OperatorPlus, WithDecimalNumbers) {
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(2, 2);

  matrix1(0, 0) = 1.5;
  matrix1(0, 1) = 2.25;
  matrix1(1, 0) = 3.75;
  matrix1(1, 1) = 4.1;

  matrix2(0, 0) = 0.5;
  matrix2(0, 1) = 1.75;
  matrix2(1, 0) = 2.25;
  matrix2(1, 1) = 3.9;

  S21Matrix result = matrix1 + matrix2;

  EXPECT_DOUBLE_EQ(result(0, 0), 2.0);
  EXPECT_DOUBLE_EQ(result(0, 1), 4.0);
  EXPECT_DOUBLE_EQ(result(1, 0), 6.0);
  EXPECT_DOUBLE_EQ(result(1, 1), 8.0);
}

TEST(OperatorMinus, Subtraction) {
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(2, 2);

  matrix1(0, 0) = 10.0;
  matrix1(0, 1) = 4.0;
  matrix1(1, 0) = 3.0;
  matrix1(1, 1) = 6.0;

  matrix2(0, 0) = 5.0;
  matrix2(0, 1) = 6.0;
  matrix2(1, 0) = 7.0;
  matrix2(1, 1) = 8.0;

  S21Matrix result = matrix1 - matrix2;

  EXPECT_DOUBLE_EQ(result(0, 0), 5.0);
  EXPECT_DOUBLE_EQ(result(0, 1), -2.0);
  EXPECT_DOUBLE_EQ(result(1, 0), -4.0);
  EXPECT_DOUBLE_EQ(result(1, 1), -2.0);
}

TEST(OperatorPlusAndMinus, DifferentSizesThrowsException) {
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(3, 3);

  EXPECT_THROW(matrix1 + matrix2, std::out_of_range);
  EXPECT_THROW(matrix1 - matrix2, std::out_of_range);

  S21Matrix matrix3(2, 3);
  S21Matrix matrix4(3, 3);

  EXPECT_THROW(matrix3 + matrix4, std::out_of_range);

  S21Matrix matrix5(3, 2);
  S21Matrix matrix6(3, 3);

  EXPECT_THROW(matrix5 + matrix6, std::out_of_range);
}

TEST(OperatorMinusTest, BasicSubtraction) {
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

  S21Matrix result = matrix1 - matrix2;

  EXPECT_DOUBLE_EQ(result(0, 0), 5.0);
  EXPECT_DOUBLE_EQ(result(0, 1), 2.0);
  EXPECT_DOUBLE_EQ(result(1, 0), -1.0);
  EXPECT_DOUBLE_EQ(result(1, 1), -4.0);
}

TEST(OperatorMinusTest, SubtractionWithNegativeNumbers) {
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

  S21Matrix result = matrix1 - matrix2;

  EXPECT_DOUBLE_EQ(result(0, 0), -6.0);
  EXPECT_DOUBLE_EQ(result(0, 1), 4.0);
  EXPECT_DOUBLE_EQ(result(1, 0), 4.0);
  EXPECT_DOUBLE_EQ(result(1, 1), -12.0);
}

TEST(OperatorMinusTest, SubtractionFromZero) {
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(2, 2);

  matrix2(0, 0) = 1.0;
  matrix2(0, 1) = 2.0;
  matrix2(1, 0) = 3.0;
  matrix2(1, 1) = 4.0;

  S21Matrix result = matrix1 - matrix2;

  EXPECT_DOUBLE_EQ(result(0, 0), -1.0);
  EXPECT_DOUBLE_EQ(result(0, 1), -2.0);
  EXPECT_DOUBLE_EQ(result(1, 0), -3.0);
  EXPECT_DOUBLE_EQ(result(1, 1), -4.0);
}

TEST(OperatorMinusTest, DifferentRowsThrowsException) {
  S21Matrix matrix1(2, 3);
  S21Matrix matrix2(3, 3);

  EXPECT_THROW(matrix1 - matrix2, std::out_of_range);
}

TEST(OperatorMinusTest, DifferentColsThrowsException) {
  S21Matrix matrix1(3, 2);
  S21Matrix matrix2(3, 3);

  EXPECT_THROW(matrix1 - matrix2, std::out_of_range);
}

TEST(OperatorMinusTest, BothDifferentSizesThrowsException) {
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(3, 4);

  EXPECT_THROW(matrix1 - matrix2, std::out_of_range);
}

TEST(OperatorMultiplyNumberTest, MultiplyByPositiveNumber) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(1, 0) = 3.0;
  matrix(1, 1) = 4.0;

  S21Matrix result = matrix * 2.0;

  EXPECT_DOUBLE_EQ(result(0, 0), 2.0);
  EXPECT_DOUBLE_EQ(result(0, 1), 4.0);
  EXPECT_DOUBLE_EQ(result(1, 0), 6.0);
  EXPECT_DOUBLE_EQ(result(1, 1), 8.0);
}

TEST(OperatorMultiplyNumberTest, MultiplyByNegativeNumber) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(1, 0) = 3.0;
  matrix(1, 1) = 4.0;

  S21Matrix result = matrix * (-2.0);

  EXPECT_DOUBLE_EQ(result(0, 0), -2.0);
  EXPECT_DOUBLE_EQ(result(0, 1), -4.0);
  EXPECT_DOUBLE_EQ(result(1, 0), -6.0);
  EXPECT_DOUBLE_EQ(result(1, 1), -8.0);
}

TEST(OperatorMultiplyNumberTest, MultiplyByZero) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 5.0;
  matrix(0, 1) = 10.0;
  matrix(1, 0) = 15.0;
  matrix(1, 1) = 20.0;

  S21Matrix result = matrix * 0.0;

  EXPECT_DOUBLE_EQ(result(0, 0), 0.0);
  EXPECT_DOUBLE_EQ(result(0, 1), 0.0);
  EXPECT_DOUBLE_EQ(result(1, 0), 0.0);
  EXPECT_DOUBLE_EQ(result(1, 1), 0.0);
}

TEST(OperatorMultiplyNumberTest, MultiplyByOne) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1.5;
  matrix(0, 1) = 2.5;
  matrix(1, 0) = 3.5;
  matrix(1, 1) = 4.5;

  S21Matrix result = matrix * 1.0;

  EXPECT_DOUBLE_EQ(result(0, 0), 1.5);
  EXPECT_DOUBLE_EQ(result(0, 1), 2.5);
  EXPECT_DOUBLE_EQ(result(1, 0), 3.5);
  EXPECT_DOUBLE_EQ(result(1, 1), 4.5);
}

TEST(OperatorMultiplyNumberTest, MultiplyByFraction) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 4.0;
  matrix(0, 1) = 8.0;
  matrix(1, 0) = 12.0;
  matrix(1, 1) = 16.0;

  S21Matrix result = matrix * 0.5;

  EXPECT_DOUBLE_EQ(result(0, 0), 2.0);
  EXPECT_DOUBLE_EQ(result(0, 1), 4.0);
  EXPECT_DOUBLE_EQ(result(1, 0), 6.0);
  EXPECT_DOUBLE_EQ(result(1, 1), 8.0);
}

TEST(OperatorMultiplyNumberTest, MultiplyByDecimal) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(1, 0) = 3.0;
  matrix(1, 1) = 4.0;

  S21Matrix result = matrix * 1.5;

  EXPECT_DOUBLE_EQ(result(0, 0), 1.5);
  EXPECT_DOUBLE_EQ(result(0, 1), 3.0);
  EXPECT_DOUBLE_EQ(result(1, 0), 4.5);
  EXPECT_DOUBLE_EQ(result(1, 1), 6.0);
}

TEST(OperatorMultiplyNumberTest, MultiplyPositiveInfinityThrowsException) {
  S21Matrix matrix(2, 2);

  double inf_value = 1.0 / 0.0;

  EXPECT_THROW(matrix * inf_value, std::invalid_argument);
}

TEST(OperatorMultiplyNumberTest, MultiplyNegativeInfinityThrowsException) {
  S21Matrix matrix(2, 2);

  double neg_inf_value = -1.0 / 0.0;

  EXPECT_THROW(matrix * neg_inf_value, std::invalid_argument);
}

TEST(OperatorMultiplyMatrixTest, BasicMultiplication) {
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

  S21Matrix result = matrix1 * matrix2;

  EXPECT_EQ(result.get_rows(), 2);
  EXPECT_EQ(result.get_cols(), 2);

  EXPECT_DOUBLE_EQ(result(0, 0), 58.0);
  EXPECT_DOUBLE_EQ(result(0, 1), 64.0);
  EXPECT_DOUBLE_EQ(result(1, 0), 139.0);
  EXPECT_DOUBLE_EQ(result(1, 1), 154.0);
}

TEST(OperatorMultiplyMatrixTest, SquareMatrices) {
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

  S21Matrix result = matrix1 * matrix2;

  EXPECT_EQ(result.get_rows(), 2);
  EXPECT_EQ(result.get_cols(), 2);

  EXPECT_DOUBLE_EQ(result(0, 0), 19.0);
  EXPECT_DOUBLE_EQ(result(0, 1), 22.0);
  EXPECT_DOUBLE_EQ(result(1, 0), 43.0);
  EXPECT_DOUBLE_EQ(result(1, 1), 50.0);
}

TEST(OperatorMultiplyMatrixTest, IncompatibleSizesThrowsException) {
  S21Matrix matrix1(2, 3);
  S21Matrix matrix2(2, 2);

  EXPECT_THROW(matrix1 * matrix2, std::invalid_argument);
}

TEST(OperatorMultiplyMatrixTest, AnotherIncompatibleSizes) {
  S21Matrix matrix1(3, 2);
  S21Matrix matrix2(3, 3);

  EXPECT_THROW(matrix1 * matrix2, std::invalid_argument);
}

TEST(OperatorMultiplyMatrixTest, OriginalMatricesUnaffected) {
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(2, 2);

  matrix1(0, 0) = 2;
  matrix2(0, 0) = 3;

  double original1_00 = matrix1(0, 0);
  double original2_00 = matrix2(0, 0);

  S21Matrix result = matrix1 * matrix2;

  EXPECT_DOUBLE_EQ(matrix1(0, 0), original1_00);
  EXPECT_DOUBLE_EQ(matrix2(0, 0), original2_00);
}

TEST(OperatorMultiplyMatrixTest, ResultIsNewMatrix) {
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(2, 2);

  matrix1(0, 0) = 2;
  matrix2(0, 0) = 3;

  S21Matrix result = matrix1 * matrix2;

  EXPECT_DOUBLE_EQ(result(0, 0), 6.0);
  result(0, 0) = 100.0;
  EXPECT_DOUBLE_EQ(matrix1(0, 0), 2.0);
  EXPECT_DOUBLE_EQ(matrix2(0, 0), 3.0);
}

TEST(OperatorEqualTest, EqualMatrices) {
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

  EXPECT_TRUE(matrix1 == matrix2);
  EXPECT_TRUE(matrix2 == matrix1);
}

TEST(OperatorEqualTest, DifferentSizes) {
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(3, 3);
  S21Matrix matrix3(2, 3);

  EXPECT_FALSE(matrix1 == matrix2);
  EXPECT_FALSE(matrix1 == matrix3);
  EXPECT_FALSE(matrix2 == matrix3);
}

TEST(OperatorEqualTest, DifferentValues) {
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

  EXPECT_FALSE(matrix1 == matrix2);
}

TEST(OperatorEqualTest, FloatingPointPrecision) {
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(2, 2);

  matrix1(0, 0) = 1.0000001;
  matrix2(0, 0) = 1.0000002;

  matrix1(0, 1) = 0.0000005;
  matrix2(0, 1) = 0.0000006;

  EXPECT_TRUE(matrix1 == matrix2);
}

TEST(OperatorEqualTest, FloatingPointDifference) {
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(2, 2);

  matrix1(0, 0) = 1.0;
  matrix2(0, 0) = 1.000001;

  matrix1(0, 1) = 0.000001;
  matrix2(0, 1) = 0.000002;

  EXPECT_FALSE(matrix1 == matrix2);
}

TEST(OperatorEqualTest, EmptyMatrices) {
  S21Matrix matrix1;
  S21Matrix matrix2;

  EXPECT_TRUE(matrix1 == matrix2);
}

TEST(OperatorEqualTest, SelfComparison) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 5.0;
  matrix(1, 1) = 10.0;

  EXPECT_TRUE(matrix == matrix);
}

TEST(OperatorEqualTest, NegativeValues) {
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

  EXPECT_TRUE(matrix1 == matrix2);
}

TEST(OperatorPlusEqualTest, BasicAddition) {
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

  matrix1 += matrix2;

  EXPECT_DOUBLE_EQ(matrix1(0, 0), 6.0);
  EXPECT_DOUBLE_EQ(matrix1(0, 1), 8.0);
  EXPECT_DOUBLE_EQ(matrix1(1, 0), 10.0);
  EXPECT_DOUBLE_EQ(matrix1(1, 1), 12.0);
}

TEST(OperatorPlusEqualTest, AdditionWithZero) {
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(2, 2);

  matrix1(0, 0) = 1.5;
  matrix1(0, 1) = 2.5;
  matrix1(1, 0) = 3.5;
  matrix1(1, 1) = 4.5;

  matrix1 += matrix2;

  EXPECT_DOUBLE_EQ(matrix1(0, 0), 1.5);
  EXPECT_DOUBLE_EQ(matrix1(0, 1), 2.5);
  EXPECT_DOUBLE_EQ(matrix1(1, 0), 3.5);
  EXPECT_DOUBLE_EQ(matrix1(1, 1), 4.5);
}

TEST(OperatorPlusEqualTest, DifferentRowsThrowsException) {
  S21Matrix matrix1(2, 3);
  S21Matrix matrix2(3, 3);

  EXPECT_THROW(matrix1 += matrix2, std::out_of_range);
}

TEST(OperatorPlusEqualTest, DifferentColsThrowsException) {
  S21Matrix matrix1(3, 2);
  S21Matrix matrix2(3, 3);

  EXPECT_THROW(matrix1 += matrix2, std::out_of_range);
}

TEST(OperatorPlusEqualTest, BothDifferentSizesThrowsException) {
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(3, 4);

  EXPECT_THROW(matrix1 += matrix2, std::out_of_range);
}

TEST(OperatorMinusEqualTest, BasicSubtraction) {
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

  matrix1 -= matrix2;

  EXPECT_DOUBLE_EQ(matrix1(0, 0), 5.0);
  EXPECT_DOUBLE_EQ(matrix1(0, 1), 2.0);
  EXPECT_DOUBLE_EQ(matrix1(1, 0), -1.0);
  EXPECT_DOUBLE_EQ(matrix1(1, 1), -4.0);
}

TEST(OperatorMinusEqualTest, SubtractionWithNegativeNumbers) {
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

  matrix1 -= matrix2;

  EXPECT_DOUBLE_EQ(matrix1(0, 0), -6.0);
  EXPECT_DOUBLE_EQ(matrix1(0, 1), 4.0);
  EXPECT_DOUBLE_EQ(matrix1(1, 0), 4.0);
  EXPECT_DOUBLE_EQ(matrix1(1, 1), -12.0);
}

TEST(OperatorMinusEqualTest, SubtractionFromZero) {
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(2, 2);

  matrix2(0, 0) = 1.0;
  matrix2(0, 1) = 2.0;
  matrix2(1, 0) = 3.0;
  matrix2(1, 1) = 4.0;

  matrix1 -= matrix2;

  EXPECT_DOUBLE_EQ(matrix1(0, 0), -1.0);
  EXPECT_DOUBLE_EQ(matrix1(0, 1), -2.0);
  EXPECT_DOUBLE_EQ(matrix1(1, 0), -3.0);
  EXPECT_DOUBLE_EQ(matrix1(1, 1), -4.0);
}

TEST(OperatorMinusEqualTest, DifferentRowsThrowsException) {
  S21Matrix matrix1(2, 3);
  S21Matrix matrix2(3, 3);

  EXPECT_THROW(matrix1 -= matrix2, std::out_of_range);
}

TEST(OperatorMinusEqualTest, DifferentColsThrowsException) {
  S21Matrix matrix1(3, 2);
  S21Matrix matrix2(3, 3);

  EXPECT_THROW(matrix1 -= matrix2, std::out_of_range);
}

TEST(OperatorMinusEqualTest, BothDifferentSizesThrowsException) {
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(3, 4);

  EXPECT_THROW(matrix1 -= matrix2, std::out_of_range);
}

TEST(OperatorMultiplyEqualNumberTest, MultiplyByPositiveNumber) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(1, 0) = 3.0;
  matrix(1, 1) = 4.0;

  matrix *= 2.0;

  EXPECT_DOUBLE_EQ(matrix(0, 0), 2.0);
  EXPECT_DOUBLE_EQ(matrix(0, 1), 4.0);
  EXPECT_DOUBLE_EQ(matrix(1, 0), 6.0);
  EXPECT_DOUBLE_EQ(matrix(1, 1), 8.0);
}

TEST(OperatorMultiplyEqualNumberTest, MultiplyByNegativeNumber) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(1, 0) = 3.0;
  matrix(1, 1) = 4.0;

  matrix *= (-2.0);

  EXPECT_DOUBLE_EQ(matrix(0, 0), -2.0);
  EXPECT_DOUBLE_EQ(matrix(0, 1), -4.0);
  EXPECT_DOUBLE_EQ(matrix(1, 0), -6.0);
  EXPECT_DOUBLE_EQ(matrix(1, 1), -8.0);
}

TEST(OperatorMultiplyEqualNumberTest, MultiplyByZero) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 5.0;
  matrix(0, 1) = 10.0;
  matrix(1, 0) = 15.0;
  matrix(1, 1) = 20.0;

  matrix *= 0.0;

  EXPECT_DOUBLE_EQ(matrix(0, 0), 0.0);
  EXPECT_DOUBLE_EQ(matrix(0, 1), 0.0);
  EXPECT_DOUBLE_EQ(matrix(1, 0), 0.0);
  EXPECT_DOUBLE_EQ(matrix(1, 1), 0.0);
}

TEST(OperatorMultiplyEqualNumberTest, MultiplyByOne) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1.5;
  matrix(0, 1) = 2.5;
  matrix(1, 0) = 3.5;
  matrix(1, 1) = 4.5;

  matrix *= 1.0;

  EXPECT_DOUBLE_EQ(matrix(0, 0), 1.5);
  EXPECT_DOUBLE_EQ(matrix(0, 1), 2.5);
  EXPECT_DOUBLE_EQ(matrix(1, 0), 3.5);
  EXPECT_DOUBLE_EQ(matrix(1, 1), 4.5);
}

TEST(OperatorMultiplyEqualNumberTest, MultiplyByFraction) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 4.0;
  matrix(0, 1) = 8.0;
  matrix(1, 0) = 12.0;
  matrix(1, 1) = 16.0;

  matrix *= 0.5;

  EXPECT_DOUBLE_EQ(matrix(0, 0), 2.0);
  EXPECT_DOUBLE_EQ(matrix(0, 1), 4.0);
  EXPECT_DOUBLE_EQ(matrix(1, 0), 6.0);
  EXPECT_DOUBLE_EQ(matrix(1, 1), 8.0);
}

TEST(OperatorMultiplyEqualNumberTest, MultiplyByDecimal) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(1, 0) = 3.0;
  matrix(1, 1) = 4.0;

  matrix *= 1.5;

  EXPECT_DOUBLE_EQ(matrix(0, 0), 1.5);
  EXPECT_DOUBLE_EQ(matrix(0, 1), 3.0);
  EXPECT_DOUBLE_EQ(matrix(1, 0), 4.5);
  EXPECT_DOUBLE_EQ(matrix(1, 1), 6.0);
}

TEST(OperatorMultiplyEqualNumberTest, MultiplyPositiveInfinityThrowsException) {
  S21Matrix matrix(2, 2);

  double inf_value = 1.0 / 0.0;

  EXPECT_THROW(matrix *= inf_value, std::invalid_argument);
}

TEST(OperatorMultiplyEqualNumberTest, MultiplyNegativeInfinityThrowsException) {
  S21Matrix matrix(2, 2);

  double neg_inf_value = -1.0 / 0.0;

  EXPECT_THROW(matrix *= neg_inf_value, std::invalid_argument);
}

TEST(OperatorMultiplyEqualMatrixTest, BasicMultiplication) {
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

  matrix1 *= matrix2;

  EXPECT_EQ(matrix1.get_rows(), 2);
  EXPECT_EQ(matrix1.get_cols(), 2);

  EXPECT_DOUBLE_EQ(matrix1(0, 0), 58.0);
  EXPECT_DOUBLE_EQ(matrix1(0, 1), 64.0);
  EXPECT_DOUBLE_EQ(matrix1(1, 0), 139.0);
  EXPECT_DOUBLE_EQ(matrix1(1, 1), 154.0);
}

TEST(OperatorMultiplyEqualMatrixTest, SquareMatrices) {
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

  matrix1 *= matrix2;

  EXPECT_EQ(matrix1.get_rows(), 2);
  EXPECT_EQ(matrix1.get_cols(), 2);

  EXPECT_DOUBLE_EQ(matrix1(0, 0), 19.0);
  EXPECT_DOUBLE_EQ(matrix1(0, 1), 22.0);
  EXPECT_DOUBLE_EQ(matrix1(1, 0), 43.0);
  EXPECT_DOUBLE_EQ(matrix1(1, 1), 50.0);
}

TEST(OperatorMultiplyEqualMatrixTest, IncompatibleSizesThrowsException) {
  S21Matrix matrix1(2, 3);
  S21Matrix matrix2(2, 2);

  EXPECT_THROW(matrix1 *= matrix2, std::invalid_argument);
}

TEST(OperatorMultiplyEqualMatrixTest, ReturnReference) {
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(2, 2);

  matrix1(0, 0) = 2;
  matrix2(0, 0) = 3;

  S21Matrix& result = (matrix1 *= matrix2);

  EXPECT_EQ(&result, &matrix1);
}

TEST(OperatorMultiplyEqualMatrixTest, Chaining) {
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(2, 2);
  S21Matrix matrix3(2, 2);

  matrix1(0, 0) = 1;
  matrix2(0, 0) = 2;
  matrix3(0, 0) = 3;

  matrix1 *= matrix2 *= matrix3;

  EXPECT_DOUBLE_EQ(matrix3(0, 0), 3.0);
  EXPECT_DOUBLE_EQ(matrix1(0, 0), 6.0);
}

TEST(OperatorAssignmentTest, BasicAssignment) {
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

  matrix1 = matrix2;

  EXPECT_DOUBLE_EQ(matrix1(0, 0), 5.0);
  EXPECT_DOUBLE_EQ(matrix1(0, 1), 6.0);
  EXPECT_DOUBLE_EQ(matrix1(1, 0), 7.0);
  EXPECT_DOUBLE_EQ(matrix1(1, 1), 8.0);

  EXPECT_DOUBLE_EQ(matrix2(0, 0), 5.0);
  EXPECT_DOUBLE_EQ(matrix2(0, 1), 6.0);
}

TEST(OperatorAssignmentTest, DifferentSizes) {
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(3, 4);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      matrix2(i, j) = i * 4 + j + 1;
    }
  }

  matrix1 = matrix2;

  EXPECT_EQ(matrix1.get_rows(), 3);
  EXPECT_EQ(matrix1.get_cols(), 4);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      EXPECT_DOUBLE_EQ(matrix1(i, j), i * 4 + j + 1);
    }
  }
}

TEST(OperatorAssignmentTest, SelfAssignment) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 5.0;
  matrix(1, 1) = 10.0;

  matrix = matrix;

  EXPECT_DOUBLE_EQ(matrix(0, 0), 5.0);
  EXPECT_DOUBLE_EQ(matrix(1, 1), 10.0);
  EXPECT_EQ(matrix.get_rows(), 2);
  EXPECT_EQ(matrix.get_cols(), 2);
}

TEST(OperatorAssignmentTest, ReturnReference) {
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(2, 2);

  matrix2(0, 0) = 42.0;

  S21Matrix& result = (matrix1 = matrix2);

  EXPECT_EQ(&result, &matrix1);
  EXPECT_DOUBLE_EQ(matrix1(0, 0), 42.0);
}

TEST(OperatorAssignmentTest, Chaining) {
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(2, 2);
  S21Matrix matrix3(2, 2);

  matrix2(0, 0) = 10.0;
  matrix3(0, 0) = 20.0;

  matrix1 = matrix2 = matrix3;

  EXPECT_DOUBLE_EQ(matrix1(0, 0), 20.0);
  EXPECT_DOUBLE_EQ(matrix2(0, 0), 20.0);
  EXPECT_DOUBLE_EQ(matrix3(0, 0), 20.0);
}

TEST(OperatorAssignmentTest, DeepCopy) {
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(2, 2);

  matrix1(0, 0) = 1.0;
  matrix2(0, 0) = 2.0;

  matrix1 = matrix2;

  matrix1(0, 0) = 100.0;

  EXPECT_DOUBLE_EQ(matrix1(0, 0), 100.0);
  EXPECT_DOUBLE_EQ(matrix2(0, 0), 2.0);
}

TEST(OperatorParenthesesTest, ValidAccess) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(1, 0) = 3.0;
  matrix(1, 1) = 4.0;

  EXPECT_DOUBLE_EQ(matrix(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(matrix(0, 1), 2.0);
  EXPECT_DOUBLE_EQ(matrix(1, 0), 3.0);
  EXPECT_DOUBLE_EQ(matrix(1, 1), 4.0);
}

TEST(OperatorParenthesesTest, WriteAndRead) {
  S21Matrix matrix(2, 2);

  matrix(0, 0) = 5.5;
  matrix(1, 1) = 10.5;

  EXPECT_DOUBLE_EQ(matrix(0, 0), 5.5);
  EXPECT_DOUBLE_EQ(matrix(1, 1), 10.5);
}

TEST(OperatorParenthesesTest, NegativeRowThrowsException) {
  S21Matrix matrix(2, 2);

  EXPECT_THROW(matrix(-1, 0), std::out_of_range);
  EXPECT_THROW(matrix(-5, 1), std::out_of_range);
}

TEST(OperatorParenthesesTest, NegativeColThrowsException) {
  S21Matrix matrix(2, 2);

  EXPECT_THROW(matrix(0, -1), std::out_of_range);
  EXPECT_THROW(matrix(1, -3), std::out_of_range);
}

TEST(OperatorParenthesesTest, RowOutOfRangeThrowsException) {
  S21Matrix matrix(2, 2);

  EXPECT_THROW(matrix(2, 0), std::out_of_range);
  EXPECT_THROW(matrix(5, 1), std::out_of_range);
}

TEST(OperatorParenthesesTest, ColOutOfRangeThrowsException) {
  S21Matrix matrix(2, 2);

  EXPECT_THROW(matrix(0, 2), std::out_of_range);
  EXPECT_THROW(matrix(1, 5), std::out_of_range);
}

TEST(OperatorParenthesesTest, BothIndicesOutOfRange) {
  S21Matrix matrix(2, 2);

  EXPECT_THROW(matrix(5, 5), std::out_of_range);
  EXPECT_THROW(matrix(-1, -1), std::out_of_range);
}

TEST(OperatorParenthesesTest, SingleElementMatrix) {
  S21Matrix matrix(1, 1);

  matrix(0, 0) = 42.0;
  EXPECT_DOUBLE_EQ(matrix(0, 0), 42.0);

  EXPECT_THROW(matrix(1, 0), std::out_of_range);
  EXPECT_THROW(matrix(0, 1), std::out_of_range);
  EXPECT_THROW(matrix(-1, 0), std::out_of_range);
}

TEST(OperatorParenthesesConstTest, ReadFromConstObject) {
  const S21Matrix matrix(2, 2);

  EXPECT_DOUBLE_EQ(matrix(0, 0), 0.0);
  EXPECT_DOUBLE_EQ(matrix(1, 1), 0.0);
}

TEST(OperatorParenthesesConstTest, ReadFromPreparedConstObject) {
  S21Matrix temp(2, 2);
  temp(0, 0) = 1.0;
  temp(0, 1) = 2.0;
  temp(1, 0) = 3.0;
  temp(1, 1) = 4.0;

  const S21Matrix matrix = temp;

  EXPECT_DOUBLE_EQ(matrix(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(matrix(0, 1), 2.0);
  EXPECT_DOUBLE_EQ(matrix(1, 0), 3.0);
  EXPECT_DOUBLE_EQ(matrix(1, 1), 4.0);
}

TEST(OperatorParenthesesConstTest, CannotModifyThroughConstReference) {
  const S21Matrix matrix(2, 2);

  double value = matrix(0, 0);
  EXPECT_DOUBLE_EQ(value, 0.0);
}

TEST(OperatorParenthesesConstTest, BoundaryChecksOnConstObject) {
  const S21Matrix matrix(2, 2);

  EXPECT_THROW(matrix(-1, 0), std::out_of_range);
  EXPECT_THROW(matrix(0, -1), std::out_of_range);
  EXPECT_THROW(matrix(2, 0), std::out_of_range);
  EXPECT_THROW(matrix(0, 2), std::out_of_range);
}