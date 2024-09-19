#include <unistd.h>
int ft_strncmp(char *s1, char *s2, unsigned int n)
{
    unsigned int    i;
    i = 0;
    while (((s1[i] - s2[i]) == 0) && s1[i] && s2[i] && i < n)
    {
        i++;
        if (i == n)
        {
            return (s1[i - 1] - s2[i - 1]);
        }
    }
    return (s1[i] - s2[i]);
}
#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
    int n;
    if (argc == 3)
    {
        n = ft_strncmp(argv[1], argv[2], 5);
        printf("Return = %i\n", n);
        n = strncmp(argv[1], argv[2], 5);
        printf("Return = %i", n);
    }
    return (0);
}