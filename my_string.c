#include "main.h"

/**
* my_string - a function to s handle
* @args: argument
* Return: num of chars
*/
int my_string(va_list args)
{
char *ptr = va_arg(args, char *);
int counter = 0;
int index = 0;

if (ptr == NULL)
{
ptr = "(null)";
}
while (ptr[index])
{
counter = counter + my_putchar(ptr[index]);
index++;
}
return (counter);
}
