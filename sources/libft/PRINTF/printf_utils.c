/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 20:44:21 by avieira           #+#    #+#             */
/*   Updated: 2021/04/14 13:42:29 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void		str_toupper(char *str)
{
	while (*str)
	{
		if (*str >= 97 && *str <= 122)
			*str -= 32;
		str++;
	}
	return ;
}

static char	*ft_strnstr_in_zero(const char *big, const char *little, size_t len)
{
	size_t		len_to_find;
	size_t		i;
	size_t		j;

	j = 0;
	i = 0;
	while (little[j] != '\0')
		j++;
	len_to_find = j - 1;
	if (j == 0)
		return ((char *)big);
	j = 0;
	while ((big[i] == '0' || big[i] == little[j]) && i < len)
	{
		while (big[i + j] == little[j] && i + j < len)
			if (j++ == len_to_find)
				return ((char *)big + i);
		j = 0;
		i++;
	}
	return (NULL);
}

void		replace(char *print, char *to_move)
{
	char	*place;
	int		l_to_move;

	l_to_move = ft_strlen(to_move);
	place = ft_strnstr_in_zero(print, to_move, ft_strlen(print));
	if (place)
	{
		ft_memset(place, '0', l_to_move);
		ft_memcpy(print, to_move, l_to_move);
	}
}
