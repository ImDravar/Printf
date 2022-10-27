/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz-sa <rruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:48:18 by rruiz-sa          #+#    #+#             */
/*   Updated: 2022/10/26 20:26:39 by rruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_c(int c)
{
	int	check;

	check = ft_putchar(c);
	return (check);
}
/*
	[Description ft_printf_c]
		1- Call [ft_putchar] and send the char passed by parameter AND
			 return their value (the number of bytes printed)

	[Description ft_putchar]
		1- Write the character passed by parameter AND
			 check if the writing its correct
		2- If its incorrect return -1 , it its correct return 1;
*/
