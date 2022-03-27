
#include <string.h>
#include <stdlib.h>

void	ft_rev(char *tab, int size) //function to revert a string;
{
	int		size2;
	char	nr;

	size2 = 0;
	nr = 0;
	size = size - 1;
	while (size2 < size)
	{
		nr = tab[size];
		tab[size] = tab[size2];
		tab[size2] = nr;
		size2++;
		size--;
	}
}

char	*strsum(const char *a, const char *b)
{
	int a_index;
	int b_index;
	int i;
	int n;
	int next;
	int nbr;
	char *res;
	char *res2;

	i = 0;
	a_index = 0;
	b_index = 0;
	next = 0;
	nbr = 0;
	res = 0;
	res2 = 0;
  	n = 0;
	while (a[i])	//check how many numbers each string has (-1 for the 0 terminator)
	{
		i++;
	}
	a_index = i - 1;
	i = 0;
	while (b[i])
	{
		i++;
	}
	b_index = i - 1;
	i = 0;
	if (a_index > b_index) //if my number a is bigger than number b
	{
		res = malloc((a_index + 2)); //create space of memory for the amount of digits the biggest number has + 1 if number is made out of 9s only and + 1 for the 0 terminator
		res2 = malloc((a_index + 2));
		while (b_index > -1) 
		{
			nbr = (a[a_index] - '0') + (b[b_index] - '0'); //first turn number into an actual int
			nbr += next; //add up the "rest" from my last addition (at the beginning is 0)
			if (nbr > 9) //if my number is bigger than 0 then save my right digit and put the left digit into the variable "next"
			{
				res[i] = (nbr % 10) + '0';
				next = nbr / 10;
			}
			else
			{
				res[i] = nbr + '0'; 
				next = 0;
			}
			a_index--;
			b_index--;
			i++;
		}
		while (a_index > -1) //this is for when the addition is completed and there are digits left to copy from the number a
		{
			nbr = (a[a_index] - '0') + next; //if last addition had a "rest" otherwise "next" will be 0
			if (nbr > 9) //if my addition made a number bigger than 0 then continue the addition 
			{
				res[i] = (nbr % 10) + '0';
				next = nbr / 10;
			}
			else
			{
				res[i] = nbr + '0';
				next = 0;
			}
			i++;
			a_index--;
		}
		if (next > 0) //add the "rest" of my addition if there is any
		{
			res[i++] = next + '0';
		}
		
	}
	else if (b_index > a_index || (b_index == a_index && (b_index > 0 && a_index > 0))) // same as before but in this case if number b is bigger than a and also if 
	{																					// number a and b are the same size and are not empty
		res = malloc((b_index + 2));
		res2 = malloc((b_index + 2));
		while (a_index > -1)
		{
			nbr = (a[a_index] - '0') + (b[b_index] - '0');
			nbr += next;
			if (nbr > 9)
			{
				res[i] = (nbr % 10) + '0';
				next = nbr / 10;
			}
			else
			{
				res[i] = nbr + '0';
				next = 0;
			}
			a_index--;
			b_index--;
			i++;
		}
		while (b_index > -1)
		{
			nbr = (b[b_index] - '0') + next;
			if (nbr > 9)
			{
				res[i] = (nbr % 10) + '0';
				next = nbr / 10;
			}
			else
			{
				res[i] = nbr + '0';
				next = 0;
			}
			i++;
			b_index--;
		}
		if (next > 0)
		{	
			res[i++] = next + '0';
		}
	}
	ft_rev(res, i); //reverse my number to have it in the correct order
	res[i] = 0; //add 0 terminator
	i = 0;
	n = 0;
	while (res[i] == '0') //if there were any unnecessary 0s (i amount of 0s infront of the actual number)
	{
		i++;
	}
	while (res[n])
	{
		n++;
	}
	if (i == n) //this is for the scenario of the sum of 0 + 0 if one of the numbers was represented with an i unnecessary amount of 0s (e.g. 00000 + 0)
	{
		i = i - 1;
	}
	n = 0;
	while (res[i]) //copy to res2 starting from where there are no unnecessary 0s
	{
		res2[n] = res[i];
		i++;
		n++;
	}
	res2[n] = 0; //add 0 terminator
	return res2;
}
