/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:12:37 by avieira           #+#    #+#             */
/*   Updated: 2020/02/02 19:41:13 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct	s_flag
{
	int			width;
	int			precision;
	int			zero;
	int			minus;
	char		format;
}				t_flag;

void			replace(char *a, char *b);
void			str_toupper(char *a);
void			place_front(char *a, char b);
int				max(int a, int b);
void			write_conversion(int *a, char *b, t_flag c);
char			*alloc_print(int a, int b);
void			c(t_flag a, int *b, char *c);
void			s(t_flag a, int *b, char *c);
void			p(t_flag a, int *b, char *c);
void			di(t_flag a, int *b, char *c);
void			u(t_flag a, int *b, char *c);
void			xx(t_flag a, int *b, char *c);
void			mod(t_flag a, int *b, char *c);
int				ft_isdigit(int a);
int				ft_atoi(const char *a);
int				ft_strlen(const char *s);
void			*ft_memset(void *a, int b, size_t c);
void			*ft_calloc(size_t a, size_t b);
void			*ft_memcpy(void *a, const void *b, size_t c);
char			*ft_itoa(long int a);
char			*ft_convert_to_hex(unsigned long int a, char *b);
int				width(const char *a, char b, va_list c);
int				precision(const char *a, char b, va_list c);
int				zero(const char *a, char b);
int				minus(const char *a, char b);
int				ft_printf(const char *str, ...);

#endif
