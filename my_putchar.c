#include "main.h"
/**
 * my_putchar - a functions to print character
 * @c: the input character
 * Return: 1 or -1 on error
 */
int my_putchar(int c)
{
static int index;
static char out_buffer[out_size_buffer];

if (c == flush || index >= out_size_buffer)
{
write(1, out_buffer, index);
index = 0;
}
if (c != flush)
{
out_buffer[index++] = c;
}
return (1);
}
