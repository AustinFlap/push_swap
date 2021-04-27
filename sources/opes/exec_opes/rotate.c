/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 21:45:14 by avieira           #+#    #+#             */
/*   Updated: 2021/04/27 01:49:47 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	reverse_array_index(int *a, int start, int end)
{
	int	tmp[end - start + 1];
	int	i;

	i = -1;
	while (++i < end - start + 1)
		tmp[i] = a[i + start];
	while (--i > -1)
		a[end - i] = tmp[i];
}

void	rotate(int *a, int *len_a)
{
	if (*len_a < 2)
		return ;
	reverse_array_index(a, 0, *len_a - 1);
	reverse_array_index(a, 0, *len_a - 2);
}

void	reverse_rotate(int *a, int *len_a)
{
	if (*len_a < 2)
		return ;
	reverse_array_index(a, 0, *len_a - 1);
	reverse_array_index(a, 1, *len_a - 1);
}
