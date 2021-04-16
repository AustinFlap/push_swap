/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 21:23:18 by avieira           #+#    #+#             */
/*   Updated: 2021/04/16 22:28:57 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	define_ope(char *str_opes[], char *line, t_list *temp)
{
	t_opes	i;

	i = -1;
	while (str_opes[++i])
	{
		if (!ft_strncmp(str_opes[i], line, ft_strlen(str_opes[i]) + 1))
		{
			if (!(temp->content = ft_calloc(sizeof(t_opes), 1)))
				error();
			*((t_opes *)temp->content) = i;
			return ;
		}
	}
	error();
}

void	get_opes(t_list **opes)
{
	char	*line;
	char	*str_opes[12] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr",
													"rra", "rrb", "rrr", NULL};
	t_list	*temp;
	int		ret;

	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(0, &line);
		if(*line)
		{
			if (!(temp = ft_lstnew(line)))
				error();
			if (*opes)
				ft_lstadd_back(opes, temp);
			else 
				*opes = temp;
			define_ope(str_opes, line, temp);
		}
	}
}
