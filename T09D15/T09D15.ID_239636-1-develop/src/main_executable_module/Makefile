CC = gcc

CFLAGS = -Wall -Wextra -Werror -I../data_libs -I../yet_another_decision_module -I../data_module
STATIC = ../data_libs/data_stat.a
STATIC_O = ../data_libs/data_stat.o

DYNAMIC = ../data_module/data_process.so
DYNAMIC_O = ../data_module/data_process.o


SRC = main_executable_module.c \
      ../data_libs/data_io.c \
      ../yet_another_decision_module/decision.c \
      ../data_module/data_process.c \
      ../data_libs/data_stat.c

OBJ = main_executable_module.o \
      ../data_libs/data_io.o \
      ../yet_another_decision_module/decision.o \
      ../data_module/data_process.o \
      ../data_libs/data_stat.o

OBJ_1 = main_executable_module.o \
      ../data_libs/data_io.o \
      ../yet_another_decision_module/decision.o \
      ../data_module/data_process.o

OBJ_2 = main_executable_module.o \
      ../data_libs/data_io.o \
      ../yet_another_decision_module/decision.o

TARGET_DIR = ../../build
TARGET = $(TARGET_DIR)/Quest_3
TARGET3 = $(TARGET_DIR)/Quest_5
TARGET4 = $(TARGET_DIR)/Quest_6


all: $(TARGET)


$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJ) $(TARGET) $(TARGET3) $(STATIC) $(DYNAMIC) $(TARGET4)

rebuild: clean all

data_stat.a: $(STATIC_O)
	ar rcs $(STATIC) $^

build_with_static: data_stat.a $(OBJ)
	$(CC) $(CFLAGS) $(OBJ_1) $(STATIC) -o $(TARGET3)

data_process.so: $(DYNAMIC_O) $(STATIC_O)
	$(CC) -shared -o $(DYNAMIC) $^

build_with_dynamic: data_process.so $(OBJ)
	$(CC) $(CFLAGS) -fPIC $(OBJ_2) $(DYNAMIC) -o $(TARGET4)

.PHONY: all clean data_process.so build_with_dynamic rebuild data_stat.a build_with_static