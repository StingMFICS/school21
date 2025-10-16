#ifndef S21_STRING
#define S21_STRING
#include <stdio.h>
#include <stdlib.h>

size_t s21_strlen(const char *str);
int s21_strcmp(const char *str1, const char *str2);
char *s21_strcpy(char *new, const char *old);
char *s21_strcat(char *new, const char *old);
char *s21_strchr(const char *str, int n);
char *s21_strstr(const char *str1, const char *str2);
char *s21_strtok(char *str, char *delim);

#endif
