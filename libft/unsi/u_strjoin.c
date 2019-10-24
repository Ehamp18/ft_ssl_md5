/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_strjoin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 13:10:23 by elhampto          #+#    #+#             */
/*   Updated: 2019/10/24 13:20:16 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

u_char			*u_strjoin(u_char const *s1, u_char const *s2)
{
	u_char		*str;
	size_t		len;

	if (!s1 || !s2)
		return (NULL);
	len = u_strlen(s1) + u_strlen(s2);
	if (!(str = (u_char*)ft_memalloc(len)))
		return (0);
	u_strcpy(str, s1);
	u_strcat(str, s2);
	return (str);
}
