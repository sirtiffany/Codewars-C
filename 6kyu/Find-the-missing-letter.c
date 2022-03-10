
void	lowercase(char *array, int length)
{
	int i;

	i = 0;
	while(i != length)
	{
		if (('A' <= array[i]) && (array[i] <= 'Z'))
		{
			array[i] = (array[i] - 'A') + 'a';
		}
		i++;
	}
}

int	find_start(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] == s2[0])
		{
			break ;
		}
		i++;
	}
	return (i);
}

char	findMissingLetter(char array[], int arrayLength)
{
	int i;
	int x;
	int b;
	char alpha[] = "abcdefghijklmnopqrstuvwxyz";	

	i = 0;
	x = 0;
	b = 0;
	if (('A' <= array[0]) && (array[0] <= 'Z')) //check if input is lower- or upercase
	{
		b = 1;
	}
	lowercase(array, arrayLength); //change input to always lowercase
	i = find_start(alpha, array); //find from which letter my input starts (in the alphabet)
	while (alpha[i]) //go through each letter and check if its found in the input
	{
		while (x != arrayLength)// check if the given letter is in my input
		{
			if (alpha[i] == array[x]) //if the letter is found, it will reset my inputs array index and break the loop
			{
				x = 0;
				break ;
			}
			x++;
		}
		if (x > 0) //if no letter was found then my my index would have never reseted so it will be bigger than 0
		{
			break ;
		}
		i++;
	}
	if (b > 0) //if the input was actually upercase then transform my output accordingly
	{
		alpha[i] = (alpha[i] - 'a') + 'A';
	}
	return (alpha[i]); //return the letter
}
