CC = gcc

CFLAGS = -Wall -Wextra -Werror
Q1_C = cipher.c
Q1_O = $(STRING_C:.c=.o)

TARGET_DIR = ../build
TARGET1 = $(TARGET_DIR)/cipher


all: $(TARGET1) 


$(TARGET1): $(STRING_O) $(TEST)
	$(CC) $(CFLAGS) $(Q1_C) -o $(TARGET1)




cipher: $(TARGET1)




%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(TARGET1) *.o

rebuild: clean all

