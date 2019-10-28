/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 11:40:17 by elhampto          #+#    #+#             */
/*   Updated: 2019/10/27 16:55:56 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void			bit_split(t_woer *lst, u_char *str, t_al *in)
{
	uint32_t			i;
	uint32_t			z;

	i = -1;
	while (++i < 16)
	{
		z = -1;
		while (++z < 4)
			lst->bit[i][z] = str[(in->j * 64) + (i * 4) + z];
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

void			*clean(u_char *str, t_al *in, uint32_t times)
{
	in->j = -1;
	while (++in->j < times)
		str[in->j] = 0x0;
	return (str);
}

u_char			*last_eight(t_al *in, u_char *msg)
{
	in->len = in->len << 3;
	in->j = -1;	
	while (++in->j < 8)
	{
		BREAK(!(in->len >> (in->j * 8)));
		msg[((64 * in->block) - 8) + in->j] = in->len >> (in->j * 8);
	}
	return (msg);
}
