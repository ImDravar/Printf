/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz-sa <rruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:38:52 by rruiz-sa          #+#    #+#             */
/*   Updated: 2022/10/27 11:52:37 by rruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flagchecker(char flag, va_list arg_ptr)
{
	int	result;

	result = 0;
	if (flag == 'c')
		result = ft_printf_c(va_arg(arg_ptr, int));
	else if (flag == 's')
		result = ft_printf_s(va_arg(arg_ptr, char *), 0);
	else if (flag == 'p')
		result = ft_printf_p(va_arg(arg_ptr, unsigned long long));
	else if (flag == 'd' || flag == 'i')
		result = ft_printf_di(va_arg(arg_ptr, int));
	else if (flag == 'u')
		result = ft_printf_u(va_arg(arg_ptr, unsigned int));
	else if (flag == 'x')
		result = ft_printf_x(va_arg(arg_ptr, unsigned int), "0123456789abcdef");
	else if (flag == 'X')
		result = ft_printf_x(va_arg(arg_ptr, unsigned int), "0123456789ABCDEF");
	else if (flag == '%')
		result = ft_printf_37();
	return (result);
}
/*
	[Description ft_printf]
		1- Check the flag passed by paramenter
		2- Calls its respective function sending the argument pointer and
			saving the result
		3- Return the result
*/

int	ft_printf(char const *str, ...)
{
	va_list	arg_ptr;
	int		result;
	int		i;
	int		tmp;

	va_start(arg_ptr, str);
	result = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			tmp = ft_flagchecker(str[++i], arg_ptr);
			if (tmp == -1)
				return (-1);
			result += tmp;
		}
		else
		{
			if (ft_putchar(str[i]) == -1)
				return (-1);
			result++;
		}
	}
	return (result);
}
/*
	[Description ft_printf]
		1- Init the va_start
		2- Iterate the string and each iteration:
			- Check for %, if its matches and i + 1 still exist
			   {If exist}
				a- Call [ft_flagchecker, send the str char and the argument,save the return.
				b- Check if the return its incorrect, if its return -1
				c- Sum the return and him selft to the counter.
			   {If not}
				A- Call [ft_putchar] with the str char
				B- Check if the return its incorrect, if its, return -1
				C- Increase the counter.
		3- Return the counter
*/

// int main (void)
// {
// 	//printf("\nReturn: %d",ft_printf("Imprimir un tab:%c|",'\t')); //OK
// 	//printf("\nReturn: %d",ft_printf("Imp char:%c %c %c \n",'0' - 256, 1 ,2));
// 	printf("\nReturn: %d",ft_printf(" %d ", -1)); //OK
// 	//printf("\nReturn: %d",ft_printf("Imp una str%s\n","Me gusta el colacao"));
// 	//printf("\nReturn: %d",ft_printf("Imprimir un entero:%d\n",-9876543210));
// 	//printf("\nReturn: %d",ft_printf("Imp num sin negativo:%u\n",-9876543210));
// 	//printf("\nReturn: %d",ft_printf("Imprimir un hex min:%x\n",9876543210));
// 	//printf("\nReturn: %d",ft_printf("Imprimir un hex may:%X\n",9876543210));
// 	//printf("\nEl return es de : %d",);
// 	//printf("\nEl return es de : %d",);
// 	return (0);
// }
