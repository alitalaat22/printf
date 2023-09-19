#include "main.h"
/**
 * first_parameters - a struct to inital parameters
 * @p: parameters
 * @ptr: the argument to be followed by pointer
 * Return: nothing
 */
void first_parameters(my_parameters *p, va_list ptr)
{
p->flag_minus = 0;
p->spec_width = 0;
p->flag_unsign = 0;
p->flag_plus = 0;
p->flag_space = 0;
p->flag_hash = 0;
p->flag_zero = 0;
p->short_mod = 0;
p->long_mod = 0;
p->spec_precision = UINT_MAX;
/* to avoid not using it */
(void)ptr;
}
