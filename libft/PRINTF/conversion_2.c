/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 18:19:50 by avieira           #+#    #+#             */
/*   Updated: 2021/10/09 14:07:56 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	u(t_flag flag, int *ret, char *arg)
{
	int		size;
	char	*print;

	if (*arg == '0' && flag.precision == 0)
	{
		free(arg);
		write_conversion(ret, "", flag);
		return ;
	}
	size = ft_strlen(arg);
	print = alloc_print(max(size, flag.precision), 1);
	if (!print)
		return ;
	ft_memcpy(print + max(size, flag.precision) - size, arg, size);
	write_conversion(ret, print, flag);
	free(arg);
	free(print);
}

void	xx(t_flag flag, int *ret, char *arg)
{
	int		size;
	char	*print;

	if (*arg == '0' && flag.precision == 0)
	{
		free(arg);
		write_conversion(ret, "", flag);
		return ;
	}
	size = ft_strlen(arg);
	print = alloc_print(max(size, flag.precision), 1);
	if (!print)
		return ;
	ft_memcpy(print + max(size, flag.precision) - size, arg, size);
	if (flag.format == 'X')
		str_toupper(print);
	write_conversion(ret, print, flag);
	free(arg);
	free(print);
}

void	mod(t_flag flag, int *ret, char *arg)
{
	write_conversion(ret, arg, flag);
}
