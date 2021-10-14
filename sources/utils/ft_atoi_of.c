/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_of.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 20:44:21 by avieira           #+#    #+#             */
/*   Updated: 2021/10/12 22:15:29 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_atoi_of(const char *nptr, t_input *input)
{
	int					i;
	int					neg;
	unsigned long long	n;
	int					len;

	i = 0;
	n = 0;
	neg = 1;
	len = (int)ft_strlen((char *)nptr);
	while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
		if (nptr[i++] == '-')
			neg = -1;
	if (i == len)
		error(input);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		n = 10 * n + (nptr[i++] - '0');
		if ((n > 2147483647 && neg == 1) || (n > 2147483648 && neg == -1))
			error(input);
	}
	if (i == 0 || i != len)
		error(input);
	return ((int)n * neg);
}
