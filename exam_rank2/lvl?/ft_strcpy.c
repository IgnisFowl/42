char    *ft_strcpy(char *s1, char *s2)
{
    int length = 0;
    int index = 0;

    while(s2[length] != '\0')
        length++;
    while(index < length)
    {
        s1[index] = s2[index];
        index++;
    }
    s1[index] = '\0';
    return(s1);
}
