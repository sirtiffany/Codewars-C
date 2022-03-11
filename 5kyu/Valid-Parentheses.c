#include <stdbool.h>
#include <stdlib.h>

void	cpypar(char *dest, const char *src)
{
	int i;
	int x;

	i = 0;
	x = 0;
	while (src[i])
	{
		if (src[i] == '(' || src[i] == ')')
		{
			dest[x] = src[i];
			x++;
		}
		i++;
	}
	dest[x++] = '\0';
}

bool	validParentheses(const char *str_in)
{
	int i;
	int count;

	i = 0;
	count = 0;
	char *par = malloc(sizeof(str_in)/sizeof(char));
	cpypar(par, str_in);	//save all my parentheses in order in a different string
	if (par[0] == ')')	//if it starts with closing parentheses then it is false.
	{
		return (false);
	}
	while(par[i])
	{
		if (count == 0) //if my parentheses close out (count = 0) then check that the next one doesn't start with a closing parentheses
		{
			if (par[i] == ')')
			{
				return (false);
			}
		}
		if (par[i] == '(') //this and the lines below add the amount of open parentheses and substract the amount of closing ones.
		{
			count++;
		}
		if (par[i] == ')')
		{
			count--;
		}
		i++;
	}
	if (count != 0) //count should always be 0 if all my parentheses close out; bigger than 0 if there are closing parentheses missing and smaller than 0 if there are opening parentheses missing
	{
		return(false);
	}
	return (true);
}