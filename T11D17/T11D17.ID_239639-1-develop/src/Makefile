CC = gcc
CFLAGS = -Wall -Wextra -Werror
DOOR_C = dmanager_module.c
DOOR_O = $(DOOR_C:.c=.o)
LIST_C = list.c list_test.c
LIST_O = $(LIST_C:.c=.o)

TARGET_DIR = ../build
TARGET1 = $(TARGET_DIR)/Quest_1
TARGET2 = $(TARGET_DIR)/Quest_2

all: $(TARGET1) $(TARGET2)

$(TARGET1): $(DOOR_O)
	$(CC) $(CFLAGS) $(DOOR_O) -o $(TARGET1)

$(TARGET2): $(LIST_O)
	$(CC) $(CFLAGS) $(LIST_O) -o $(TARGET2)

door_struct: $(TARGET1)

list_test: $(TARGET2)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET1) *.o $(TARGET2)

rebuild: clean all

.PHONY: list_test door_struct all clean rebuild