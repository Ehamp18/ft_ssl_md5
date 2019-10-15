/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 21:59:26 by elhampto          #+#    #+#             */
/*   Updated: 2019/10/14 15:36:14 by elhampto         ###   ########.fr       */
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

static int		leftrotate (x, c)
{
	return (x << c) | (x >> (32-c));
}

static int		get_len(char *str)
{
	int			i;

	i = ((int)ft_strlen(str) + 9) / 64; // check later to make sure it works
	return (i + 1);
}

static char		get_e_bites(char *str) //not done
{
	int			i;
	char		tmp;

	i = (int)ft_strlen(str) * 8;
	tmp = i;
	return (tmp);
}

char			*end_add_on(char *str, char c)
{
	int			i;

	i = ft_strlen(str) - 8;
	str[i] = c;
	// while (i != (int)ft_strlen(str))
	// {
	// 	str[i] = c;
	// 	i++;
	// }
	return (str);
}

char			*ft_md5(char *str)
{
	char	digest[16];
	char	*tmp;
	char	*hashed_message;
	t_al	in;

	ft_bzero(&in, sizeof(&in));
	a0 = 0x67452301;
	b0 = 0xefcdab89;
	c0 = 0x98badcfe;
	d0 = 0x10325476;
	I = 0;
	F = 0;
	G = 0;
	LEN = get_len(str);
	if (!(hashed_message = (char*)ft_memalloc(64 * LEN)))
		return (NULL);
	tmp = ft_itoa_base(ft_atoi(str), 16);
	hashed_message = ft_strcat(hashed_message, tmp);
	hashed_message[ft_strlen(tmp)] = (char)128;
	in.n_bit = get_e_bites(str);
	hashed_message = end_add_on(hashed_message, in.n_bit); //append original length in bits mod 264 to message;
	while (hashed_message[I]) //each 512-bit chunk of padded message
	{
		// break chunk into sixteen 32-bit words M[j], 0 ≤ j ≤ 15;
		A = a0;
		B = b0;
		C = c0;
		D = d0;
		while (I > 63)
		{
			if (I <= 15)
			{
				F = ((B && C) | (~B && D));	
				G = I;
			}
			else if (16 <= I && I <= 31)
			{
				F = ((D && B) | (~D && C));
				G = ((5 * I) + 1) % 16;
			}
			else if (32 <= I && I <= 47)
			{
				F = (B ^ C ^ D);
				G = ((3 * I) + 5) % 16;
			}
			else if (48 <= I && I <= 63)
			{
				F = (C ^ (B | ~D));
				G = (7 * I) % 16;
			}
			F = F + A + g_k[I] + hashed_message[G];
			A = D;
			D = C;
			C = B;
			B = B + leftrotate(F, g_s[I]);
			I++;
		}
		a0 += A;
		b0 += B;
		c0 += C;
		d0 += D;
	}
	// digest = a0 append b0 append c0 append d0; //(Output is in little-endian)
	digest[0] = a0;
	digest[4] = b0;
	digest[8] = c0;
	digest[12] = d0;
	free(hashed_message);
	return (ft_strdup(digest));
}
