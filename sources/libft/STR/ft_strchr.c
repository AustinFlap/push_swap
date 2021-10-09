/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 20..//10 11:40:53 by avieira           #+#    #+#             */
/*   Updated: 2021/10/09 13:41:44 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	d;

	d = c;
	while (*s)
		if (*s++ == d)
			return ((char *)--s);
	if (c == 0)
		return ((char *)s);
	return (NULL);
}
