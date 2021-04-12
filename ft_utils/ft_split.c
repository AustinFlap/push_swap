/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:49:28 by avieira           #+#    #+#             */
/*   Updated: 2019/10/18 17:28:49 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		word_count(char const *s, char c)
{
	int n;
	int i;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			n++;
			while (s[i] != c && s[i])
				i++;
		}
		while (s[i] == c && s[i])
			i++;
	}
	return (n);
}

static int		len_to_sep(char const *s, char c, int i)
{
	int l;

	l = 0;
	while (s[i] != c && s[i])
	{
		l++;
		i++;
	}
	return (l);
}

static int		word_create(char const *s, char c, int i, char *split)
{
	int a;

	a = 0;
	while (s[i] != c && s[i])
	{
		split[a] = s[i];
		a++;
		i++;
	}
	split[a] = 0;
	return (i);
}

static void		*free_array(char **split, int j)
{
	int i;

	i = 0;
	while (i <= j)
		free(split[i++]);
	free(split);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	int		j;
	int		n_words;

	if (!s)
		return (NULL);
	n_words = word_count(s, c);
	if (!(split = malloc(sizeof(char *) * (n_words + 1))))
		return (NULL);
	i = 0;
	j = -1;
	while (++j < n_words)
	{
		while (s[i] == c && s[i])
			i++;
		if (!(split[j] = malloc(sizeof(char) * (len_to_sep(s, c, i) + 1))))
			return (free_array(split, j));
		i = word_create(s, c, i, split[j]);
		while (s[i] == c && s[i])
			i++;
	}
	split[j] = NULL;
	return (split);
}
