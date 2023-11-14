#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int _printf(const char *format, ...);
int binary (int num);
int octal(int num);

int _putchar(char c);
int _puts(char *str);

#endif
