/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_md5.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 22:01:27 by elhampto          #+#    #+#             */
/*   Updated: 2019/10/23 15:16:48 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_MD5_H
# define FT_SSL_MD5_H

# include "libft.h"
# define ERROR_MESS "usage: ft_ssl command [command opts] [command args]"
# define NO_FIle_ST "usage: ft_ssl command no input file or string"

typedef struct			s_allints
{
	unsigned int		a;
	unsigned int		b;
	unsigned int		c;
	unsigned int		d;
	unsigned int		a0;
	unsigned int		b0;
	unsigned int		c0;
	unsigned int		d0;
	int					num;
	unsigned int		i;
	unsigned int		f;
	unsigned int		g;
	int					block;
	unsigned int		e;
	char				n_bit;
}						t_al;

typedef struct			s_word_holder
{
	unsigned int		i;
	char				*str;
	unsigned char		*conv;
	char				*word;
	unsigned char		**bit_word;
}						t_woer;

typedef struct			s_sslfl
{
	unsigned int		p;
	unsigned int		q;
	unsigned int		r;
	unsigned int		s;
	unsigned int		type;
	int					fd;
}						t_slfl;

typedef	void	(*t_ret)(t_woer *lst, t_slfl *fla);

typedef struct			s_type
{
	char				*name;
	t_ret				funct;
}						t_type;

extern unsigned int	g_k[];
extern unsigned int	g_s[];
extern t_type	g_check[];

void					ft_md5(t_woer *lst, t_slfl *fla);
void					ft_sha256(t_woer *lst, t_slfl *fla);
void					mdflags(char *str, t_slfl **fla);
void					print_rflag(t_slfl *fla, t_woer *lst, t_al *in);
void					print_flag(t_slfl *fla, t_woer *lst, t_al *in);

#endif
