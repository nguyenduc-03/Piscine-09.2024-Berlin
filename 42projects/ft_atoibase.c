#include <stdio.h>

int ft_strlen(char *str)
{

	int i = 0;
	while(str[i] != 0)
		i++;
	return i;
}

int is_valid(char *base)
{
	int i =0 ;
	if (!base || ft_strlen(base) < 2)
		return 0;
	while (base[i] != '\0')
	{
		if(base[i] == '+' || base[i] == '-' || base[i] == ' ')
			return 0;
		int j = i + 1;
		while(base[j])
		{
			if(base[i] == base[j])
				return 0;
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	if (!is_valid(base))
		return 0;
	int lenbase = ft_strlen(base);
	int i = 0;
	int result=0;
	int sign = 1;
        while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
        {
                i++;
        }
        while (str[i] == '+' || str[i] == '-')
        {
                if (str[i] == '-')
                        sign = -sign;
                i++;
        }
	// which position is the str in the base
	while(str[i] != '\0')
	{
	int j = 0;
		while(str[i] != base[j])
		{		
			j++; // j  = the position from str in base
		}
	result = (result * lenbase) + j ;
	i++;
	}
	return (result *sign);
}


int main()
{

	char *base = "0123456789abcdef";
	char *str = "ff";
	printf("%d\n", ft_atoi_base(str,base));
	return 0;
}
