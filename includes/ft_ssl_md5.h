/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_md5.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 22:01:27 by elhampto          #+#    #+#             */
/*   Updated: 2019/10/14 21:49:05 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_MD5_H
# define FT_SSL_MD5_H

# include "libft.h"

#define ERROR_MESS "usage: ft_ssl command [command opts] [command args]"

typedef	char	(*t_ret)(char *str);

typedef struct	s_type
{
	int			num;
	t_ret		funct;
}				t_type;

typedef struct	s_allints
{
	int			a[3];
	int			b[3];
	int			c[3];
	int			d[3];
	char		n_bit;
}				t_al;

typedef struct	s_sslfl
{
	int			p;
	int			q;
	int			r;
	int			s;
	int			type;
}				t_slfl;

extern int64_t	g_k[];
extern int64_t	g_s[];
extern t_type	g_check;

char			*ft_md5(char *str);
void			mdflags(char *str, t_slfl *fla);

#endif