#include "main.h"

/**
 * get_percision - get the percision from format string
 * @s: string format
 * @params: struct parameters
 * @ap: pointer arguments
 * Return: new pointer
 */

char *get_precision(char *p, params_t *params, va_list ap)
{
	int n = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		n = va_arg(ap, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
		{
			n = n * 10 + (*p++ - '0');
		}

	}
	params->precision = n;
	return (p);
}
