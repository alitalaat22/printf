#include "main.h"
/**
* my_char - a function to c handle
* @args: arguments
* Return: counter of chars
*/
int my_char(va_list args)
{
char pointer = va_arg(args, int);

return (my_putchar(pointer));
}
