/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 21:23:18 by avieira           #+#    #+#             */
/*   Updated: 2021/04/16 22:04:09 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	get_stack(int ac, char **av, int *a)
{
	int	i;
	int	j;
	int *temp;

	i = 0;
	temp = a;
	while (++i < ac)
	{
		j = -1;
		while (av[i][++j])
		{
			if (!(ft_isdigit(av[i][j]) || (av[i][j] == '-' && !j &&
																av[i][j + 1])))
				error();
		}
		*temp = ft_atoi_of(av[i]);
		temp++;
	}
}
