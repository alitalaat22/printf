#include "main.h"
/**
 * reverse - a function to print the reverse
 * @ptr: a pointer to the string
 * @p: parameters
 * Return: sum of bytes
 */
int reverse(va_list ptr)
{
int length_string;
int result = 0;
char *pointer = va_arg(ptr, char *);

if (pointer)
{
for (length_string = 0; *pointer; pointer++)
{
length_string++;
}
pointer--;
for (; length_string > 0; length_string--, pointer--)
{
result = result + my_putchar(*pointer);
}
}
return (result);
}
