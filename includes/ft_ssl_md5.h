/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_md5.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 22:01:27 by elhampto          #+#    #+#             */
/*   Updated: 2019/10/19 19:32:50 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_MD5_H
# define FT_SSL_MD5_H

# include "libft.h"

#define ERROR_MESS "usage: ft_ssl command [command opts] [command args]"

typedef struct	s_allints
{
	uint64_t	a[3];
	uint64_t	b[3];
	uint64_t	c[3];
	uint64_t	d[3];
	uint64_t	e;
	char		n_bit;
}				t_al;

typedef struct	s_word_holder
{
	char		*str;
	char		*word;
	char		**bit_word;
}				t_woer;

typedef struct	s_sslfl
{
	uint64_t	p;
	uint64_t	q;
	uint64_t	r;
	uint64_t	s;
	uint64_t	type;
	uint64_t	fd;
}				t_slfl;

typedef	void	(*t_ret)(t_woer *lst, t_slfl *fla);

typedef struct	s_type
{
	char		*name;
	t_ret		funct;
}				t_type;

extern int64_t	g_k[];
extern int64_t	g_s[];
extern t_type	g_check[];

void			ft_md5(t_woer *lst, t_slfl *fla);
void			ft_sha256(t_woer *lst, t_slfl *fla);
void			mdflags(char *str, t_slfl *fla);

#endif
