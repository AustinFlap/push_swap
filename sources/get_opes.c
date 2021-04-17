/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 21:23:18 by avieira           #+#    #+#             */
/*   Updated: 2021/04/17 21:02:33 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_opes			define_ope(char *str_opes[], char *line)
{
	t_opes	i;

	i = -1;
	while (str_opes[++i])
		if (!ft_strncmp(str_opes[i], line, ft_strlen(str_opes[i]) + 1))
			return (i);
	return (-1);
}

void	get_opes(t_input *input)
{
	char	*line;
	char	*str_opes[12] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr",
													"rra", "rrb", "rrr", NULL};
	int		ret;
	t_list	*temp;
	t_opes	*ope;

	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(0, &line);
		if(*line)
		{
			if (!(ope = ft_calloc(sizeof(t_opes), 1)))
				error(input);
			if ((*ope = define_ope(str_opes, line)) == (t_opes)-1)
				error(input);
			if (!(temp = ft_lstnew(ope)))
				error(input);
			if (input->opes)
				ft_lstadd_back(&input->opes, temp);
			else
				input->opes = temp;
		}
		free(line);
	}
}
