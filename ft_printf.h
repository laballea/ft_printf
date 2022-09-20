/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laballea <laballea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 11:58:40 by laballea          #+#    #+#             */
/*   Updated: 2019/11/15 13:28:46 by laballea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include "libft/libft.h"

int		ft_conv(char *str, int i, va_list *ap, int carac);
int		ft_without(const char *str, int i, int carac);
int		*ft_pourcent(va_list *ap, int *c, char *str);

int		ft_printf(const char *str, ...);

int		ft_putc(va_list *ap, int carac, int i, char *str);
int		ft_puts(va_list *ap, int carac, int i, char *str);
int		ft_putp(va_list *ap, int carac, int i, char *str);
int		ft_putdi(va_list *ap, int carac, int i, char *str);
int		ft_putu(va_list *ap, int carac, int i, char *str);
int		ft_putxx(va_list *ap, int carac, int i, char *str);
int		ft_putx(va_list *ap, int carac, int i, char *str);
void	ft_putunbr_fd(unsigned int n, int fd);

int		**ft_getflags(char *str, int i, va_list *ap);
int		ft_printflags(int lenght, int **flags, int neg, char zorp);

int		ft_cflags(char *str, int i, int check);
int		ft_cset(char c, char *set);

int		**ft_getflagszero(int **flags, char *str, int i, va_list *ap);
int		**ft_getflagsmin(int **flags, char *str, int i, va_list *ap);
int		**ft_getflagspoint(int **flags, char *str, int i, va_list *ap);
int		**ft_getflagsfield(int **flags, char *str, int i);
int		**ft_getflagswildcard(int **flags, char *str, int i, va_list *ap);

int		ft_printflagszero(int lenght, int size, int neg, int pointsize);
int		ft_printflagsmin(int **flags, int lenght, int neg, int pointsize);
int		ft_printflagsminfors(int **flags, int lenght, int pointsize);
int		ft_printflagsfield(int lenght, int size, int pointsize, int neg);
int		ft_printflagspoint(int lenght, int size, int neg, char zorp);

void	ft_free(int **flags);

#endif
