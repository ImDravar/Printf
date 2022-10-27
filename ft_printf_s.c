/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz-sa <rruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:52:46 by rruiz-sa          #+#    #+#             */
/*   Updated: 2022/10/26 20:31:50 by rruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_s(char *str, int check_malloc)
{
	int	i;
	int	check;

	i = -1;
	check = 0;
	if (str)
	{
		while (str[++i])
		{
			check = ft_putchar(str[i]);
			if (check == -1)
				return (-1);
		}
	}
	else
	{
		i = 6;
		check = ft_printf_s("(null)", 0);
		if (check == -1)
			return (-1);
	}
	if (check_malloc == 1)
		free(str);
	return (i);
}
/*
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
