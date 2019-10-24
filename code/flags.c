/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 19:55:29 by elhampto          #+#    #+#             */
/*   Updated: 2019/10/24 11:41:31 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

/*
** • -p, echo STDIN to STDOUT and append the checksum to STDOUT
** • -q, quiet mode
** • -r, reverse the format of the output.
** • -s, print the sum of the given string
*/

void		print_flag(t_slfl *fla, t_woer *lst, t_al *in)
{
	if (!fla->s)
	{
		if (!fla->q)
			ft_printf("MD5 (%s) = ", lst->word);
		ft_printf("%.8x%.8x%.8x%.8x\n", in->a0, in->b0, in->c0, in->d0);
	}
	else
	{
		if (!fla->q)
			ft_printf("MD5 (\"%s\") = ", lst->word);
		ft_printf("%.8x%.8x%.8x%.8x\n", in->a0, in->b0, in->c0, in->d0);
	}
}

void		print_rflag(t_slfl *fla, t_woer *lst, t_al *in)
{
	if (!fla->s)
	{
		ft_printf("%.8x%.8x%.8x%.8x ", in->a0, in->b0, in->c0, in->d0);
		if (!fla->q)
			ft_printf("%s\n", lst->word);
	}
	else
	{
		ft_printf("%.8x%.8x%.8x%.8x ", in->a0, in->b0, in->c0, in->d0);
		if (!fla->q)
			ft_printf("%s\n", lst->word);
	}
}

void		mdflags(char *str, t_slfl **fla)
{
	int		i;

	i = 1;
	while (str[i])
	{
		(*fla)->p = (str[i] == 'p') ? 112 : (*fla)->p;
		(*fla)->q = (str[i] == 'q') ? 113 : (*fla)->q;
		(*fla)->r = (str[i] == 'r') ? 114 : (*fla)->r;
		(*fla)->s = (str[i] == 's') ? 115 : (*fla)->s;
		if (str[i] != 'p' && str[i] != 'q' && str[i] != 'r' &&
			str[i] != 's')
			ft_printf("Error: %c is not a flag!\n", str[i]);
		i++;
	}
}
