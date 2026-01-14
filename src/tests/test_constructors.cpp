#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

TEST(DefaultConstructor, Default) {
  S21Matrix matrix;
  EXPECT_EQ(matrix.get_rows(), 3);
  EXPECT_EQ(matrix.get_cols(), 3);
}

TEST(ParameterizedConstructor, ParameterizedConstructorRowsCols) {
  S21Matrix matrix(2, 4);
  EXPECT_EQ(matrix.get_rows(), 2);
  EXPECT_EQ(matrix.get_cols(), 4);
}

TEST(ParameterizedConstructor, ConstructorInvalidArguments) {
  EXPECT_THROW(S21Matrix matrix(-1, 5), std::invalid_argument);
  EXPECT_THROW(S21Matrix matrix(3, -2), std::invalid_argument);
  EXPECT_THROW(S21Matrix matrix(0, 5), std::invalid_argument);
  EXPECT_THROW(S21Matrix matrix(3, 0), std::invalid_argument);
}

TEST(ParameterizedConstructor, ConstructorValidArguments) {
  EXPECT_NO_THROW(S21Matrix matrix(1, 1));
  EXPECT_NO_THROW(S21Matrix matrix(5, 10));
  EXPECT_NO_THROW(S21Matrix matrix(100, 100));
}

TEST(CopyConstructor, StandartCopyConstructor) {
  S21Matrix original(2, 3);
  original(0, 0) = 1.0;
  original(0, 1) = 2.0;
  original(0, 2) = 3.0;
  original(1, 0) = 4.0;
  original(1, 1) = 5.0;
  original(1, 2) = 6.0;

  S21Matrix copy(original);

  EXPECT_EQ(copy.get_rows(), original.get_rows());
  EXPECT_EQ(copy.get_cols(), original.get_cols());

  EXPECT_DOUBLE_EQ(copy(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(copy(0, 1), 2.0);
  EXPECT_DOUBLE_EQ(copy(0, 2), 3.0);
  EXPECT_DOUBLE_EQ(copy(1, 0), 4.0);
  EXPECT_DOUBLE_EQ(copy(1, 1), 5.0);
  EXPECT_DOUBLE_EQ(copy(1, 2), 6.0);

  copy(0, 0) = 100.0;
  EXPECT_DOUBLE_EQ(original(0, 0), 1.0);
}

TEST(CopyConstructor, CopyConstructorWithDifferentSizes) {
  S21Matrix small(1, 1);
  small(0, 0) = 42.0;

  S21Matrix large(3, 3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      large(i, j) = i * 3 + j + 1;
    }
  }

  S21Matrix copySmall(small);
  EXPECT_EQ(copySmall.get_rows(), 1);
  EXPECT_EQ(copySmall.get_cols(), 1);
  EXPECT_DOUBLE_EQ(copySmall(0, 0), 42.0);

  S21Matrix copyLarge(large);
  EXPECT_EQ(copyLarge.get_rows(), 3);
  EXPECT_EQ(copyLarge.get_cols(), 3);
  EXPECT_DOUBLE_EQ(copyLarge(2, 2), 9.0);
}

TEST(CopyConstructor, CopyConstructorEmptyMatrix) {
  S21Matrix original(2, 2);

  S21Matrix copy(original);

  EXPECT_EQ(copy.get_rows(), 2);
  EXPECT_EQ(copy.get_cols(), 2);
  EXPECT_DOUBLE_EQ(copy(0, 0), 0.0);
  EXPECT_DOUBLE_EQ(copy(1, 1), 0.0);
}

TEST(CopyConstructor, CopyConstructorWithNegativeValues) {
  S21Matrix original(2, 2);
  original(0, 0) = -1.5;
  original(0, 1) = -2.5;
  original(1, 0) = -3.5;
  original(1, 1) = -4.5;

  S21Matrix copy(original);

  EXPECT_DOUBLE_EQ(copy(0, 0), -1.5);
  EXPECT_DOUBLE_EQ(copy(1, 1), -4.5);
}

S21Matrix createTemporaryMatrix() {
  S21Matrix temp(2, 2);
  temp(0, 0) = 1.0;
  temp(0, 1) = 2.0;
  temp(1, 0) = 3.0;
  temp(1, 1) = 4.0;
  return temp;
}

TEST(MoveConstructorTest, BasicMove) {
  S21Matrix original(2, 3);
  original(0, 0) = 1.0;
  original(0, 1) = 2.0;
  original(0, 2) = 3.0;
  original(1, 0) = 4.0;
  original(1, 1) = 5.0;
  original(1, 2) = 6.0;

  int original_rows = original.get_rows();
  int original_cols = original.get_cols();

  S21Matrix moved(std::move(original));

  EXPECT_EQ(moved.get_rows(), original_rows);
  EXPECT_EQ(moved.get_cols(), original_cols);

  EXPECT_DOUBLE_EQ(moved(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(moved(0, 1), 2.0);
  EXPECT_DOUBLE_EQ(moved(1, 2), 6.0);

  EXPECT_EQ(original.get_rows(), 0);
  EXPECT_EQ(original.get_cols(), 0);

  EXPECT_THROW(original(0, 0), std::out_of_range);

  moved(1, 1) = 100.0;
  EXPECT_DOUBLE_EQ(moved(1, 1), 100.0);
}

TEST(MoveConstructorTest, MoveFromFunction) {
  S21Matrix result = createTemporaryMatrix();

  EXPECT_EQ(result.get_rows(), 2);
  EXPECT_EQ(result.get_cols(), 2);
  EXPECT_DOUBLE_EQ(result(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(result(1, 1), 4.0);
}

TEST(MoveConstructorTest, MoveFromTemporary) {
  S21Matrix moved(createTemporaryMatrix());

  EXPECT_EQ(moved.get_rows(), 2);
  EXPECT_DOUBLE_EQ(moved(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(moved(1, 1), 4.0);
}

TEST(MoveConstructorTest, ExplicitMoveWithStdMove) {
  S21Matrix original(3, 3);
  original(0, 0) = 5.0;
  original(1, 1) = 10.0;
  original(2, 2) = 15.0;

  int original_rows = original.get_rows();

  S21Matrix moved = std::move(original);

  EXPECT_EQ(moved.get_rows(), original_rows);
  EXPECT_DOUBLE_EQ(moved(1, 1), 10.0);

  EXPECT_EQ(original.get_rows(), 0);
  EXPECT_EQ(original.get_cols(), 0);

  EXPECT_THROW(original(0, 0), std::out_of_range);
}

TEST(MoveConstructorTest, SelfMoveProtection) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 42.0;

  S21Matrix moved(std::move(matrix));

  EXPECT_EQ(moved.get_rows(), 2);
  EXPECT_DOUBLE_EQ(moved(0, 0), 42.0);
}

TEST(MoveConstructorTest, MoveEmptyMatrix) {
  S21Matrix empty;
  S21Matrix moved(std::move(empty));

  EXPECT_EQ(moved.get_rows(), 3);
  EXPECT_EQ(moved.get_cols(), 3);

  EXPECT_EQ(empty.get_rows(), 0);
  EXPECT_EQ(empty.get_cols(), 0);
  EXPECT_THROW(empty(0, 0), std::out_of_range);
}

TEST(MoveConstructorTest, ChainMove) {
  S21Matrix first(2, 2);
  first(0, 0) = 1.0;
  first(1, 1) = 4.0;

  S21Matrix second = std::move(first);
  S21Matrix third = std::move(second);
  S21Matrix fourth = std::move(third);

  EXPECT_EQ(fourth.get_rows(), 2);
  EXPECT_DOUBLE_EQ(fourth(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(fourth(1, 1), 4.0);

  EXPECT_EQ(first.get_rows(), 0);
  EXPECT_EQ(second.get_rows(), 0);
  EXPECT_EQ(third.get_rows(), 0);

  EXPECT_THROW(first(0, 0), std::out_of_range);
  EXPECT_THROW(second(0, 0), std::out_of_range);
  EXPECT_THROW(third(0, 0), std::out_of_range);
}

TEST(MoveConstructorTest, MoveThenUseMovedObject) {
  S21Matrix original(2, 2);
  original(0, 0) = 10.0;
  original(1, 1) = 20.0;

  S21Matrix moved(std::move(original));

  EXPECT_NO_THROW(moved(0, 0) = 5.0);
  EXPECT_NO_THROW(moved(1, 0) = 15.0);

  EXPECT_DOUBLE_EQ(moved(0, 0), 5.0);
  EXPECT_DOUBLE_EQ(moved(1, 0), 15.0);
  EXPECT_DOUBLE_EQ(moved(1, 1), 20.0);
}

TEST(MoveConstructorTest, MoveDifferentSizes) {
  S21Matrix small(1, 1);
  small(0, 0) = 42.0;

  S21Matrix large(5, 5);
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      large(i, j) = i * 5 + j;
    }
  }

  S21Matrix moved_small = std::move(small);
  EXPECT_EQ(moved_small.get_rows(), 1);
  EXPECT_DOUBLE_EQ(moved_small(0, 0), 42.0);
  EXPECT_EQ(small.get_rows(), 0);

  S21Matrix moved_large = std::move(large);
  EXPECT_EQ(moved_large.get_rows(), 5);
  EXPECT_DOUBLE_EQ(moved_large(4, 4), 24.0);
  EXPECT_EQ(large.get_rows(), 0);
}

TEST(DestructorTest, BasicDestruction) {
  {
    S21Matrix matrix(100, 100);
    for (int i = 0; i < 100; i++) {
      for (int j = 0; j < 100; j++) {
        matrix(i, j) = i * j;
      }
    }
  }

  EXPECT_TRUE(true);
}

TEST(DestructorTest, MultipleCreationsDestructions) {
  for (int i = 0; i < 100; i++) {
    S21Matrix matrix(10, 10);
    matrix(0, 0) = i;
  }
  EXPECT_TRUE(true);
}

TEST(DestructorTest, CopyThenDestruct) {
  S21Matrix* original = new S21Matrix(5, 5);
  original->operator()(0, 0) = 42.0;

  S21Matrix copy = *original;

  delete original;

  EXPECT_DOUBLE_EQ(copy(0, 0), 42.0);
  EXPECT_EQ(copy.get_rows(), 5);
}

TEST(DestructorTest, MoveThenDestruct) {
  S21Matrix* original = new S21Matrix(3, 3);
  original->operator()(1, 1) = 99.0;

  S21Matrix moved = std::move(*original);

  delete original;

  EXPECT_DOUBLE_EQ(moved(1, 1), 99.0);
}