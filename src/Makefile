CC = gcc
CFLAGS = -std=c++20 -Wall -Werror -Wextra -Wpedantic
LIB = s21_matrix_oop.a
TEST_TARGET = matrix_test

LDFLAGS = -lstdc++ -lm
GTEST_FLAGS = -lgtest -lgtest_main -lpthread

SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, out/%.o, $(SRC))
TEST_SRC = $(wildcard tests/*.cpp)
TEST_OBJ = $(patsubst tests/%.cpp, out/%.o, $(TEST_SRC))

all: $(LIB) test

$(LIB): $(OBJ)
	ar rcs $(LIB) $(OBJ)

test: $(TEST_TARGET)
	./$(TEST_TARGET)

$(TEST_TARGET): $(filter-out out/main.o, $(OBJ)) $(TEST_OBJ)
	$(CC) $^ -o $(TEST_TARGET) $(GTEST_FLAGS) $(LDFLAGS)

out/%.o: %.cpp
	@mkdir -p out
	$(CC) $(CFLAGS) -c $< -o $@

out/%.o: tests/%.cpp
	@mkdir -p out
	$(CC) $(CFLAGS) -c $< -o $@

re: clean all

memory:
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./$(TEST_TARGET)

style:
	clang-format -style=Google -n *.cpp *.h -n tests/*.cpp
	clang-format -style=Google -i *.cpp *.h -i tests/*.cpp

clean:
	rm -rf $(LIB) $(TEST_TARGET) out

.PHONY: all test clean re memory style