/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_strdup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 13:27:40 by elhampto          #+#    #+#             */
/*   Updated: 2019/10/24 14:08:45 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

u_char			*u_strdup(const char *src)
{
	u_char *dup;

	if (!src || !(dup = (u_char*)malloc(sizeof(*dup) * (ft_strlen(src) + 1))))
		return (NULL);
	dup = u_strcpy(dup, (u_char*)src);
	return (dup);
}
