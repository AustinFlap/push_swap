/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 23:58:03 by avieira           #+#    #+#             */
/*   Updated: 2021/09/30 04:12:52 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int				main(int ac, char **av)
{
	t_input		input;

	if (ac - 1)
	{
		alloc_input(&input, ac);
		get_stack(ac, av, &input);
		transform_stack(&input);
		sort_stack(&input);

		printf("opes pointer : %p\nLIST :", input.opes);
		while (input.opes)
		{
			printf("-%d-", *(int *)input.opes->content);
			input.opes = input.opes->next;
		}
		printf("\n");
	}
}
