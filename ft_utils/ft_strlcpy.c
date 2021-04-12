/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:12:38 by avieira           #+#    #+#             */
/*   Updated: 2019/10/18 17:21:00 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strl(const char *s)
{
	int l;

	if (!s)
		return (0);
	l = 0;
	while (*s++)
		l++;
	return (l);
}

size_t			ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t i;

	i = 0;
	if (dstsize && src && dst)
	{
		while (i < dstsize - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	return (ft_strl(src));
}
