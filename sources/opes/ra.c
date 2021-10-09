/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 23:48:50 by avieira           #+#    #+#             */
/*   Updated: 2021/10/09 13:05:50 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate_a(t_stacks *stacks, char sorting, t_input *input)
{
	t_opes	*ope;

	rotate(stacks->a, stacks->len_a);
	if (sorting)
	{
		ope = malloc(sizeof(t_opes));
		if (!ope)
			error(input);
		*ope = ra;
		add_ope(ope, input);
	}
}
