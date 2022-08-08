#include <stdio.h>
#include "main.h"
#include <stdlib.h>
#include <stdarg.h>

/*tr_reverse - reverse a string
 * @ap: arg list
 *  * Return: number printed char
*/
 int print_str_reverse(va_list ap)
{
	char *argument = va_arg(ap, char *), *str;
	int size, left, limit, right, sum = 0;

	if (!argument)
	{
	sum += _puts("%r", 0);
	return (sum);
	}

	size = _strlen_recursion(argument);
	right = size - 1;
	limit = (size % 2 == 0) ? (size + 1) / 2 : (size / 2);

	str = malloc(sizeof(char) * size + 1);

	if (str == NULL)
	{
	return (0);
	}

	if (size % 2 != 0)
	{
	str[limit] = argument[limit];
	}

	for (left = 0; left < limit; left++)
	{
	str[left] = argument[right];
	str[right] = argument[left];
	right--;
	}

	str[size] = '\0';

	sum = _puts(str, 0);
	free(str);

	return (sum);
}
