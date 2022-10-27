/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz-sa <rruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:12:07 by rruiz-sa          #+#    #+#             */
/*   Updated: 2022/10/26 21:04:08 by rruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_numlen_easy(unsigned int num)
{
	int	i;

	i = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		num = num / 10;
		i++;
	}
	return (i);
}
/*
	[Description ft_numlen_easy]
		1- Check if number its equal a 0, if it is, return 1
		3- Iterate while number exist, at the end return the iteration counter.
*/

int	ft_printf_u(unsigned int num)
{
	char	*str;
	int		len;
	int		result;

	result = 0;
	num = ft_minmax(num);
	len = ft_numlen_easy(num);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (-1);
	str[len] = '\0';
	if (num == 0)
		str[0] = '0';
	while (num)
	{
		len--;
		str[len] = ft_minmax(num % 10) + '0';
		num = num / 10;
	}
	result = ft_printf_s(str, 1);
	if (result == -1)
		free (str);
	return (result);
}
/*
	[Description ft_printf_di]
		0- Transform the number in positive [ft_minmax]
		1- Get the len of the number [ft_numlen_easy]
		2- Create (and check)the malloc with the len
		3- Close the string
		4- Check if the number is equal to 0,
			if it is, put in the position 0 the character
		5- Iterate while num exist.Each iteration
			- Put the mod(in char) of the number in the string
			- The number is the result of dividing itself by 10
		6- Call [ft_printf_s] and send the str with the param for free the str
		7- Check the return of [ft_printf_s] if fails free the str
		8- Return the [ft_printf_s] value.

	[Description ft_minmax]
		1- If number is negative transform in positive

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