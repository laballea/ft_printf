/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laballea <laballea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:30:41 by laballea          #+#    #+#             */
/*   Updated: 2019/11/16 14:22:37 by laballea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printflagszero(int lenght, int size, int neg, int pointsize)
{
	int		carac;
	int		point;
	char	a;

	carac = 0;
	a = '0';
	if (pointsize > -1)
		a = ' ';
	if (neg == -1)
		pointsize++;
	if (pointsize && pointsize >= lenght)
		point = pointsize;
	else
		point = lenght;
	if (neg == -1)
		ft_putchar_fd('-', 1);
	size -= point;
	if (size < 0)
		size = 0;
	while (size-- > 0 && carac++ > -1)
		ft_putchar_fd(a, 1);
	return (carac);
}

int		ft_printflagsmin(int **flags, int lenght, int neg, int pointsize)
{
	int carac;
	int size;
	int point;

	size = flags[1][1];
	carac = 0;
	if (pointsize <= 0)
		neg = 0;
	if (pointsize > lenght)
		point = pointsize + neg;
	else
		point = lenght + neg;
	if (flags[0][1] == '-')
	{
		size -= point;
		if (size < 0)
			size = 0;
		while (size-- > 0)
		{
			ft_putchar_fd(' ', 1);
			carac++;
		}
	}
	return (carac);
}

int		ft_printflagsminfors(int **flags, int lenght, int pointsize)
{
	int carac;
	int size;

	carac = 0;
	size = pointsize - lenght;
	if (flags[0][1] == '-')
	{
		if (size < 0)
			size = 0;
		while (size-- > 0)
		{
			ft_putchar_fd(' ', 1);
			carac++;
		}
	}
	return (carac);
}

int		ft_printflagsfield(int lenght, int size, int pointsize, int neg)
{
	int carac;
	int point;

	carac = 0;
	if (pointsize && pointsize >= lenght)
		point = pointsize;
	else
		point = lenght;
	size -= point;
	(void)neg;
	if (neg == -1 && pointsize > 0)
		size -= 1;
	if (size < 0)
		size = 0;
	while (size-- > 0)
	{
		ft_putchar_fd(' ', 1);
		carac++;
	}
	return (carac);
}

int		ft_printflagspoint(int lenght, int size, int neg, char zorp)
{
	int carac;
	int i;

	carac = 0;
	if (neg == -1)
	{
		ft_putchar_fd('-', 1);
		size++;
	}
	i = -1;
	while (++i < size - lenght)
	{
		ft_putchar_fd(zorp, 1);
		carac++;
	}
	return (carac);
}
