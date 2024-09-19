#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char *ft_itoa(int nb)
{

	int i =0;


	if (nb == -2147483648)
	{
		return "-214783648" ;
	}
	if (nb < 0)
	{
		nb = -nb;
		i++;
	}
	int temp = nb;

	if (nb == 0)
		{
					char *str1 = (char *)malloc(2 * sizeof(char));
		str1[0] = '0';
		str1[1] = '\0';
		return str1;
		}
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}

	char *str = (char *)malloc(sizeof(char)* (i + 1));
	str[i] = '\0';
	i = i -1;
	while (i >= 0)
	{
		if(temp < 0)
			str[0] = '-';
		str[i] = (temp) % 10 +48;
		temp /= 10;
		i--;
	}
	return str;
}

int main()
{
	printf("%s\n", ft_itoa(123));
	return 0;
}

//just like putnumbr , but now using malloc to store ()
//caculate how long is the numb, then malloc, then %10 print it on to the last position, minus till the end