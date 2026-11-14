#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: the string to convert
 *
 * Description: the number is built as a negative value so that
 * INT_MIN can be stored without overflow, then flipped if positive.
 * Return: the converted integer, or 0 if there are no digits
 */
int _atoi(char *s)
{
	int sign;
	int num;

	sign = 1;
	num = 0;

	while (*s != '\0' && (*s < '0' || *s > '9'))
	{
		if (*s == '-')
			sign = -sign;
		s++;
	}

	while (*s >= '0' && *s <= '9')
	{
		num = (num * 10) - (*s - '0');
		s++;
	}

	if (sign > 0)
		num = -num;

	return (num);
}
