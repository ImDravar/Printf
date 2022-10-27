/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz-sa <rruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:24:09 by rruiz-sa          #+#    #+#             */
/*   Updated: 2022/10/26 21:33:40 by rruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_x(unsigned int num, char *base)
{
	int	i;
	int	temp;
	int	temp2;

	temp = 0;
	temp2 = 0;
	i = 0;
	if (num < 16)
	{
		if (ft_putchar(base[num]) == -1)
			return (-1);
		i++;
	}
	else
	{
		temp = ft_printf_x(num / 16, base);
		if (temp == -1)
			return (-1);
		temp2 = ft_printf_x(num % 16, base);
		if (temp2 == -1)
			return (-1);
		i += temp + temp2;
	}
	return (i);
}
/*
	[Description ft_printf_x]
		1- Check if number < 16
			{If it is}
				a- Call [ft_putchar] and send the char of the base
				b- Check if the return of [ft_putchar] its correct, if not return -1
				c- Increase the counter
			{If not}
				A- Call with recursivity [ft_printf_x] send the num/16 and the base
				B- Check if the return its correct, if its not return -1
				C- Call with recursivity [ft_printf_x] send num%16 and the base
				D- Check if the return its correct, if its not return -1
				E- Increase the counter with the sum of the return A+B
		2- Return the counter

	[Description ft_putchar]
		1- Write the character passed by parameter AND
			 check if the writing its correct
		2- If its incorrect return -1 , it its correct return 1;

*/
/*
int main (void){
	//printf("\nReturn: %d",ft_printf_xX(167892323, "0123456789abcdef"));
	//printf("\nReturn: %d",ft_printf_xX(167892323, "0123456789ABCDEF"));

	return (0);
}
*/