/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 00:41:45 by avieira           #+#    #+#             */
/*   Updated: 2021/04/27 00:57:43 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		check_stacks(int *a, int *len_a, int *len_b)
{
	int		i;

	i = 0;
	if (!*len_b)
	{
		while (++i < *len_a)
			if (a[i] < a[i - 1])
				ft_printf("KO");
		ft_printf("OK");
	}
	ft_printf("KO");
}
