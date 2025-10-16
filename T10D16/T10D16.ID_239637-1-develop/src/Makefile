CC = gcc

CFLAGS = -Wall -Wextra -Werror
STRING_C = s21_string.c
STRING_O = $(STRING_C:.c=.o)
TEST = s21_string_test.c

TARGET_DIR = ../build
TARGET1 = $(TARGET_DIR)/Quest_1
TARGET2 = $(TARGET_DIR)/Quest_2
TARGET3 = $(TARGET_DIR)/Quest_3
TARGET4 = $(TARGET_DIR)/Quest_4
TARGET5 = $(TARGET_DIR)/Quest_5
TARGET6 = $(TARGET_DIR)/Quest_6


all: $(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4) $(TARGET5) $(TARGET6)


$(TARGET1): $(STRING_O) $(TEST)
	$(CC) $(CFLAGS) -D STRLEN $(STRING_C) $(TEST) -o $(TARGET1)

$(TARGET2): $(STRING_O) $(TEST)
	$(CC) $(CFLAGS) -D STRCMP $(STRING_O) $(TEST) -o $(TARGET2)

$(TARGET3): $(STRING_O) $(TEST)
	$(CC) $(CFLAGS) -D STRCPY $(STRING_O) $(TEST) -o $(TARGET3)

$(TARGET4): $(STRING_O) $(TEST)
	$(CC) $(CFLAGS) -D STRCAT $(STRING_O) $(TEST) -o $(TARGET4)

$(TARGET5): $(STRING_O) $(TEST)
	$(CC) $(CFLAGS) -D STRCHR $(STRING_O) $(TEST) -o $(TARGET5)

$(TARGET6): $(STRING_O) $(TEST)
	$(CC) $(CFLAGS) -D STRSTR $(STRING_O) $(TEST) -o $(TARGET6)



strlen_tests: $(TARGET1)

strcmp_tests: $(TARGET2)

strcpy_tests: $(TARGET3)

strcat_tests: $(TARGET4)

strchr_tests: $(TARGET5)

strstr_tests: $(TARGET6)



%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(TARGET1) $(TEST_O) $(STRING_O) $(TARGET2) $(TARGET3) $(TARGET4) $(TARGET5) $(TARGET6)

rebuild: clean all

