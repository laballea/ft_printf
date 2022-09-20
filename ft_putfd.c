/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laballea <laballea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 17:18:35 by marvin            #+#    #+#             */
/*   Updated: 2019/11/16 14:20:18 by laballea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putc(va_list *ap, int carac, int i, char *str)
{
	int		**flags;
	int		arg;

	flags = ft_getflags(str, i, ap);
	arg = va_arg(*ap, int);
	carac += ft_printflags(1, flags, 1, '0');
	ft_putchar_fd(arg, 1);
	carac += ft_printflagsmin(flags, 1, 1, flags[1][2]) + 1;
	ft_free(flags);
	return (carac);
}

int		ft_puts(va_list *ap, int carac, int i, char *str)
{
	int		**flags;
	char	*arg;
	int		check;

	check = 0;
	flags = ft_getflags(str, i, ap);
	arg = va_arg(*ap, char *);
	if (!arg)
		arg = "(null)";
	if (flags[0][2] == '.' && flags[1][2] >= 0 && !check++)
		arg = ft_substr(arg, 0, flags[1][2]);
	flags[0][2] = 0;
	flags[1][2] = 0;
	carac += ft_printflags(ft_strlen(arg), flags, 1, '0');
	ft_putstr_fd(arg, 1);
	carac += ft_printflagsminfors(flags, ft_strlen(arg),
	flags[1][1]) + ft_strlen(arg);
	if (check == 1)
		free(arg);
	ft_free(flags);
	return (carac);
}

int		ft_putp(va_list *ap, int carac, int i, char *str)
{
	int		**flags;
	int		lenght;
	size_t	arg;
	int		n;

	n = 2;
	flags = ft_getflags(str, i, ap);
	arg = va_arg(*ap, size_t);
	if (flags[0][2] == '.')
		n = 1;
	lenght = ft_putnbr_base_uns(arg, "0123456789abcdef", 0) + n;
	carac += ft_printflags(lenght, flags, 1, '0');
	ft_putstr_fd("0x", 1);
	if (!(flags[0][2] == '.' && arg == 0))
		carac += ft_putnbr_base_uns(arg, "0123456789abcdef", 1);
	carac += ft_printflagsmin(flags, lenght, 1, flags[1][2]) + 2;
	ft_free(flags);
	return (carac);
}

int		*getplace(int **flags, int arg)
{
	int *neg;

	if (!(neg = malloc(sizeof(int) * 4)))
		return (0);
	neg[0] = 1;
	neg[1] = 1;
	neg[2] = 0;
	neg[3] = 1;
	if (arg < 0)
		neg[0] = -1;
	if (neg[0] == -1 && (flags[0][0] == '0' || flags[0][2] == '.'))
		neg[1] = -1;
	if (arg == 0 && flags[0][2] == '.' && flags[1][2] == 0 && flags[1][1] > 0)
		neg[3] = 0;
	if (arg < 0 && flags[0][2] == '.' && flags[1][2] < flags[1][1])
		neg[2] = 1;
	return (neg);
}

int		ft_putdi(va_list *ap, int carac, int i, char *str)
{
	int		**flags;
	int		arg;
	int		*neg;

	flags = ft_getflags(str, i, ap);
	arg = va_arg(*ap, int);
	neg = getplace(flags, arg);
	if (flags[0][2] == '.' && arg == 0 && flags[1][2] == 0)
	{
		flags[0][2] = -1;
		if (!flags[1][0] && !flags[1][3])
			carac--;
	}
	carac += ft_printflags(ft_intlen(arg) * neg[3], flags, neg[0], '0')
	+ ft_intlen(arg) * neg[3];
	if (!(flags[0][2] == -1 && arg == 0))
		ft_putnbr_fd(arg * neg[1], 1);
	else if (flags[1][3] != 0)
		ft_putchar_fd(' ', 1);
	carac += ft_printflagsmin(flags, ft_intlen(arg), neg[2], flags[1][2]);
	free(neg);
	ft_free(flags);
	return (carac);
}
