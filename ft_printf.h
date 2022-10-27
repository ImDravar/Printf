/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz-sa <rruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:14:29 by rruiz-sa          #+#    #+#             */
/*   Updated: 2022/10/22 13:22:16 by rruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

int		ft_printf(char const *str, ...);
int		ft_flagchecker(char flag, va_list arg_ptr);
int		ft_printf_c(int c);
int		ft_printf_s(char *str, int check_malloc);
int		ft_printf_di(int num);
int		ft_printf_u(unsigned int num);
int		ft_printf_x(unsigned int num, char *base);
int		ft_printf_37(void);
int		ft_printf_p(unsigned long long p);

// UTILS //
int		ft_putchar(char c);
int		ft_isdigit(int c);
int		ft_isascii(int c);
size_t	ft_strlen(const char *str);
long	ft_minmax(long n);

#endif