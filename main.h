#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

/* helpers functions */
int its_put(char x);
char *binary_switch(unsigned int int_num, int binary_size);
char *hex_switch(unsigned long long_num, int p_size);

/* print functions */
int pt_char(va_list args);
int pt_string(va_list args);
int pt_percent(va_list args);
int pt_int(va_list args);
int pt_binary(va_list args);
int pt_pointer(va_list args);
int (*func_spec(char x))(va_list args);
int _printf(const char *format, ...);
int rot13_ch(va_list args);

/**
 * struct specifier - structure
 * @letter: letter data type
 * @func: function pointer
*/
typedef struct specifier
{
	char letter;
	int (*func)(va_list);
} specifier_t;



#endif
