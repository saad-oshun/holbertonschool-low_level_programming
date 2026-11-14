#include "main.h"

/**
 * leet - encodes a string into 1337
 * @str: the string to encode
 *
 * Description: each letter in "aAeEoOtTlL" is replaced by the
 * digit at the same position in "4433007711".
 * Return: a pointer to str
 */
char *leet(char *str)
{
	char *letters;
	char *digits;
	int i;
	int j;

	letters = "aAeEoOtTlL";
	digits = "4433007711";

	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; letters[j] != '\0'; j++)
		{
			if (str[i] == letters[j])
				str[i] = digits[j];
		}
	}

	return (str);
}
