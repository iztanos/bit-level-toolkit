CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c11

TARGET = bit-tool

SRC = main.c bit_ops.c memory.c
OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Test target: build and run the test harness
TEST_BIN = tests/test_bit_ops

test: $(TEST_BIN)
	./$(TEST_BIN)

$(TEST_BIN): tests/test_bit_ops.c bit_ops.c memory.c
	$(CC) $(CFLAGS) tests/test_bit_ops.c bit_ops.c memory.c -o $(TEST_BIN)

clean:
	rm -f $(OBJ) $(TARGET)

rebuild: clean all

.PHONY: all clean rebuild