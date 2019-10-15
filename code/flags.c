/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 19:55:29 by elhampto          #+#    #+#             */
/*   Updated: 2019/10/14 15:43:41 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_md5.h"

/*
** • -p, echo STDIN to STDOUT and append the checksum to STDOUT
** • -q, quiet mode
** • -r, reverse the format of the output.
** • -s, print the sum of the given string
*/

void		mdflags(char *str, t_slfl *fla)
{
	int		i;

	i = 1;
	while (str[i])
	{
		fla->p = (str[i] == 'p')? 112 : fla->p;
		fla->q = (str[i] == 'q')? 113 : fla->q;
		fla->r = (str[i] == 'r')? 114 : fla->r;
		fla->s = (str[i] == 's')? 115 : fla->s;
		if (str[i] != 'p' && str[i] != 'q' && str[i] != 'r' && str[i] != 's')
			ft_printf("Error: %c is not a flag!\n", str[i]);
		i++;
	}
}
