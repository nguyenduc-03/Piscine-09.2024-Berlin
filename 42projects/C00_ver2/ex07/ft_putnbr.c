/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ducnguye <ducnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:32:00 by ducnguye          #+#    #+#             */
/*   Updated: 2024/09/04 17:18:07 by ducnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void ft_putnbr(int nb){
    

    if(nb<0){
        write(1,"-",1);
        nb = -nb;
    }

    if ( nb >= 10){
        ft_putnbr(nb/10);
    }

    char digit = nb%10 + '0' ;
    write(1,&digit,1);
}
