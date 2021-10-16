/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 21:23:18 by avieira           #+#    #+#             */
/*   Updated: 2021/10/14 17:52:46 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_duplicates(int *list, int idx, int value, t_input *input)
{
	int	i;

	i = -1;
	while (++i < idx)
		if (list[i] == value)
			error(input);
}

void	get_stack(int ac, char **av, t_input *input)
{
	int	i;
	int	j;
	int	*temp;

	i = 0;
	temp = input->stacks.a;
	while (++i < ac)
	{
		j = -1;
		while (av[i][++j])
		{
			if (!(ft_isdigit(av[i][j]) || (av[i][j] == '-' && !j
				&& av[i][j + 1])))
				error(input);
		}
		*temp = ft_atoi_of(av[i], input);
		check_duplicates(input->stacks.a, temp - input->stacks.a, *temp, input);
		temp++;
	}
}
