/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfd2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laballea <laballea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:16:33 by laballea          #+#    #+#             */
/*   Updated: 2019/11/16 13:44:13 by laballea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putu(va_list *ap, int carac, int i, char *str)
{
	int					**flags;
	unsigned int		arg[2];
	char				*lol;

	flags = ft_getflags(str, i, ap);
	arg[0] = va_arg(*ap, unsigned long long);
	arg[1] = 1;
	if (flags[0][2] == '.' && arg[0] == 0 && flags[1][2] == 0)
	{
		flags[0][2] = -1;
		carac--;
		if (flags[1][0])
			arg[1] = 0;
	}
	lol = ft_itoaunsigned(arg[0]);
	carac += ft_printflags(ft_unslen(arg[0]) * arg[1], flags, 1, '0');
	if (!(flags[0][2] == -1 && arg[0] == 0))
		ft_putstr_fd(lol, 1);
	else if (flags[1][3] != 0)
		carac--;
	carac += ft_printflagsmin(flags, ft_unslen(arg[0]), 0,
	flags[1][2]) + ft_unslen(arg[0]);
	free(lol);
	ft_free(flags);
	return (carac);
}

void	ft_putunbr_fd(unsigned int n, int fd)
{
	if (n / 10 > 0)
		ft_putunbr_fd(n / 10, fd);
	ft_putchar_fd('0' + n % 10, fd);
}

int		ft_putx(va_list *ap, int carac, int i, char *str)
{
	int				**flags;
	int				lenght;
	unsigned int	arg[2];

	flags = ft_getflags(str, i, ap);
	arg[0] = va_arg(*ap, unsigned int);
	arg[1] = 1;
	if (flags[0][2] == '.' && arg[0] == 0 && flags[1][2] == 0)
	{
		flags[0][2] = -1;
		if (flags[1][0])
			arg[1] = 0;
	}
	lenght = ft_putnbr_base_uns(arg[0], "0123456789abcdef", 0) * arg[1];
	carac += ft_printflags(lenght, flags, 1, '0');
	if (!(flags[0][2] == -1 && arg[0] == 0 && flags[1][2] == 0))
		carac += ft_putnbr_base_uns(arg[0], "0123456789abcdef", 1);
	else if (flags[1][3] != 0)
	{
		ft_putchar_fd(' ', 1);
		carac++;
	}
	carac += ft_printflagsmin(flags, lenght, 0, flags[1][2]);
	ft_free(flags);
	return (carac);
}

int		ft_putxx(va_list *ap, int carac, int i, char *str)
{
	int				**flags;
	int				lenght;
	unsigned int	arg[2];

	flags = ft_getflags(str, i, ap);
	arg[0] = va_arg(*ap, unsigned int);
	arg[1] = 1;
	if (flags[0][2] == '.' && arg[0] == 0 && flags[1][2] == 0)
	{
		flags[0][2] = -1;
		if (flags[1][0])
			arg[1] = 0;
	}
	lenght = ft_putnbr_base_uns(arg[0], "0123456789ABCDEF", 0) * arg[1];
	carac += ft_printflags(lenght, flags, 1, '0');
	if (!(flags[0][2] == -1 && arg[0] == 0 && flags[1][2] == 0))
		carac += ft_putnbr_base_uns(arg[0], "0123456789ABCDEF", 1);
	else if (flags[1][3] != 0)
	{
		ft_putchar_fd(' ', 1);
		carac++;
	}
	carac += ft_printflagsmin(flags, lenght, 0, flags[1][2]);
	ft_free(flags);
	return (carac);
}

int		*ft_pourcent(va_list *ap, int *c, char *str)
{
	int		**flags;
	int		arg;

	flags = ft_getflags(str, c[2], ap);
	flags[1][2] = -1;
	arg = '%';
	while (str[c[2]++] != '%')
		;
	c[0] += ft_printflags(1, flags, 1, ' ');
	ft_putchar_fd(arg, 1);
	c[0] += ft_printflagsmin(flags, 1, 0, flags[1][2]) + 1;
	c[1] = 1;
	c[2] -= 1;
	ft_free(flags);
	return (c);
}
