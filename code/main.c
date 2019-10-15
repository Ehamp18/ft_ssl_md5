/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 21:59:19 by elhampto          #+#    #+#             */
/*   Updated: 2019/10/14 21:51:44 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_md5.h"

int			main(int ac, char **av)
{
	int		i;
	char	*hash;
	t_slfl	fla;

	fla.type = 0;
	ft_bzero(&fla, sizeof(&fla));
	i = 1;
	if (ac >= 2)
	{
		while (av[i])
		{
			if (av[i][0] == '-')
			{
				mdflags(av[i], &fla);
			}
			else
			{
				fla.type = (av[i] == "md5") ? 1 : fla.type;
				fla.type = (av[i] == "sha256") ? 2 : fla.type;
				if (open(av[i], O_RDONLY) >= 3)
				{
					if (!(hash = g_check[fla.type].funct(av[i])))
					{
						ft_printf("%s\n", ERROR_MESS);
						return (0);
					}
					// hash = ft_md5(av[i]);
					ft_printf("MD5(%s) = %s\n", av[i], hash);
					free(hash);
				}
				else
					return (-1);
			}
			i++;
		}
	}
	else
		ft_printf("%s\n", ERROR_MESS);
	return (0);
}