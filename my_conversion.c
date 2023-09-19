#include "main.h"
/**
 * hex_print - a function to print hex
 * @ptr: arguments
 * @params: parameters
 * Return: bytes printed
 */
int hex_print(va_list ptr, my_parameters *params)
{
/* declarition of varables */
unsigned long index;
char *str;
int count = 0;

if (params->long_mod)
{
index = (unsigned long)va_arg(ptr, unsigned long);
}
else if (params->short_mod)
{
index = (unsigned short int)va_arg(ptr, unsigned int);
}
else
{
index = (unsigned int)va_arg(ptr, unsigned int);
}

str = convert(index, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
/* check if flag_hash and index or not */
if (params->flag_hash && index)
{
*--str = 'x';
*--str = '0';
}
params->flag_unsign = 1;
return (count = count + print_num(str, params));
}

/**
 * hexa_print - a function that prints upper hex
 * @ptr: arguments
 * @params: parameters
 * Return: sum of bytes
 */
int hexa_print(va_list ptr, my_parameters *params)
{
unsigned long index;
char *str;
int count = 0;
/* check of parameter is l_modifier */
if (params->long_mod)
{
index = (unsigned long)va_arg(ptr, unsigned long);
}
else if (params->short_mod)
{
index = (unsigned short int)va_arg(ptr, unsigned int);
}
else
{
index = (unsigned int)va_arg(ptr, unsigned int);
}
/* to convert the char with hex uppercase format */
str = convert(index, 16, CONVERT_UNSIGNED, params);
if (params->flag_hash && index)
{
*--str = 'X';
*--str = '0';
}
params->flag_unsign = 1;
return (count = count + print_num(str, params));
}
/**
 * binary - a function that prints binary num
 * @ptr: argument
 * @params: parameters
 * Return: sum of bytes
 */
int binary(va_list ptr, my_parameters *params)
{
unsigned int num = va_arg(ptr, unsigned int);
char *str = convert(num, 2, CONVERT_UNSIGNED, params);
int counter = 0;

if (params->flag_hash && num)
{
*--str = '0';
}
params->flag_unsign = 1;
return (counter = counter + print_num(str, params));
}
/**
 * octal - a function that prints octal numbers
 * @ptr: arguments
 * @params: parameters
 * Return: sum of bytes
 */
int octal(va_list ptr, my_parameters *params)
{
/* declare the variables */
unsigned long index;
int counter = 0;
char *str;

/* check value of l_modifier */
if (params->long_mod)
{
index = (unsigned long)va_arg(ptr, unsigned long);
}
else if (params->short_mod)
{
index = (unsigned short int)va_arg(ptr, unsigned int);
}
else
{
index = (unsigned int)va_arg(ptr, unsigned int);
}
str = convert(index, 8, CONVERT_UNSIGNED, params);

if (params->flag_hash && index)
{
*--str = '0';
}
params->flag_unsign = 1;
return (counter = counter + print_num(str, params));
}
