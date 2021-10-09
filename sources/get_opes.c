/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 21:23:18 by avieira           #+#    #+#             */
/*   Updated: 2021/10/09 13:54:31 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_opes	define_ope(char *str_opes[], char *line)
{
	t_opes	i;

	i = -1;
	while (str_opes[++i])
		if (!ft_strncmp(str_opes[i], line, ft_strlen(str_opes[i]) + 1))
			return (i);
	return (-1);
}

void	set_ope_str(char *str_opes[12])
{
	str_opes[0] = "sa";
	str_opes[1] = "sb";
	str_opes[2] = "ss";
	str_opes[3] = "pa";
	str_opes[4] = "pb";
	str_opes[5] = "ra";
	str_opes[6] = "rb";
	str_opes[7] = "rr";
	str_opes[8] = "rra";
	str_opes[9] = "rrb";
	str_opes[10] = "rrr";
	str_opes[11] = NULL;
}

void	get_new_ope(t_input *input, char *str_opes[12], char *line)
{
	t_opes	*ope;
	t_list	*temp;

	ope = ft_calloc(sizeof(t_opes), 1);
	if (!ope)
		error(input);
	*ope = define_ope(str_opes, line);
	if (*ope == (t_opes)-1)
		error(input);
	temp = ft_lstnew(ope);
	if (!temp)
		error(input);
	if (input->opes)
		ft_lstadd_back(&input->opes, temp);
	else
		input->opes = temp;
}

void	get_opes(t_input *input)
{
	char	*line;
	char	*str_opes[12];
	int		ret;

	set_ope_str(str_opes);
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(0, &line);
		if (*line)
			get_new_ope(input, str_opes, line);
		free(line);
	}
}
