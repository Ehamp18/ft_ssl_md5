/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 22:01:27 by elhampto          #+#    #+#             */
/*   Updated: 2019/10/27 16:55:46 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include "libft.h"
# include <stdio.h>
# define ERROR_MESS "usage: ft_ssl command [command opts] [command args]"
# define NO_FILE_ST "usage: ft_ssl command no input file or string"

typedef struct		s_allints
{
	uint32_t		a;
	uint32_t		b;
	uint32_t		c;
	uint32_t		d;
	uint32_t		a0;
	uint32_t		b0;
	uint32_t		c0;
	uint32_t		d0;
	uint32_t		len;
	uint32_t		f;
	uint32_t		e;
	uint32_t		g;
	uint32_t		j;
	uint32_t		i;
	uint32_t		num;
	uint32_t		block;
	u_char			n_bit;
}					t_al;

typedef struct		s_word_holder
{
	uint32_t		i;
	u_char			*str;
	u_char			*conv;
	u_char			*word;
	u_char			bit[16][4];
}					t_woer;

typedef struct		s_sslfl
{
	uint32_t		p;
	uint32_t		q;
	uint32_t		r;
	uint32_t		s;
	uint32_t		type;
	int				fd;
	int				val;
}					t_slfl;

typedef	void		(*t_ret)(t_woer *lst, t_slfl *fla);

typedef struct		s_type
{
	char			*name;
	t_ret			funct;
}					t_type;

extern uint32_t		g_k[64];
extern uint32_t		g_s[64];
extern t_type		g_check[];

void				ft_md5(t_woer *lst, t_slfl *fla);
void				ft_sha256(t_woer *lst, t_slfl *fla);
void				mdflags(char *str, t_slfl **fla);
void				print_rflag(t_slfl *fla, t_woer *lst, t_al *in);
void				print_flag(t_slfl *fla, t_woer *lst, t_al *in);
void				bit_split(t_woer *lst, u_char *str, t_al *in);
void				ft_assign(t_al *in);
void				*clean(u_char *str, t_al *in, uint32_t times);
u_char				*last_eight(t_al *in, u_char *msg);

#endif
