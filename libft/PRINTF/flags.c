/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 00:59:03 by avieira           #+#    #+#             */
/*   Updated: 2021/10/09 14:06:44 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	minus(const char *str, char format)
{
	str++;
	while ((*str == '0' || *str == '-') && *str != format)
	{
		if (*str == '-')
			return (1);
		str++;
	}
	return (0);
}

int	zero(const char *str, char format)
{
	str++;
	while ((*str == '0' || *str == '-') && *str != format)
	{
		if (*str == '0')
			return (1);
		str++;
	}
	return (0);
}

int	precision(const char *str, char format, va_list ap)
{
	int	stock;

	while (*str != format)
		str++;
	while (*str != '.' && *str != '%')
		str--;
	if (*str == '%')
		return (-1);
	else if (*(str + 1) == '*')
	{
		stock = va_arg(ap, int);
		if (stock < 0)
			return (-1);
		else
			return (stock);
	}
	return (ft_atoi(str + 1));
}

int	width(const char *str, char format, va_list ap)
{
	str++;
	while ((*str == '0' || *str == '-') && *str != format)
		str++;
	if (*str == '*')
		return (va_arg(ap, int));
	else if (ft_isdigit(*str))
		return (ft_atoi(str));
	return (0);
}

char	*alloc_print(int size, int zero)
{
	char	*print;

	print = ft_calloc(size + 1, sizeof(char));
	if (!print)
		return (NULL);
	print[size] = 0;
	if (zero)
		ft_memset(print, '0', size);
	else
		ft_memset(print, ' ', size);
	return (print);
}
