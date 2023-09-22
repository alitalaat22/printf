#include "main.h"
/**
* my_string - a function to s handle
* @args: arguments
* Return: num of chars
*/
int my_string(va_list args)
{
int counter = 0;
int index;
char *ptr = va_arg(args, char *);

if (!ptr)
{
ptr = "(null)";
}
for (index = 0; ptr[index]; index++)
{
counter = counter + my_putchar(ptr[index]);
}
return (counter);
}
