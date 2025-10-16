#include "s21_string.h"

void s21_strlen_tests();
void s21_strcmp_tests();
void s21_strcpy_tests();
void s21_strcat_tests();
void s21_strchr_tests();
void s21_strstr_tests();

int main() {
#ifdef STRLEN
    s21_strlen_tests();
#elif STRCMP
    s21_strcmp_tests();
#elif STRCPY
    s21_strcpy_tests();
#elif STRCAT
    s21_strcat_tests();
#elif STRCHR
    s21_strchr_tests();
#elif STRSTR
    s21_strstr_tests();
#endif
    return 0;
}

void s21_strlen_tests() {
    printf("\"s21_strlen(\"Hello\")\" | = 5 | ");
    printf(s21_strlen("Hello") == 5 ? "SUCCESS\n" : "FAIL\n");

    printf("\"s21_strlen(\"\")\" | = 0 | ");
    printf(s21_strlen("") == 0 ? "SUCCESS\n" : "FAIL\n");

    printf("\"s21_strlen(\"Hello \\0 Hello\")\" | = 6 | ");
    printf(s21_strlen("Hello \0 Hello") == 6 ? "SUCCESS" : "FAIL");
}

void s21_strcmp_tests() {
    int res = s21_strcmp("abc", "abcd");
    printf("\"s21_strcmp(\"abc\", \"abcd\")\" | < 0 | ");
    printf(res < 0 ? "SUCCESS\n" : "FAIL\n");

    res = s21_strcmp("Hello", "Hello");
    printf("\"s21_strcmp(\"Hello\", \"Hello\")\" | = 0 | ");
    printf(res == 0 ? "SUCCESS\n" : "FAIL\n");

    res = s21_strcmp("", "Hello");
    printf("\"s21_strcmp(\"\", \"Hello\")\" | < 0 | ");
    printf(res < 0 ? "SUCCESS\n" : "FAIL\n");
}

void s21_strcpy_tests() {
    char new[20] = "NOTTRUE";
    s21_strcpy(new, "Hello");
    int res = s21_strcmp(new, "Hello");
    printf("new = NOTTRUE\n");
    printf("\"s21_strcpy(new, \"Hello\")\" | new == \"Hello\" | ");
    printf(res == 0 ? "SUCCESS\n" : "FAIL\n");

    s21_strcpy(new, "");
    res = s21_strcmp(new, "");
    printf("\"s21_strcpy(new, \"\")\" | new == \"\" | ");
    printf(res == 0 ? "SUCCESS\n" : "FAIL\n");

    s21_strcpy(new, "Hello \0 Hello");
    res = s21_strcmp(new, "Hello ");
    printf("\"s21_strcpy(new, \"Hello \\0 Hello\")\" | new == \"Hello \" | ");
    printf(res == 0 ? "SUCCESS\n" : "FAIL\n");
}

void s21_strcat_tests() {
    char new[20] = "first + ";
    s21_strcat(new, "second");
    int res = s21_strcmp(new, "first + second");
    printf("new = \"first + \"\n");
    printf("\"s21_strcat(new, \"second\")\" | new == \"first + second\" | ");
    printf(res == 0 ? "SUCCESS\n" : "FAIL\n");

    char new_1[20] = "first + ";
    s21_strcat(new_1, "");
    res = s21_strcmp(new_1, "first + ");
    printf("new_1 = \"first + \"\n");
    printf("\"s21_strcat(new_1, \"\")\" | new_1 == \"first + \" | ");
    printf(res == 0 ? "SUCCESS\n" : "FAIL\n");

    char new_2[20] = "first + ";
    s21_strcat(new_2, "Hello\0Hello");
    res = s21_strcmp(new_2, "first + Hello");
    printf("new_2 = \"first + \"\n");
    printf("\"s21_strcat(new_2, \"Hello\\0 Hello\")\" | new_2 == \"first + Hello\" | ");
    printf(res == 0 ? "SUCCESS\n" : "FAIL\n");
}

void s21_strchr_tests() {
    char new[20] = "Hello";
    char *res = s21_strchr(new, 'l');
    printf("new = \"Hello\"\n");
    printf("\"s21_strchr(new, \"l\")\" | = 2 | ");
    printf(res == &new[2] ? "SUCCESS\n" : "FAIL\n");

    char new_1[20] = "Hello World";
    char *res_1 = s21_strchr(new_1, ' ');
    printf("new_1 = \"Hello World\"\n");
    printf("\"s21_strchr(new_1, \" \")\" | = 5 | ");
    printf(res_1 == &new_1[5] ? "SUCCESS\n" : "FAIL\n");

    char new_2[20] = "Hello \0 Bobr";
    char *res_2 = s21_strchr(new_2, 'b');
    printf("new = \"Hello \\0 Bobr\"\n");
    printf("\"s21_strchr(new, \"b\")\" | = NULL | ");
    printf(res_2 == NULL ? "SUCCESS\n" : "FAIL\n");
}

void s21_strstr_tests() {
    char *new = "Hello";
    char *res = s21_strstr(new, "llo");
    printf("new = \"Hello\"\n");
    printf("\"s21_strstr(new, \"llo\")\" | = 2 | ");
    printf(res == &new[2] ? "SUCCESS\n" : "FAIL\n");

    char *new_1 = "Hello World";
    char *res_1 = s21_strstr(new_1, "QQ");
    printf("new_1 = \"Hello World\"\n");
    printf("\"s21_strstr(new_1, \"QQ\")\" | = NULL | ");
    printf(res_1 == NULL ? "SUCCESS\n" : "FAIL\n");

    char *new_2 = "Hello \0 Bobr";
    char *res_2 = s21_strstr(new_2, "");
    printf("new = \"Hello \\0 Bobr\"\n");
    printf("\"s21_strstr(new, \"\")\" | = 0 | ");
    printf(res_2 == &new_2[0] ? "SUCCESS\n" : "FAIL\n");
}