#ifndef CIPHER_H
#define CIPHER_H

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_file(int *flag, char *filepath);
void write_file(int *flag, char *filepath);
char caesar(char c, int shift);
void shift_for_dir(int *flag);

#endif