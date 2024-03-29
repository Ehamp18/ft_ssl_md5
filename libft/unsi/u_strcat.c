/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_strcat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 13:19:00 by elhampto          #+#    #+#             */
/*   Updated: 2019/10/24 13:20:50 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

u_char			*u_strcat(u_char *s1, const u_char *s2)
{
	uint			i;
	uint			o;

	o = 0;
	i = 0;
	while (s1[i])
		i++;
	while (s2[o] != '\0')
	{
		s1[i + o] = s2[o];
		o++;
	}
	s1[i + o] = '\0';
	return (s1);
}
