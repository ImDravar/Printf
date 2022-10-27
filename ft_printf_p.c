/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz-sa <rruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:41:08 by rruiz-sa          #+#    #+#             */
/*   Updated: 2022/10/26 20:57:34 by rruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_p_num(unsigned long long num, char *base)
{
	int	i;
	int	temp;
	int	temp2;

	temp = 0;
	i = 0;
	temp2 = 0;
	if (num < 16)
	{
		if (ft_putchar(base[num]) == -1)
			return (-1);
		i++;
	}
	else
	{
		temp = ft_printf_p_num(num / 16, base);
		temp2 = ft_printf_p_num(num % 16, base);
		if (temp == -1 || temp2 == -1)
			return (-1);
		i += temp + temp2;
	}
	return (i);
}
/*
	[Description ft_printf_p_num]
		1- Check If the number passed by parameter is < 16
			{If its}
				a- Call [ft_putchar] and send the char of the hex base
				b- Check if the return of the [ft_putchar] its incorrect
					-- If its, return -1
				c- Increase the counter
			{If its not}
				A- Send to [ft_printf_p_num] the num / 16 and the base and save the return
				B- Send to [ft_printf_p_num] the num % 16 and the base and save the return
				C- Check if the return of A or B its incorrect
					--If its, return -1
				D- Sum the return of A + B to the counter and to itself
		2- Return the counter
*/

int	ft_printf_p(unsigned long long p)
{
	int	i;
	int	temp;
	int	temp2;

	temp = 0;
	temp2 = 0;
	i = 0;
	if (!p)
	{
		i = ft_printf_s("0x0", 0);
		if (i == -1)
			return (-1);
	}
	else
	{
		temp = ft_printf_s("0x", 0);
		if (temp == -1)
			return (-1);
		temp2 = ft_printf_p_num(p, "0123456789abcdef");
		if (temp2 == -1)
			return (-1);
		i += temp;
		i += temp2;
	}
	return (i);
}
/*
	[Description ft_printf_p]
		1- Check If the number passed by parametr exist
			{If doesn't}
				a- Call [ft_printf_s] ans send "0x0"
				b- Check if the return of the [ft_printf_s] its incorrect
					- If its, return -1
			{If exist}
				A- Call [ft_printf_s] ans send "0x"
				B- Check if the return of the [ft_printf_s] its incorrect
					- If its, return -1
				C- Call [ft_printf_p_num] ans send the number and the hex base

	[Description ft_printf_s]
		1- Check If the string exist
			{If exist}
				a- Iterate the string, call [ft_putchar] each iteration
				b- And each iteration check if the writing is correct
					 if its Incorrect return -1
			{If doesn't}
				A- Counter its equal to size of the str "(null)"
				B- Call [ft_printf_s] and send by parameter "(null)"
				C- Check the return of [ft_printf_s] if its Incorrect return -1
		2- If the param "check_malloc" its 1 free the str
		3- Return counter

	[Description ft_putchar]
		1- Write the character passed by parameter AND
			 check if the writing its correct
		2- If its incorrect return -1 , it its correct return 1;
*/
/*
int main (void){

	printf("\nReturn: %d",ft_printf_p(167892323, "0123456789abcdf"));
	printf("\nReturn:%d", printf("%p",167892323));

	return (0);
}*/