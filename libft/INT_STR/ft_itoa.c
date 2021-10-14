/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 20..//07 16:44:55 by avieira           #+#    #+#             */
/*   Updated: 2021/10/09 13:21:33 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	get_lenght(long int n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 9)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(long int n)
{
	long int	num;
	char		*number;
	int			len;

	num = n;
	if (n < 0)
		num = num * -1;
	len = get_lenght(n);
	number = malloc(sizeof(char) * (len + 1));
	if (!number)
		return (NULL);
	number += len;
	*number = 0;
	while (num > 9)
	{
		*--number = num % 10 + 48;
		num /= 10;
	}
	*--number = num % 10 + 48;
	if (n < 0)
		*--number = '-';
	return (number);
}
