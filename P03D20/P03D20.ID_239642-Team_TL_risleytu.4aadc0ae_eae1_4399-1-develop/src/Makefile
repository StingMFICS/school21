CC = gcc
CFLAGS = -Wall -Wextra -Werror

TARGET = ../build/graph

SRC = calculation.c get.c graph.c map_matrix.c polish.c stack.c validate.c

OBJ = $(SRC:.c=.o)

all: formating build

# formating
formating: clang-format cppcheck

clang-format: $(SRC)
	cp ../materials/linters/.clang-format ./
	clang-format -i *.c
	clang-format -i *.h

cppcheck: $(SRC)
	cppcheck --enable=all --suppress=missingIncludeSystem $^

# build
build: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# other: clean, rebuild
rebuild: clean all

clean:
	rm -rf $(OBJ) $(TARGET)
