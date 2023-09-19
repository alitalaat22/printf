#include "main.h"
/**
 * obtain_precision - a function that gets the precision
 * @ptr: a pointer
 * @format: a pointer
 * @p: parameters
 * Return: new pointer
*/
char *obtain_precision(char *format, my_parameters *p, va_list ptr)
{
int precision = 0;
char *index = format;

if (*index != '.')
{
return (index);
}
index++;

if (*index == '*')
{
precision = va_arg(ptr, int);
index++;
}
else
{
while (_isdigit(*index))
{
precision = precision * 10 + (*index - '0');
index++;
}
}
p->spec_precision = precision;
return (index);
}
