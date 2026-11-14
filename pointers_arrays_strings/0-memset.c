#include "main.h"

/**
 * _memset - fills the first n bytes of a memory area with a constant byte
 * @s: the memory area to fill
 * @b: the byte to write
 * @n: the number of bytes to fill
 *
 * Return: a pointer to s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;

	return (s);
}
