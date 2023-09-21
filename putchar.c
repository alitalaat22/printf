#include <unistd.h>
/**
 * my_putchar - Function prints char
 * @s: Char to printe
 * Return: Char
 */
int my_putchar(char s)
{
return (write(1, &s, 1));

}
