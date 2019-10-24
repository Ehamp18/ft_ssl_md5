/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_free_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 13:07:14 by elhampto          #+#    #+#             */
/*   Updated: 2019/10/24 13:25:10 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

u_char			*u_free_copy(u_char *com, u_char *tmp)
{
	free(tmp);
	ft_bzero(tmp, u_strlen(tmp));
	tmp = u_strjoin(tmp, com);
	free(com);
	return (tmp);
}
