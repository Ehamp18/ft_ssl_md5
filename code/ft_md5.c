/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 21:59:26 by elhampto          #+#    #+#             */
/*   Updated: 2019/10/24 20:46:41 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void		lil(uint *j)
{
	*j = (*j >> 24) | ((*j << 8) & 0x00ff0000) |
		((*j >> 8) & 0x0000ff00) | (*j << 24);
}

static void		hash_loop(t_al *in, t_woer *lst)
{
	while (in->num < in->block)
	{
		in->i = 0;
		while (in->i < 64)
		{
			if (in->i > 0 && in->i < 16)
			{
				in->f = (in->b & in->c) | ((~in->b) & in->d);
				in->g = in->i;
			}
			else if (in->i >= 16 && in->i < 32)
			{
				in->f = (in->d & in->b) | ((~in->d) & in->c);
				in->g = ((5 * in->i) + 1) % 16;
			}
			else if (in->i >= 32 && in->i < 48)
			{
				in->f = (in->b ^ in->c ^ in->d);
				in->g = ((3 * in->i) + 5) % 16;
			}
			else
			{
				in->f = in->c ^ (in->b | (~in->d));
				in->g = (7 * in->i) % 16;
			}
			in->f = in->f + in->a + g_k[in->i] + *lst->bit[in->g];
			in->a = in->d;
			in->d = in->c;
			in->c = in->b;
			in->b = in->b + left_rot(in, g_s[in->i]);
			in->i++;
		}
		in->a0 += in->a;
		in->b0 += in->b;
		in->c0 += in->c;
		in->d0 += in->d;
		in->num++;
	}
}

void			ft_md5(t_woer *lst, t_slfl *fla)
{
	u_char		*hashed_message;
	t_al		in;

	ft_bzero(&in, sizeof(in));
	ft_assign(&in);
	in.e = 0;
	in.len = u_strlen(lst->str);
	in.block = (u_strlen(lst->str + 8) / 64) + 1;
	hashed_message = (u_char*)malloc(64 * in.block);
	clean(hashed_message, &in, 64);
	u_strcpy(hashed_message, lst->str);
	hashed_message[in.len] = 128;
	hashed_message = last_eight(&in, hashed_message, lst);
	bit_split(lst, hashed_message, &in);
	hash_loop(&in, lst);
	lil(&in.a0);
	lil(&in.b0);
	lil(&in.c0);
	lil(&in.d0);
	free(hashed_message);
	!fla->r ? print_flag(fla, lst, &in) : print_rflag(fla, lst, &in);
	free(lst->bit);
}

/*
** ft_printf("check: %.8x%.8x%.8x%.8x\n", in.a, in.b, in.c, in.d);
*/
