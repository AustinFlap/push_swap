/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 23:58:43 by avieira           #+#    #+#             */
/*   Updated: 2021/10/09 13:07:55 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	swap_b(t_stacks *stacks, char sorting, t_input *input)
{
	t_opes	*ope;

	swap(stacks->b, stacks->len_b);
	if (sorting)
	{
		ope = malloc(sizeof(t_opes));
		if (!ope)
			error(input);
		*ope = sb;
		add_ope(ope, input);
	}
}
