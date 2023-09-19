#include "main.h"
/**
 * range_print - a function to print the range
 * @begin: begin address
 * @end: end address
 * @without: without specific address
 * Return: sum of bytes
 */
int range_print(char *begin, char *end, char *without)
{
int result = 0;

for ( ; begin <= end; begin++)
{
if (begin != without)
result = result + my_putchar(*begin);
}
return (result);
}
/**
 * reverse - a function to print the reverse
 * @ptr: a pointer to the string
 * @p: parameters
 * Return: sum of bytes
 */
int reverse(va_list ptr, my_parameters *p)
{
int length_string;
int result = 0;
char *pointer = va_arg(ptr, char *);
(void)p;

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
