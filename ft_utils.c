/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laballea <laballea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 12:04:01 by laballea          #+#    #+#             */
/*   Updated: 2019/11/15 18:16:17 by laballea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_free(int **flags)
{
	int i;

	i = 0;
	while (i < 2)
	{
		free(flags[i]);
		i++;
	}
	free(flags);
}

int		ft_check(int check, int i)
{
	if (check == i && check != 0)
		return (0);
	else
		return (1);
}

int		ft_cflags(char *str, int i, int check)
{
	int resi;

	if (i == 0 && str[i] == '%')
		return (0);
	if (i > 0)
		i--;
	while (ft_cset(str[i], "0.-*123456789") && i)
		i--;
	if (str[i] == '%' && ft_check(check, i))
	{
		resi = i;
		i++;
		while (ft_cset(str[i], "0.-*123456789"))
			i++;
		if (ft_cset(str[i], "cspdiuxX%%"))
			return (1);
	}
	return (0);
}

int		ft_without(const char *str, int i, int carac)
{
	char c;

	c = str[i];
	write(1, &c, 1);
	carac++;
	return (carac);
}

int		ft_conv(char *str, int i, va_list *ap, int carac)
{
	if (str[i] == 'c')
		return (ft_putc(ap, carac, i, str));
	else if (str[i] == 's')
		return (ft_puts(ap, carac, i, str));
	else if (str[i] == 'p')
		return (ft_putp(ap, carac, i, str));
	else if (str[i] == 'd')
		return (ft_putdi(ap, carac, i, str));
	else if (str[i] == 'i')
		return (ft_putdi(ap, carac, i, str));
	else if (str[i] == 'u')
		return (ft_putu(ap, carac, i, str));
	else if (str[i] == 'x')
		return (ft_putx(ap, carac, i, str));
	else if (str[i] == 'X')
		return (ft_putxx(ap, carac, i, str));
	return (carac);
}
