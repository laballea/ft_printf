/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laballea <laballea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 11:15:38 by laballea          #+#    #+#             */
/*   Updated: 2019/11/15 18:26:39 by laballea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_cset(char c, char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

int		*initc(void)
{
	int *c;

	if (!(c = malloc(sizeof(int) * 3)))
		return (0);
	c[0] = 0;
	c[1] = 0;
	c[2] = -1;
	return (c);
}

int		ft_getplace(int *c)
{
	int check;

	check = c[0];
	free(c);
	return (check);
}

int		ft_printf(const char *str, ...)
{
	int	*c;
	int check;

	c = initc();
	check = 0;
	va_list(ap);
	va_start(ap, str);
	while (str[++c[2]])
	{
		if (ft_cset(str[c[2]], "cspdiuxX%%")
		&& ft_cflags((char *)str, c[2], check))
		{
			check = c[2];
			c[0] = ft_conv((char *)str, c[2], &ap, c[0]);
			if (str[c[2]] == '%')
				c = ft_pourcent(&ap, c, (char *)str);
		}
		if (!ft_cflags((char *)str, c[2], check) && str[c[2]] != '%')
			c[0] = ft_without(str, c[2], c[0]);
	}
	check = ft_getplace(c);
	va_end(ap);
	return (check);
}
