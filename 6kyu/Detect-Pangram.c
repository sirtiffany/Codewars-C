
#include <stdbool.h>

void	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char	*turn_to_lower(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (('A' <= str[i]) && (str[i] <= 'Z'))
		{
			str[i] = (str[i] - 'A') + 'a';
		}
		i++;
	}
	return (str);
}

bool	is_pangram(const char *str_in)
{
	int i;
	int x;
	int count;
	char alpha[] = "abcdefghijklmnopqrstuvwxyz";
	char *copy = malloc(sizeof(str_in)/sizeof(char));

	i = 0;
	x = 0;
	count = 0;
	ft_strcpy(copy, str_in);  //copies input to a modifiable area of meemory
	turn_to_lower(copy);     //turns string to lowercase, because case is not important
	while (alpha[i])        //takes each letter of the alphabet and checks if it is found once in str_in
	{
		while (copy[x])
		{
			if (alpha[i] == copy[x])
			{
				count++;
				x = 0;
				break ;
			}
			x++;
		}
		i++;
	}
	if (count != 26)
	{
		return (false);
	}
	return (true);
}
