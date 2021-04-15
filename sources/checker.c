/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 21:23:18 by avieira           #+#    #+#             */
/*   Updated: 2021/04/14 14:04:09 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

	(void)opes_list;
	(void)str_opes;
	while (get_next_line(0, &line))
	{
	//	if (*opes_list)
	//		*opes_list = (struct s_opes_list)ft_lstnew(line);
	}
}

int		main(int ac, char **av)
{
	int	*list;
	t_opes_list *opes_list;

	ft_printf("LOL JE TEST\n");
	opes_list = NULL;
	if (!(list = ft_calloc(ac - 1, sizeof(int))))
		error(list);
	get_list(ac, av, list);
	read_opes(&opes_list);
}
