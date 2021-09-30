/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 23:48:50 by avieira           #+#    #+#             */
/*   Updated: 2021/09/30 04:05:48 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate_double(t_stacks *stacks, char sorting, t_input *input)
{
	t_opes *ope;

	rotate(stacks->a, stacks->len_a);
	rotate(stacks->b, stacks->len_b);
	if (sorting)
	{
		if (!(ope = malloc(sizeof(t_opes))))
			error(input);
		*ope = rr;
		add_ope(ope, input);
	}
}
