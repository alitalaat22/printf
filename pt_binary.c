#include "main.h"

/**
 * binary_switch - Convert unsigned intger to binary.
 * @int_num: unsigned int number
 * @binary_size: binary number size
 * Return: s pointer of binary allocated memory
*/
char *binary_switch(unsigned int int_num, int binary_size)
{
	char *str, binary_num;
	int y, remi;

	str = malloc(sizeof(char) * (binary_size + 1));
	if (str == NULL)
		return (str);
	for (y = binary_size - 1; y >= 0 ; y--)
	{
		remi = int_num % 2;
		binary_num = '0' + remi;
		str[y] = binary_num;
		int_num = int_num / 2;
	}

	str[binary_size] = '\0';
	return (str);
}


/**
 * pt_binary - print binary representation given unsigned integer.
 * @args: variadic arguments
 * Return: no. of binary (success)
*/
int pt_binary(va_list args)
{
	unsigned int int_num, temp, binary_counter;
	char *str, binary_num;

	int_num = va_arg(args, unsigned int);
	temp = int_num;
	binary_counter = 0;

	if (int_num == 0 || int_num == 1)
	{
		binary_num = int_num + '0';
		its_put(binary_num);
		return (1);
	}

	while (temp != 0)
	{
		temp = temp / 2;
		binary_counter++;
	}
	str = binary_switch(int_num, (binary_counter));
	if (str == NULL)
		return (0);

	binary_counter =  write(STDOUT_FILENO, str, binary_counter);
	free(str);

	return (binary_counter);
}
