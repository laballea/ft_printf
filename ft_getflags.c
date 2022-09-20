/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getflags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laballea <laballea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:49:51 by laballea          #+#    #+#             */
/*   Updated: 2019/11/16 14:24:36 by laballea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		**ft_getflagsfield(int **flags, char *str, int i)
{
	while (str[i - 1] != '%')
		i--;
	if (ft_cset(str[i], "123456789"))
		flags[1][3] = ft_atoi(str + i);
	else
		flags[1][3] = 0;
	return (flags);
}

int		**ft_getflagszero(int **flags, char *str, int i, va_list *ap)
{
	flags[1][0] = 0;
	while (str[i - 1] != '%')
		i--;
	while (!ft_cset(str[i], "123456789cspdiuxX%%"))
	{
		if (str[i] == '0' && !ft_cset(str[i - 1], "123546789."))
		{
			flags[0][0] = '0';
			if (str[i + 1] == '*' && flags[1][1] == 0)
				flags[1][0] = va_arg(*ap, int);
			else if (flags[1][1] == 0)
				flags[1][0] = ft_atoi(str + i + 1);
			return (flags);
		}
		i++;
	}
	return (flags);
}

int		**ft_getflagsmin(int **flags, char *str, int i, va_list *ap)
{
	while (str[i - 1] != '%')
		i--;
	while (!ft_cset(str[i], "123456789cspdiuxX%%"))
	{
		if (str[i] == '-')
		{
			if (flags[0][0] == '0')
			{
				flags[0][0] = '\0';
				flags[1][0] = 0;
			}
			flags[0][1] = '-';
			if (str[i + 1] == '*')
				flags[1][1] = ft_abs(va_arg(*ap, int));
			else
			{
				while (str[i] == '-')
					i++;
				flags[1][1] = ft_atoi(str + i);
			}
			return (flags);
		}
		i++;
	}
	return (flags);
}

int		**ft_getflagspoint(int **flags, char *str, int i, va_list *ap)
{
	flags[1][2] = -1;
	while (str[i - 1] != '%')
		i--;
	while (!ft_cset(str[i], "cspdiuxX%%"))
	{
		if (str[i] == '.')
		{
			flags[0][2] = '.';
			if (str[i + 1] == '*')
				flags[1][2] = va_arg(*ap, int);
			else
				flags[1][2] = ft_atoi(str + i + 1);
			if (flags[1][2] < 0)
				flags[1][2] = -1;
			return (flags);
		}
		i++;
	}
	return (flags);
}

int		**ft_getflagswildcard(int **flags, char *str, int i, va_list *ap)
{
	int		wild;

	while (str[i - 1] != '%')
		i--;
	while (!ft_cset(str[i], "cspdiuxX%%"))
	{
		if (str[i] == '*' && !ft_cset(str[i - 1], "-."))
		{
			wild = va_arg(*ap, int);
			if (wild < 0)
			{
				flags[0][1] = '-';
				flags[1][1] = wild * -1;
			}
			else if (str[i - 1] != '0')
				flags[1][3] = wild;
		}
		i++;
	}
	return (flags);
}
