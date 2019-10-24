/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_strlen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 13:15:22 by elhampto          #+#    #+#             */
/*   Updated: 2019/10/24 13:15:51 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint			u_strlen(const u_char *s)
{
	uint		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
