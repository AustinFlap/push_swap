/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:17:05 by avieira           #+#    #+#             */
/*   Updated: 2021/10/09 14:12:05 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	def_conversion(const char *str, const char *set)
{
	int				i;

	str++;
	while (*str)
	{
		i = -1;
		while (set[++i])
			if (set[i] == *str)
				return (i);
		str++;
	}
	return (-1);
}

static char	*get_arg(char format, va_list ap)
{
	char			*arg;

	if (format == 'c')
	{
		arg = ft_calloc(2, sizeof(char));
		if (!arg)
			return (NULL);
		*arg = va_arg(ap, int);
		return (arg);
	}
	else if (format == 's')
		return (va_arg(ap, char *));
	else if (format == 'p')
		return (ft_convert_to_hex(va_arg(ap, unsigned long int), "0x"));
	else if (format == 'd' || format == 'i')
		return (ft_itoa(va_arg(ap, int)));
	else if (format == 'u')
		return (ft_itoa(va_arg(ap, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_convert_to_hex(va_arg(ap, unsigned int), ""));
	else if (format == '%')
		return ("%");
	return (NULL);
}

static t_flag	def_flag(const char *str, char format, va_list ap)
{
	t_flag			flag;

	flag.width = width(str, format, ap);
	flag.precision = precision(str, format, ap);
	flag.minus = minus(str, format);
	flag.format = format;
	if (flag.width < 0)
	{
		flag.width *= -1;
		flag.minus = 1;
	}
	if (flag.minus || ((format == 'd' || format == 'i' || format == 'p'
				|| format == 'u' || format == 'x' || format == 'X')
			&& flag.precision > -1))
		flag.zero = 0;
	else
		zero(str, format);
	return (flag);
}

static const char	*conversion(const char *str, va_list ap, int *ret)
{
	void			(*f[9])(t_flag, int*, char *);
	int				i;
	const char		set[] = "cspdiuxX%";

	f[0] = &c;
	f[1] = &s;
	f[2] = &p;
	f[3] = &di;
	f[4] = &di;
	f[5] = &u;
	f[6] = &xx;
	f[7] = &xx;
	f[8] = &mod;
	i = def_conversion(str, set);
	if (i != -1)
	{
		f[i](def_flag(str, set[i], ap), ret, get_arg(set[i], ap));
		str++;
		while (*str != set[i])
			str++;
	}
	return (str + 1);
}

int	ft_printf(const char *str, ...)
{
	va_list			ap;
	int				ret;
	int				i;

	ret = 0;
	va_start(ap, str);
	while (*str)
	{
		i = 0;
		if (*str == '%')
			str = conversion(str, ap, &ret);
		while (str[i] && str[i] != '%')
			i++;
		if (i)
		{
			write(1, str, i);
			ret += i;
			str += i;
		}
	}
	va_end(ap);
	return (ret);
}
