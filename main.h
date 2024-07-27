#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int _printf(const char *format, ...);
int print_prg(va_list __attribute__((unused)), char *, unsigned int);
int print_chr(va_list arguments, char *buf, unsigned int ibuf);
int print_str(va_list arguments, char *buf, unsigned int ibuf);
int print_int(va_list arguments, char *buf, unsigned int ibuf);
int _putchar(char c);
unsigned int handle_int(char *buf, int num, unsigned int ibuf);
unsigned int handle_string(char *buf, char *str, unsigned int ibuf);
unsigned int handl_buf(char *buf, char c, unsigned int ibuf);


#endif /* MAIN_H */
