/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 23:48:50 by avieira           #+#    #+#             */
/*   Updated: 2021/10/09 13:07:22 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	reverse_rotate_double(t_stacks *stacks, char sorting, t_input *input)
{
	t_opes	*ope;

	reverse_rotate(stacks->a, stacks->len_a);
	reverse_rotate(stacks->b, stacks->len_b);
	if (sorting)
	{
		ope = malloc(sizeof(t_opes));
		if (!ope)
			error(input);
		*ope = rrr;
		add_ope(ope, input);
	}
}
