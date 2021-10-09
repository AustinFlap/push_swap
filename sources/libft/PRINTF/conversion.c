/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 16:47:34 by avieira           #+#    #+#             */
/*   Updated: 2021/10/09 14:04:59 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	write_conversion(int *ret, char *arg, t_flag flag)
{
	int		size;
	int		len;
	char	*print;

	size = ft_strlen(arg);
	if (flag.format == 'c' && *arg == 0)
		size++;
	len = flag.width;
	if (size > flag.width)
		len = size;
	print = alloc_print(len + 1, flag.zero);
	if (!print)
		return ;
	if (flag.minus)
		ft_memcpy(print, arg, size);
	else
		ft_memcpy(print + len - size, arg, size);
	if (flag.format == 'd' || flag.format == 'i')
		replace(print, "-");
	if (flag.format == 'p')
		replace(print, "0x");
	write(1, print, len);
	*ret += len;
	free(print);
}

void	c(t_flag flag, int *ret, char *arg)
{
	write_conversion(ret, arg, flag);
	free(arg);
}

void	s(t_flag flag, int *ret, char *arg)
{
	int		size;
	char	*print;

	if (!arg)
		arg = "(null)";
	size = ft_strlen(arg);
	if (size > flag.precision && flag.precision > -1)
		size = flag.precision;
	print = ft_calloc(size + 1, sizeof(char));
	if (!print)
		return ;
	ft_memcpy(print, arg, size);
	print[size] = 0;
	write_conversion(ret, print, flag);
	free(print);
}

void	p(t_flag flag, int *ret, char *arg)
{
	int					size;
	char				*print;

	if (*arg == '0' && flag.precision == 0)
	{
		free(arg);
		write_conversion(ret, "0x", flag);
		return ;
	}
	size = ft_strlen(arg) - 2;
	print = alloc_print(max(size, flag.precision) + 2, 1);
	if (!print)
		return ;
	ft_memcpy(print + max(size, flag.precision) - size + 2, arg + 2, size);
	ft_memcpy(print, "0x", 2);
	write_conversion(ret, print, flag);
	free(print);
	free(arg);
}

void	di(t_flag flag, int *ret, char *arg)
{
	char	*print;
	int		size;
	int		neg;

	if (*arg == '0' && flag.precision == 0)
	{
		free(arg);
		write_conversion(ret, "", flag);
		return ;
	}
	neg = 0;
	if (*arg == '-')
		neg = 1;
	size = ft_strlen(arg) - neg;
	print = alloc_print(max(size, flag.precision) + neg, 1);
	if (!print)
		return ;
	ft_memcpy(print + max(size, flag.precision) - size + neg, arg + neg, size);
	if (neg)
		print[0] = '-';
	write_conversion(ret, print, flag);
	free(print);
	free(arg);
}
