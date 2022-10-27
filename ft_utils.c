/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz-sa <rruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:33:40 by rruiz-sa          #+#    #+#             */
/*   Updated: 2022/10/26 20:18:20 by rruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	if (write (1, &c, 1) == -1)
		return (-1);
	return (1);
}
/*
	[Description ft_putchar]
		1- Write the character passed by parameter AND
			 check if the writing its correct
		2- If its incorrect return -1 , it its correct return 1;
*/

long	ft_minmax(long n)
{
	if (n < 0)
		n = -n;
	return (n);
}
/*
	[Description ft_minmax]
		1- If number is negative transform in positive
*/