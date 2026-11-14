#include "main.h"

/**
 * is_separator - checks if a character separates words
 * @c: the character to check
 *
 * Return: 1 if c is a separator, 0 otherwise
 */
int is_separator(char c)
{
	char *sep;

	sep = " \t\n,;.!?\"(){}";
	while (*sep != '\0')
	{
		if (c == *sep)
			return (1);
		sep++;
	}

	return (0);
}

/**
 * cap_string - capitalizes all words of a string
 * @str: the string to change
 *
 * Return: a pointer to str
 */
char *cap_string(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z' &&
		    (i == 0 || is_separator(str[i - 1])))
			str[i] = str[i] - ('a' - 'A');
	}

	return (str);
}
