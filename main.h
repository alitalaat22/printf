#ifndef _PRINTF_H
#define _PRINTF_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <stddef.h>

#define out_size_buffer 1024
#define flush -1
#define NULL_STRING "(null)"
#define f_par {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2
/**
 * struct parameters - parameters
 * @flag_unsign: unsigned
 * @flag_plus: plus_flag spec
 * @flag_space: hashtag_flag spec
 * @flag_hash: flag spec
 * @flag_zero: flag spec
 * @flag_minus: flag spec
 * @spec_width: field width spec
 * @spec_precision: field precision spec
 * @short_mod: h_modifier is spec
 * @long_mod: l_modifier is spec
 */
typedef struct parameters
{
unsigned int flag_unsign	: 1;
unsigned int flag_plus		: 1;
unsigned int flag_space		: 1;
unsigned int flag_hash		: 1;
unsigned int flag_zero		: 1;
unsigned int flag_minus		: 1;
unsigned int spec_width;
unsigned int spec_precision;
unsigned int short_mod		: 1;
unsigned int long_mod		: 1;
} my_parameters;

/**
 * struct specifier - Struct
 * @specifier: format
 * @f: The function associated
 */
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, my_parameters *);
} spec_t;

int my_puts(char *ptr);
int my_putchar(int c);
int print_character(va_list ptr, my_parameters *p);
int print_integer(va_list ptr, my_parameters *p);
int string(va_list ptr, my_parameters *params);
int percent(va_list ptr, my_parameters *params);
int s_print(va_list ptr, my_parameters *params);
char *convert(long int num, int base, int flags, my_parameters *params);
int p_unsigned(va_list ap, my_parameters *params);
int p_add(va_list ap, my_parameters *params);
int (*obtain_specifier(char *str))(va_list ptr, my_parameters *params);
int obtain_print(char *str, va_list ptr, my_parameters *params);
int obtain_flag(char *str, my_parameters *params);
int obtain_modifier(char *str, my_parameters *params);
char *obtain_width(char *str, my_parameters *params, va_list ptr);
int hex_print(va_list ptr, my_parameters *params);
int hexa_print(va_list ptr, my_parameters *params);
int binary(va_list ptr, my_parameters *params);
int octal(va_list ptr, my_parameters *params);
int range_print(char *begin, char *end, char *without);
int reverse(va_list ptr, my_parameters *p);
int rot13_ch(va_list ptr, my_parameters *p);
int _isdigit(int c);
int _strlen(char *s);
int print_num(char *str, my_parameters *params);
int print_right(char *str, my_parameters *params);
int print_left(char *str, my_parameters *params);
void first_parameters(my_parameters *p, va_list ptr);
char *obtain_precision(char *format, my_parameters *p, va_list ptr);
int _printf(const char *format, ...);

#endif /* PRINTF_H */
