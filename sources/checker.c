/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 21:23:18 by avieira           #+#    #+#             */
/*   Updated: 2021/10/09 13:01:40 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_input	input;

	if (ac - 1)
	{
		alloc_input(&input, ac);
		get_stack(ac, av, &input);
		get_opes(&input);
		exec_opes(&input);
		check_stacks(input.stacks.a, input.stacks.len_a, input.stacks.len_b);
		free_input(&input);
	}
}
