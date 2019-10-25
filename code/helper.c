/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 11:40:17 by elhampto          #+#    #+#             */
/*   Updated: 2019/10/24 20:43:43 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void			bit_split(t_woer *lst, u_char *str, t_al *in)
{
	// int			k;
	int			i;
	int			j;
	int			z;

	j = -1;
	lst->bit = (u_char**)ft_memalloc(17);
	while (++j < in->block)
	{
		i = -1;
		while (lst->bit[++i])
		{
			lst->bit[i] = (u_char*)ft_memalloc(sizeof(u_char) * 5);
			// k = -1;
			// while (++k < 6)
			// 	lst->bit[i][k] = 0x0;
			z = -1;
			while (lst->bit[i][++z])
				lst->bit[i][z] = (uint)str[(j * 64) + (i * 4) + z];
		}
	}
}

void			ft_assign(t_al *in)
{
	in->a0 = 0x67452301;
	in->b0 = 0xefcdab89;
	in->c0 = 0x98badcfe;
	in->d0 = 0x10325476;
	in->a = in->a0;
	in->b = in->b0;
	in->c = in->c0;
	in->d = in->d0;
}

void			*clean(u_char *str, t_al *in, uint times)
{
	in->j = -1;
	while (++in->j < times)
		str[in->j] = 0x0;
	return (str);
}

uint			left_rot(t_al *in, uint y)
{
	return ((in->f << y) | (in->f >> (32 - y)));
}

u_char			*last_eight(t_al *in, u_char *msg, t_woer *lst)
{
	in->j = -1;
	in->len = in->len << 3;
	while (++in->j < 8)
	{
		BREAK(!(u_strlen(lst->str) >> (in->j * 8)));
		msg[((64 * in->block) - 8) + in->j] = in->len >> (in->j * 8);
	}
	return (msg);
}
