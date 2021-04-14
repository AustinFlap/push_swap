/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 20..//10 16:20:09 by avieira           #+#    #+#             */
/*   Updated: 20..//18 14:06:04 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	ft_strl(const char *s)
{
	int l;

	l = 0;
	while (*s++)
		l++;
	return (l);
}

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		l;
	char	*result;
	int		i;

	if (!s)
		return (NULL);
	l = ft_strl(s);
	if (!(result = malloc(sizeof(char) * (l + 1))))
		return (NULL);
	i = -1;
	while (++i < l)
		result[i] = (*f)(i, s[i]);
	result[i] = 0;
	return (result);
}
