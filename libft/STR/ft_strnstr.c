/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 20..//11 15:02:43 by avieira           #+#    #+#             */
/*   Updated: 20..//14 17:10:22 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
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
	while (big[i] != '\0' && i < len)
	{
		while (big[i + j] == little[j] && i + j < len)
			if (j++ == len_to_find)
				return ((char *)big + i);
		j = 0;
		i++;
	}
	return (NULL);
}
