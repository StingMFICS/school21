CC = gcc
CFLAGS = -Wall -Wextra -Werror
QUEST1_C = print_module.c main_module_entry_point.c
QUEST1_O = $(QUEST1_C:.c=.o)
QUEST2_C = main_module_entry_point.c documentation_module.c
QUEST2_O = $(QUEST1_C:.c=.o)

TARGET_DIR = ../build
TARGET1 = $(TARGET_DIR)/Quest_1
TARGET2 = $(TARGET_DIR)/Quest_2

all: $(TARGET1)

$(TARGET1): $(QUEST1_C)
	$(CC) $(CFLAGS) -D Q1 $(QUEST1_C) -o $(TARGET1)

$(TARGET2): $(QUEST2_C)
	$(CC) $(CFLAGS) -D Q2 $(QUEST2_C) -o $(TARGET2)


print_module: $(TARGET1)

documentation_module: $(TARGET2)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET1) *.o $(TARGET2)

rebuild: clean all

.PHONY: print_module all clean rebuild documentation_module