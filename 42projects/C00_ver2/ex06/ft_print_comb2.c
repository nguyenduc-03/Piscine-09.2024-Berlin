#include<unistd.h>

void ft_print_comb2(void){

    char a,b,c,d;
    
for(a='0';a<= '9';a++){
    for(b ='0'; b<='9';b++){
        for(c = a; c <= '9'; c++){
            for(d = (c == a ? b + 1 : '0'); d <= '9'; d++){
                

                write(1, &a, 1);
                write(1, &b, 1);
                write(1, " ",1);
                write(1, &c, 1);
                write(1, &d, 1);
                

                if (!(a== '9' && b== '8' && c== '9' && d == '9'))
                    {
                        write(1, ", ", 2);
                    }
                        }
                 }           
           }
    }
}

int main()
{   
    ft_print_comb2();
    return 0;
}