/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 20..//10 16:41:44 by avieira           #+#    #+#             */
/*   Updated: 2021/10/09 13:14:56 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	ft_putc_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static void	ft_puts_fd(char *s, int fd)
{
	while (*s)
		ft_putc_fd(*s++, fd);
}

void	ft_putendl_fd(char *s, int fd)
{
	if (s)
	{
		ft_puts_fd(s, fd);
		ft_putc_fd('\n', fd);
	}
}
