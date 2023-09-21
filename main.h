#ifndef printf_h
#define printf_h

#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>


int my_putchar(char c);
int _printf(const char *format, ...);
int my_char(va_list args);
int my_string(va_list args);
void p_integer(long int n, int *count, char flag, int is_start);
int my_integer(va_list args, char flag, char length_modifier);
int my_binary(va_list args);
int my_unsign_int(va_list args, char length);
int print_unsigned_int(unsigned int num);
int print_unsigned_long(unsigned long int num_l);
int print_unsigned_short(unsigned short int num_h);
int octal(va_list args, char flag, char length);
int my_octal(unsigned int num, char flag);
int my_short_octal(unsigned short int num_h, char flag);
int my_long_octal(unsigned long int num_l, char flag);
int hex_low(va_list args, char flag, char length);
int hex_up(va_list args, char flag, char length);
int my_hex(unsigned int num, int upper, char flag);
int short_hex(unsigned short int num_h, int upper, char flag);
int long_hex(unsigned long int num_l, int upper, char flag);
int my_specifier(char specifier, va_list args, char flag, char length);
int your_specifier(char specifier, va_list args, char flag, char length);
int print_hex(unsigned char c, char flag);
int custom_s(va_list args);
int my_pointer(va_list args);
int flag_and_specifier(const char **format, va_list args, int *count);

#endif

