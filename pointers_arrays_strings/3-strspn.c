#include "main.h"

/**
 * _strspn - gets the length of a prefix substring
 * @s: the string to check
 * @accept: the bytes allowed in the prefix
 *
 * Return: the number of bytes at the start of s that are all in accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int count;
	int i;
	int found;

	count = 0;
	while (s[count] != '\0')
	{
		found = 0;
		for (i = 0; accept[i] != '\0'; i++)
		{
			if (s[count] == accept[i])
			{
				found = 1;
				break;
			}
		}
		if (!found)
			break;
		count++;
	}

	return (count);
}
