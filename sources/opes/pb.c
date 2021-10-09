/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 23:58:43 by avieira           #+#    #+#             */
/*   Updated: 2021/10/09 13:05:19 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_b(t_stacks *stacks, char sorting, t_input *input)
{
	t_opes	*ope;

	push(stacks->b, stacks->a, stacks->len_b, stacks->len_a);
	if (sorting)
	{
		ope = malloc(sizeof(t_opes));
		if (!ope)
			error(input);
		*ope = pb;
		add_ope(ope, input);
	}
}
