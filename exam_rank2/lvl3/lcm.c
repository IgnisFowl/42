unsigned int gcd(unsigned int a, unsigned int b)
{
	int temp = 0;
	if (a > 0 && b > 0)
	{
		while (b != 0)
		{
			temp = b;
			b = a % b;
			a = temp;
		}
	}
	return (a);
}

unsigned int    lcm(unsigned int a, unsigned int b)
{
	int temp = 0;
	if (a > 0 && b > 0)
	{
		return ((a / gcd(a, b)) * b);
	}
	else
		return (0);
}