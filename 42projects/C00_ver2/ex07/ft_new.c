#include <unistd.h>

void	ft_putnbr(int nb)
{
	if( nb == -2147483648)
		write(1,"-2147483648\n",12);
	char a;
	if (nb < 0)
		{write(1, "-",1);
		nb = -nb ;}

	if(nb >= 10){
	ft_putnbr(nb/10);
	
	}
	a = nb%10 +  48;	
	write(1,&a,1);

}

int main()
{
	ft_putnbr(42);
	return 0;
}

