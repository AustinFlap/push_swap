/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 23:58:43 by avieira           #+#    #+#             */
/*   Updated: 2021/09/30 04:08:14 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	swap_double(t_stacks *stacks, char sorting, t_input *input)
{
	t_opes *ope;

	swap_a(stacks, sorting, input);
	swap_b(stacks, sorting, input);
	if (sorting)
	{
		if (!(ope = malloc(sizeof(t_opes))))
			error(input);
		*ope = ss;
		add_ope(ope, input);
	}
}
