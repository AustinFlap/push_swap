/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 23:58:43 by avieira           #+#    #+#             */
/*   Updated: 2021/09/30 04:06:28 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	swap_b(t_stacks *stacks, char sorting, t_input *input)
{
	t_opes *ope;

	swap(stacks->b, stacks->len_b);
	if (sorting)
	{
		if (!(ope = malloc(sizeof(t_opes))))
			error(input);
		*ope = sb;
		add_ope(ope, input);
	}
}
