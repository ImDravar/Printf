/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_37.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz-sa <rruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 20:52:16 by rruiz-sa          #+#    #+#             */
/*   Updated: 2022/10/26 20:26:36 by rruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_37(void)
{
	int	check;

	check = ft_putchar('%');
	return (check);
}
/*
	[Description ft_printf_37]
		1- Call [ft_putchar] with the '%' AND
			 return their value (the number of bytes printed)

	[Description ft_putchar]
		1- Write the character passed by parameter AND
			 check if the writing its correct
		2- If its incorrect return -1 , it its correct return 1;
*/