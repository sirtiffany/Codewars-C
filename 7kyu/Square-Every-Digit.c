unsigned long long	reversed (unsigned long long res)
{
	unsigned int		x;
	unsigned long long	rvs;
	
	x = 0;
	rvs = 0;
	while (res > 0)
	{
		x = res % 10;
		rvs = (rvs * 10) + x;
		res /= 10;
	}
	return (rvs);
}

unsigned long long	square_digits (unsigned n) //it only takes positive numbers as input; this is how the task was promted
{
	unsigned long long	res;  // result
	unsigned long long	ans;  // save reversed result(actual answer)
	unsigned int		save; //save my input
	unsigned int		a;
	unsigned int		z;
	unsigned int		b;
	
	a = 0;
	res = 0;
	z = 0;
	b = 0;
	ans = 0;
	save = n;
	while (n > 0)
	{
		a = n % 10;
		z = a * a;
		if (z > 9)  //if my squared number is > than 1 digit, break it down to each digit 
		{
			while ( z > 0)
			{
				b = z % 10;
				res = (res * 10) + b;
				z /= 10;
			}
		}
		else
		{
			res = (res * 10) + (a*a);
		}
		n /= 10;
	}
	ans = reversed(res);
	while ((save % 10 == 0) && save > 0) //if there are any zeros at the end of my number, they will get lost by the way I add the numebers in res, so I compensate those zeros afterwards 
	{
		ans *= 10;
		save /= 10;
	}
	return (ans);
}
