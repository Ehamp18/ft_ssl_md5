/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 21:59:26 by elhampto          #+#    #+#             */
/*   Updated: 2019/10/23 16:42:20 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_md5.h"

void				bit_split(t_woer *lst, unsigned char *str, t_al *in)
{
	unsigned int	k;
	unsigned int	i;
	int				j;
	unsigned int	z;

	j = -1;
	lst->bit_word = (unsigned char**)ft_memalloc(16);
	while (++j < (int)in->block)
	{
		i = -1;
		while (++i < 16)
		{
			lst->bit_word[i] = (unsigned char*)malloc(sizeof(unsigned char));
			k = -1;
			while (++k < sizeof(unsigned char))
				lst->bit_word[i][k] = 0x0;
			z = -1;
			while (++z < 4)
				lst->bit_word[i][z] = str[(j * 64) + (i * 4) + z];
		}
	}
}

static void			lil(unsigned int *j)
{
	unsigned int	i;
	unsigned int	l;

	i = 0;
	l = 0;
	l += *j & 0xff;
	l = l << 8;
	while (++i < 4)
	{
		l += (*j >> (i * 8)) & 0xFF;
		l = l << 8;
	}
	*j = l;
}

void				ft_md5(t_woer *lst, t_slfl *fla)
{
	unsigned char	*hashed_message;
	t_al			in;
	int				i;
	unsigned int	len;

	ft_bzero(&in, sizeof(in));
	in.a0 = 0x67452301;
	in.b0 = 0xefcdab89;
	in.c0 = 0x98badcfe;
	in.d0 = 0x10325476;
	in.a = in.a0;
	in.b = in.b0;
	in.c = in.c0;
	in.d = in.d0;
	in.e = 0;
	len = ft_strlen(lst->str);
	in.block = (ft_strlen(lst->str + 8) / 64) + 1;
	hashed_message = (unsigned char*)malloc(64 * in.block);
	i = -1;
	while (++i < 64)
		hashed_message[i] = 0x0;
	ft_strcpy((char*)hashed_message, lst->str);
	hashed_message[len] = 128;
	len = len << 3;
	i = -1;
	while (++i < 8)
	{
		if (!(ft_strlen(lst->str) >> (i * 8)))
			break ;
		hashed_message[((64 * in.block) - 8) + i] = len >> (i * 8);
	}
	bit_split(lst, hashed_message, &in);
	while (in.num < in.block)
	{
		in.i = 0;
		ft_printf("before second while\n");
		while (in.i < 64)
		{
			ft_printf("in while: %d\n", in.i);
			if (in.i > 0 && in.i < 16)
			{
				in.f = (in.b & in.c) | ((~in.b) & in.d);
				in.g = in.i;
			}
			else if (in.i >= 16 && in.i < 32)
			{
				in.f = (in.d & in.b) | ((~in.d) & in.c);
				in.g = ((5 * in.i) + 1) % 16;
			}
			else if (in.i >= 32 && in.i < 48)
			{
				in.f = (in.b ^ in.c ^ in.d);
				in.g = ((3 * in.i) + 5) % 16;
			}
			else
			{
				in.f = in.c ^ (in.b | (~in.d));
				in.g = (7 * in.i) % 16;
			}
			in.f = in.f + in.a + g_k[in.i] + *((unsigned int*)lst->bit_word[in.g]);
			in.a = in.d;
			in.d = in.c;
			in.c = in.b;
			in.b = in.b + ((in.f << g_s[in.i]) | (in.f >> (32 - g_s[in.i])));
			free(lst->bit_word[in.g]);
			ft_printf("before i++\n");
			in.i++;
		}
		in.a0 += in.a;
		in.b0 += in.b;
		in.c0 += in.c;
		in.d0 += in.d;
		in.num++;
	}
	ft_printf("end\n");
	lil(&in.a0);
	lil(&in.b0);
	lil(&in.c0);
	lil(&in.d0);

	free(hashed_message);
	if (!fla->r)
		print_flag(fla, lst, &in);
	else
		print_rflag(fla, lst, &in);
	free(lst->bit_word);
}
