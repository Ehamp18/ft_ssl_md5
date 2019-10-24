/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 22:01:27 by elhampto          #+#    #+#             */
/*   Updated: 2019/10/24 12:46:38 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include "libft.h"
# define ERROR_MESS "usage: ft_ssl command [command opts] [command args]"
# define NO_FILE_ST "usage: ft_ssl command no input file or string"

typedef struct		s_allints
{
	uint			a;
	uint			b;
	uint			c;
	uint			d;
	uint			a0;
	uint			b0;
	uint			c0;
	uint			d0;
	uint			len;
	uint			i;
	uint			j;
	uint			f;
	uint			e;
	uint			g;
	int				num;
	int				block;
	char			n_bit;
}					t_al;

typedef struct		s_word_holder
{
	uint			i;
	u_char			*str;
	u_char			*conv;
	char			*word;
	u_char			**bit;
}					t_woer;

typedef struct		s_sslfl
{
	uint			p;
	uint			q;
	uint			r;
	uint			s;
	uint			type;
	int				fd;
}					t_slfl;

typedef	void		(*t_ret)(t_woer *lst, t_slfl *fla);

typedef struct		s_type
{
	char			*name;
	t_ret			funct;
}					t_type;

extern uint			g_k[];
extern uint			g_s[];
extern t_type		g_check[];

void				ft_md5(t_woer *lst, t_slfl *fla);
void				ft_sha256(t_woer *lst, t_slfl *fla);
void				mdflags(char *str, t_slfl **fla);
void				print_rflag(t_slfl *fla, t_woer *lst, t_al *in);
void				print_flag(t_slfl *fla, t_woer *lst, t_al *in);
void				bit_split(t_woer *lst, u_char *str, t_al *in);
void				ft_assign(t_al *in);
void				*clean(u_char *str, t_al *in, uint times);
uint				left_rot(t_al *in, uint y);
void				last_eight(t_al *in, u_char **msg, t_woer *lst);

#endif
