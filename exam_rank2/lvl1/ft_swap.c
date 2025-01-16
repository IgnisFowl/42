void	ft_swap(int *a, int *b)
{
	int temp = *a; //store the value of a
	*a = *b; //assign the value of b to a
	*b = temp; //assign the stored value of a to b
}