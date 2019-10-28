/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 21:59:26 by elhampto          #+#    #+#             */
/*   Updated: 2019/10/27 17:20:47 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void		lil(uint *j, t_al *in)
{
	uint	value;

	value = 0;
	in->i = 0;
	value += *j & 0xff;
	value = value << 8;
	while (++in->i < 4)
	{
		value += *j >> (in->i * 8) & 0xff;
		if ((in->i * 8) == 24)
			break ;
		value = value << 8;
	}
	*j = value;
}

static void		math(t_al *in)
{
	if (in->i > 0 && in->i < 16) // needs to be >= 0 or it is wrong!!!!
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
}

static void		hash_loop(t_al *in, t_woer *lst)
{
	in->i = -1;
	while (++in->i < 64)
	{
		math(in);
		// in->f = in->f + in->a + g_k[in->i] + *((uint32_t*)lst->bit[in->g]);
		in->f = in->f + in->a + g_k[in->i] + *((uint32_t*)lst->bit[in->g]);
		in->a = in->d;
		in->d = in->c;
		in->c = in->b;
		in->b = in->b + ((in->f << g_s[in->i]) | (in->f >> (32 - g_s[in->i])));
	}
	in->a0 += in->a;
	in->b0 += in->b;
	in->c0 += in->c;
	in->d0 += in->d;
}

void			ft_md5(t_woer *lst, t_slfl *fla)
{
	u_char		*hashed_message;
	t_al		in;

	ft_bzero(&in, sizeof(in));
	ft_assign(&in);
	in.e = 0;
	in.len = u_strlen(lst->str);
	in.block = in.len ? ((in.len + 8) / 64) + 1 : 1;
	hashed_message = malloc(64 * in.block);
	//zeroing out HASHED_MESSAGE may not be necessary 
	//considering the string datatype is unsigned char!
	ft_bzero(hashed_message, (uint32_t)(64 * in.block));
	ft_strcpy((char*)hashed_message, (char*)lst->str);
	printf("chek 1: %s\n", hashed_message);
	printf("chek 2: %s\n", lst->str);
	hashed_message[in.len ? in.len : 0] = 0x80;
	hashed_message = last_eight(&in, hashed_message);
	in.j = -1;
	while (++in.j < in.block)
	{
		bit_split(lst, hashed_message, &in);
		hash_loop(&in, lst);
	}
	lil(&in.a0, &in);
	lil(&in.b0, &in);
	lil(&in.c0, &in);
	lil(&in.d0, &in);
	free(hashed_message);
	!fla->r ? print_flag(fla, lst, &in) : print_rflag(fla, lst, &in);
}
