/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laballea <laballea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 10:20:34 by laballea          #+#    #+#             */
/*   Updated: 2019/11/15 13:33:50 by laballea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printflags(int lenght, int **flags, int neg, char zorp)
{
	int carac;
	int check;
	int check2;

	check = 1;
	check2 = 0;
	if (flags[0][0] == '0' && flags[0][2] == '.' && neg == -1)
		check = -1;
	if (neg == -1 && flags[0][2] == '.')
		check2 = 1;
	carac = 0;
	if (flags[1][3])
		carac += ft_printflagsfield(lenght, flags[1][3], flags[1][2], neg);
	if (flags[0][0] == '0')
		carac += ft_printflagszero(lenght,
		flags[1][0], neg * check, flags[1][2] + check2);
	if (flags[0][2] == '.')
		carac += ft_printflagspoint(lenght, flags[1][2], neg, zorp);
	return (carac);
}

int		**ft_getflags(char *str, int i, va_list *ap)
{
	int **flags;

	flags = ft_calloc(sizeof(int *), 2);
	flags[0] = ft_calloc(sizeof(int *), 3);
	flags[1] = ft_calloc(sizeof(int *), 4);
	flags = ft_getflagsfield(flags, str, i);
	flags = ft_getflagswildcard(flags, str, i, ap);
	flags = ft_getflagszero(flags, str, i, ap);
	flags = ft_getflagsmin(flags, str, i, ap);
	flags = ft_getflagspoint(flags, str, i, ap);
	return (flags);
}
