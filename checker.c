/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 21:23:18 by avieira           #+#    #+#             */
/*   Updated: 2021/04/09 16:44:54 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(int *list)
{
	if (list)
		free(list);
	write(1, "Error\n", 6);
	exit(0);
}

void	get_list(int ac, char **av, int *list)
{
	int	i;
	int	j;
	int *temp;

	i = 0;
	temp = list;
	while (++i < ac)
	{
		j = -1;
		while (av[i][++j])
		{
			if (!(ft_isdigit(av[i][j]) || (av[i][j] == '-' && !j &&
																av[i][j + 1])))
				error(list);
		}
		*temp = ft_atoi_of(av[i], list);
		temp++;
	}
}

void	read_opes(t_opes_list **opes_list)
{
	char	*line;
	char	*str_opes[11] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr",
														"rra", "rrb", "rrr"};

	while (get_next_line(0, &line))
	{
		printf("--%s\n", line);
	}
}

int		main(int ac, char **av)
{
	int	*list;
	t_opes_list *opes_list;

	opes_list = NULL;
	if (!(list = ft_calloc(ac - 1, sizeof(int))))
		error(list);
	get_list(ac, av, list);
	read_opes(&opes_list);
}
