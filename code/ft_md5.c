/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 21:59:26 by elhampto          #+#    #+#             */
/*   Updated: 2019/10/19 20:28:36 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_md5.h"
#define a0 in.a[0]
#define b0 in.b[0]
#define c0 in.c[0]
#define d0 in.d[0]

#define A in.a[1]
#define B in.b[1]
#define C in.c[1]
#define D in.d[1]

#define I in.a[2]
#define F in.b[2]
#define G in.c[2]
#define LEN in.d[2]

static int			move(point, c)
{
	return (point << c) | (point >> (32-c));
}

// void				bit_split(t_woer *lst, char *str)
// {}

void				ft_md5(t_woer *lst, t_slfl *fla)
{
	char			digest[16];
	unsigned char	*hashed_message;
	t_al			in;
	(void)fla;

	ft_bzero(&in, sizeof(&in));
	a0 = 0x67452301;
	b0 = 0xefcdab89;
	c0 = 0x98badcfe;
	d0 = 0x10325476;
	in.e = 0;
	LEN = ((unsigned int)ft_strlen(lst->str + 8) / 64) + 1;
	hashed_message = (unsigned char*)ft_memalloc(64 * LEN);
	hashed_message = (unsigned char*)ft_strcat((char*)hashed_message, lst->str);
	hashed_message[ft_strlen(lst->str)] = (char)128;
	in.n_bit =(unsigned int)ft_strlen(lst->str) * 8;
	hashed_message[ft_strlen((char*)hashed_message) - 8] = in.n_bit;
	// bit_split(lst, hashed_message);
	while (in.e < LEN) //each 512-bit chunk of padded message
	{
		// break chunk into sixteen 32-bit words M[j], 0 ≤ j ≤ 15;
		A = a0;
		B = b0;
		C = c0;
		D = d0;
		I = 0;
		while (I < 64)
		{
			if (I <= 15)
			{
				F = ((B & C) | (~B & D));	
				G = I;
			}
			else if (I >= 16 & I <= 31)
			{
				F = ((D & B) | (~D & C));
				G = ((5 * I) + 1) % 16;
			}
			else if (I >= 32 & I <= 47)
			{
				F = (B ^ C ^ D);
				G = ((3 * I) + 5) % 16;
			}
			else if (I >= 48 & I <= 63)
			{
				F = (C ^ (B | ~D));
				G = (7 * I) % 16;
			}
			F = F + A + g_k[I] + hashed_message[G];
			A = D;
			D = C;
			C = B;
			B = B + move(F, g_s[I]);
			I++;
		}
		a0 += A;
		b0 += B;
		c0 += C;
		d0 += D;
		in.e++;
	}
	ft_printf("combined: |%02x%02x%02x%02x|\n", a0, b0, c0, d0);
	digest[0] = a0;
	digest[4] = b0;
	digest[8] = c0;
	digest[12] = d0;
	free(hashed_message);
	ft_printf("MD5 (%s) = |%02x|\n", lst->word, digest);
}
