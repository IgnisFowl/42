int		max(int* tab, unsigned int len)
{
    int max;
    int i = 0;
    if(!tab || !len)
        return (0);
    max = tab[0];
    while(i < len)
    {
        if (tab[i] > max)
            max = tab[i];
        i++;
    }
    return (max);
}
