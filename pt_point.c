#include "main.h"

/**
 * hex_swich - Convert unsigned long integer
 * to hexadecimal.
 * @long_num: unsigned long integer
 * @p_size: pointer size
 * Return: s pointer of binary allocated memory
*/

char *hex_swich(unsigned long long_num, int p_size)
{
	char hex_num, *str;
	int i, remi;

	str = malloc((p_size + 1) * sizeof(char));

	if (str == NULL)
		return (str);

	for (i = p_size - 1; i >= 0; i--)
	{
		remi = long_num % 16;

		if (remi > 9)
			hex_num = (remi - 10) + 'a';
		else
			hex_num = remi + '0';

		str[i] = hex_num;
		long_num = long_num / 16;
	}

	str[p_size] = '\0';
	return (str);
}


/**
 * pt_pointer - print hexadecimal.
 * @args: variadic arguments
 * Return: no. of characters printed
*/
int pt_pointer(va_list args)
{
	char *str;
	int no_chars_ptd = 0;
	int counter_dig = 0;
	unsigned long long_num, temp;

	long_num = (unsigned long) va_arg(args, void *);

	if (long_num == 0)
	{
		no_chars_ptd += write(STDOUT_FILENO, "(nil)", 5);
		return (no_chars_ptd);
	}
	no_chars_ptd += write(STDOUT_FILENO, "0x", 2);
	temp = long_num;

	while (temp != 0)
	{
		temp = temp / 16;
		counter_dig++;
	}

	str = hex_swich(long_num, counter_dig);

	if (str == NULL)
		return (0);

	no_chars_ptd = write(STDOUT_FILENO, str, counter_dig);

	free(str);

	return (no_chars_ptd + 2);

}
