/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 19:50:05 by avieira           #+#    #+#             */
/*   Updated: 2019/10/17 18:38:37 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*t_dst;
	const unsigned char	*t_src;
	int					i;
	int					p_diff;

	if (!dst && !src)
		return (NULL);
	t_dst = dst;
	t_src = src;
	p_diff = (t_dst > t_src) ? -1 : 1;
	i = (t_dst > t_src) ? len - 1 : 0;
	while ((size_t)i < len && i > -1)
	{
		t_dst[i] = t_src[i];
		i += p_diff;
	}
	return (dst);
}
