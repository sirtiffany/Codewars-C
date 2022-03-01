#include <stddef.h>

size_t	get_count(const char *s)
{
	size_t	count;
	int		i;

	i = 0;
	count = 0;
	while (s[i] != 0)
	{
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o'
		|| s[i] == 'u')
		{
			count++;
		}
		i++;
	}
	return (count);
}
