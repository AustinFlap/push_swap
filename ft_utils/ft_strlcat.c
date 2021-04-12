/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:36:49 by avieira           #+#    #+#             */
/*   Updated: 2019/10/14 17:44:25 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t l_src;
	size_t l_dest;

	i = 0;
	j = 0;
	while (src[j] != '\0')
		j++;
	l_src = j;
	j = 0;
	while (dst[i] != '\0')
		i++;
	l_dest = i;
	while (src[j] != '\0' && size > 0 && i < size - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (size > 0 && i < size)
		dst[i] = '\0';
	if (i >= size)
		return (size + l_src);
	return (l_dest + l_src);
}
