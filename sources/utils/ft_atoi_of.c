/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_of.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 20:44:21 by avieira           #+#    #+#             */
/*   Updated: 2021/10/09 13:11:25 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_atoi_of(const char *nptr, t_input *input)
{
	const char	*temp;
	long int	nb;
	int			u;

	temp = nptr;
	u = 1;
	nb = 0;
	while (*temp)
		temp++;
	while (temp != nptr)
	{
		temp--;
		if (*temp >= '0' && *temp <= '9')
		{
			nb += (*temp - 48) * u;
			u *= 10;
		}
		else if (*temp == '-')
			nb *= -1;
		if (nb > MAX_INT)
			error(input);
	}
	if (nb < MIN_INT || nb > MAX_INT)
		error(input);
	return ((int)nb);
}
