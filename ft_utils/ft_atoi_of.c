/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_of.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 20:44:21 by avieira           #+#    #+#             */
/*   Updated: 2021/03/27 22:09:49 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		ft_atoi_of(const char *nptr)
{
	unsigned int	nb;
	const char		*temp;
	int				u;

	u = 1;
	nb = 0;
	temp = nptr;
	while ((*temp >= 9 && *temp <= 13) || *temp == ' ')
		temp++;
	if (*temp == '-' || *temp == '+')
		temp++;
	while (*temp >= '0' && *temp <= '9')
		temp++;
	while ((temp != nptr) || ((*temp < 9 && *temp > 13) && *temp != ' '))
	{
		temp--;
		if (*temp >= '0' && *temp <= '9')
		{
			nb += (*temp - 48) * u;
			u *= 10;
			if (nb > MAX_INT)
				return (MAX_INT);
		}
	}
	return ((int)nb);
}
