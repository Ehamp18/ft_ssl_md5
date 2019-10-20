/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 21:59:19 by elhampto          #+#    #+#             */
/*   Updated: 2019/10/19 22:15:03 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_md5.h"

int			main(int ac, char **av)
{
	int		i;
	char	*tmp;
	char	*tmp2;
	t_slfl	fla;
	t_woer	*lst;

	lst = (t_woer*)ft_memalloc(sizeof(t_woer));
	tmp = ft_strnew(BUFF_SIZE);
	ft_bzero(&fla, sizeof(&fla));
	i = 1;
	if (ac >= 2)
		while (av[i])
		{
			if (av[i][0] == '-')
				mdflags(av[i], &fla);
			else
			{
				if ((fla.fd = open(av[i + 1], O_RDONLY)))
				{
					lst->str = ft_strnew(sizeof(char));
					while (read(fla.fd, tmp, BUFF_SIZE) > 0)
					{
						tmp2 = ft_strnew(sizeof(char));
						tmp2 = free_copy(lst->str, tmp2);
						lst->str = ft_strjoin(tmp2, tmp);
						free(tmp2);
					}
				}
				else
					lst->str = ft_strdup(av[i + 1]);
				fla.type = -1;
				lst->word = ft_strdup(av[i + 1]);
				while (++fla.type < 2)
					if (ft_strcmp(av[i], g_check[fla.type].name) == 0)
					{
						g_check[fla.type].funct(lst, &fla);
						free(lst->str);
						break ;
					}
			}
			i++;
		}
	else
		ft_printf("%s\n", ERROR_MESS);
	free(tmp);
	close(fla.fd);
	return (0);
}
