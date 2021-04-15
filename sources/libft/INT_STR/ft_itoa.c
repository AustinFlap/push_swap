/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 20..//07 16:44:55 by avieira           #+#    #+#             */
/*   Updated: 2021/04/14 13:32:20 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int		get_lenght(long int n)
{
	int len;

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

char			*ft_itoa(long int n)
{
	long int	num;
	char		*number;
	int			len;

	num = n;
	num = (n < 0) ? num * -1 : num;
	len = get_lenght(n);
	if (!(number = malloc(sizeof(char) * (len + 1))))
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
