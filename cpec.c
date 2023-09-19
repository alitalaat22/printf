#include "main.h"
/**
 * obtain_specifier - finds the format func
 * @str: the format string
 * Return: num of bytes
*/
int (*obtain_specifier(char *str))(va_list ptr, my_parameters * params)
{
spec_t specifiers[] = {
{"c", print_character},
{"d", print_integer},
{"o", octal},
{"u", p_unsigned},
{"x", hex_print},
{"i", print_integer},
{"s", string},
{"%", percent},
{"b", binary},
{"X", hexa_print},
{"p", p_add},
{"S", s_print},
{"r", reverse},
{"R", rot13_ch},
{NULL, NULL}
};
int index = 0;

while (specifiers[index].specifier)
{
if (*str == specifiers[index].specifier[0])
{
return (specifiers[index].f);
}
index++;
}
return (NULL);
}
/**
 * obtain_print - function that finds the format func
 * @str: format string
 * @ptr: argument
 * @params: the parameters
 * Return: the num of bytes
 */
int obtain_print(char *str, va_list ptr, my_parameters *params)
{
int (*f)(va_list, my_parameters *) = obtain_specifier(str);

if (f)
{
return (f(ptr, params));
}
return (0);
}

/**
 * obtain_flag - a function to get flag func
 * @str: the format
 * @params: the parameters struct
 * Return: flag
 */
int obtain_flag(char *str, my_parameters *params)
{
int index = 0;

switch (*str)
{
case '-':
index = params->flag_minus = 1;
break;
case '0':
index = params->flag_zero = 1;
break;
case '+':
{
index = params->flag_plus = 1;
}
break;
case ' ':
{
index = params->flag_space = 1;
}
break;
case '#':
index = params->flag_hash = 1;
break;
}
return (index);
}

/**
 * obtain_width - function that gets the width
 * @str: the format string
 * @params: parameters
 * @ptr: arguments
 * Return: modern pointer
 */
char *obtain_width(char *str, my_parameters *params, va_list ptr)
{
int index = 0;

if (*str == '*')
{
index = va_arg(ptr, int);
str++;
}
else
{
while (_isdigit(*str))
{
index = index * 10 + (*str++ - '0');
}
}
params->spec_width = index;
return (str);
}

/**
 * obtain_modifier - function that finds the modifier func
 * @str: the format string
 * @params: the parameter
 * Return: modifier
 */
int obtain_modifier(char *str, my_parameters *params)
{
int index = 0;

switch (*str)
{
case 'h':
{
index = params->short_mod = 1;
}
break;
case 'l':
{
index = params->long_mod = 1;
}
break;
}
return (index);
}
