#include "main.h"
/**
 * my_puts - a function to print every ch of string
 * @ptr: pointer to loop all string
 * Return: length of the sring except null
 */
int my_puts(char *ptr)
{
int counter = 0;

while (*ptr)
{
my_putchar(*ptr);
counter++;
ptr++;
}
counter++;
return (counter);
}
