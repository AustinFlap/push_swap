/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 12:17:27 by avieira           #+#    #+#             */
/*   Updated: 2019/10/10 13:25:43 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		d;
	const char	*start;

	d = c;
	start = s;
	while (*s)
		s++;
	if (c == 0)
		return ((char *)s);
	while (s >= start)
		if (*s-- == d)
			return ((char *)++s);
	return (NULL);
}
