#include "cipher.h"

int main() {
    int flag = 1, num = 0;
    char c = 0;
    char *filepath = malloc(sizeof(char) * 200);
    while (1 && flag != 2) {
        if (scanf("%d%c", &num, &c) != 2 || (c != ' ' && c != '\n')) {
            flag = 0;
        }
        if (flag) {
            if (num == 1) {
                read_file(&flag, filepath);
            } else if (num == -1) {
                flag = 2;
            } else if (num == 2) {
                write_file(&flag, filepath);
            } else if (num == 3) {
                shift_for_dir(&flag);
            } else {
                printf("n/a\n");
            }
        }
    }
    free(filepath);
    return 0;
}

void read_file(int *flag, char *filepath) {
    if (fgets(filepath, 200, stdin) == NULL) {
        *flag = 0;
        printf("n/a");
    }
    if (*flag) {
        char *pos = strchr(filepath, '\n');
        *pos = '\0';
        FILE *file = fopen(filepath, "r");
        if (file == NULL) {
            *flag = 0;
            printf("n/a\n");
        }
        if (*flag) {
            int c = 0;
            int point = 0;
            while (*flag && (c = fgetc(file)) != EOF) {
                putchar(c);
                point = 1;
            }
            if (point) {
                printf("\n");
            } else {
                printf("n/a\n");
            }
        }
        if (file != NULL) {
            fclose(file);
        }
    }
    *flag = 1;
}

void write_file(int *flag, char *filepath) {
    if (*flag) {
        char *input = malloc(sizeof(char) * 200);
        if (input != NULL) {
            fgets(input, 200, stdin);
            char *pos = strchr(input, '\n');
            *pos = '\0';
        }
        if (input == NULL) {
            flag = 0;
            printf("n/a\n");
        }
        if (strlen(filepath) == 0) {
            *flag = 0;
            printf("n/a\n");
        }
        if (*flag) {
            FILE *file = fopen(filepath, "r");
            if (file != NULL) {
                fclose(file);
            } else {
                *flag = 0;
                printf("n/a\n");
            }
            FILE *file2 = fopen(filepath, "a");
            fprintf(file2, "%s", input);
            fclose(file2);
        }
        free(input);
    }
    if (*flag) {
        FILE *file = fopen(filepath, "r");
        int c = 0;
        while (*flag && (c = fgetc(file)) != EOF) {
            putchar(c);
        }
        fclose(file);
        printf("\n");
    }
    *flag = 1;
}

char caesar(char c, int shift) {
    if (c >= 'a' && c <= 'z') {
        return ((c - 'a' + shift) % 26 + 26) % 26 + 'a';
    } else if (c >= 'A' && c <= 'Z') {
        return ((c - 'A' + shift) % 26 + 26) % 26 + 'A';
    }
    return c;
}

void shift_for_dir(int *flag) {
    char *dirpath = malloc(sizeof(char) * 200);
    int shift = 0;
    char c = 0;
    if (fgets(dirpath, 200, stdin) == NULL) {
        *flag = 0;
        printf("n/a\n");
    }
    if (*flag) {
        char *pos = strchr(dirpath, '\n');
        *pos = '\0';
        if (scanf("%d%c", &shift, &c) != 2) {
            printf("n/a\n");
            *flag = 0;
        }
    }
    if (*flag) {
        DIR *dir = opendir(dirpath);
        if (dir == NULL) {
            printf("n/a\n");
            *flag = 0;
        }
        if (*flag) {
            struct dirent *input_file;
            while ((input_file = readdir(dir)) != NULL) {
                char *filepath = malloc(sizeof(char) * 400);
                snprintf(filepath, 10000, "%s/%s", dirpath, input_file->d_name);
                char *dot = strrchr(input_file->d_name, '.');
                if (dot != NULL) {
                    if (strcmp(dot, ".c") == 0) {
                        FILE *file = fopen(filepath, "r");
                        char *code = malloc(1000);
                        int i = 0, ch = 0;
                        while ((ch = fgetc(file)) != EOF) {
                            code[i++] = ch;
                        }
                        code[i] = '\0';
                        fclose(file);
                        for (int j = 0; j < i; j++) {
                            code[j] = caesar(code[j], shift);
                        }
                        file = fopen(filepath, "w");
                        fwrite(code, 1, i, file);
                        fclose(file);
                        free(code);
                    } else if (strcmp(dot, ".h") == 0) {
                        FILE *file = fopen(filepath, "w");
                        fclose(file);
                    }
                }
                free(filepath);
            }
        }
        closedir(dir);
    }
    free(dirpath);
    *flag = 1;
}