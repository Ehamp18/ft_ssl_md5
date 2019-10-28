/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 21:59:19 by elhampto          #+#    #+#             */
/*   Updated: 2019/10/27 17:23:48 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

#define I lst->i

void				ma_loop(t_slfl *fla, t_woer *lst)
{
	fla->type = -1;
	while (++fla->type < 2)
		if (ft_strcmp((char*)lst->conv, g_check[fla->type].name) == 0)
		{
			if (lst->word == NULL || !lst->word)
			{
				printf("%s\n", NO_FILE_ST);
				return ;
			}
			g_check[fla->type].funct(lst, fla);
			break ;
		}
}

void				first_loop(char **av, t_slfl *fla, t_woer *lst)
{
	I = 0;
	while (av[++I])
	{
		if (av[I][0] == '-')
			mdflags(av[I], &fla);
		else if (!fla->s && ft_strcmp(av[1], av[I]) != 0)
		{
			fla->fd = open(av[I], O_RDONLY);
			if (fla->fd)
			{
				lst->word = (u_char*)ft_strdup(av[I]);
				//mike mentioned mallocing for the length of the string
				//in case the file contents string ends up being longer than
				lst->str = (u_char*)ft_memalloc(64);
				while ((fla->val = read(fla->fd, lst->str, 64)) > 0)
				{
					ma_loop(fla, lst);
					free(lst->str);
				}
				free(lst->word);
			}
			else
				printf("value inputed is a string. Add flag \"-s\"\n");
			close(fla->fd);
		}
		else if (fla->s && ft_strcmp(av[1], av[I]) != 0)
		{
			lst->str = (u_char*)ft_strdup(av[I]);
			lst->word = (u_char*)ft_strdup(av[I]);
			ma_loop(fla, lst);
			just_free((char*)lst->word, (char*)lst->str);
		}
	}
}

int					main(int ac, char **av)
{
	t_slfl	fla;
	t_woer	lst;

	lst.conv = (u_char*)ft_strdup(av[1]);
	if (ac >= 2)
		first_loop(av, &fla, &lst);
	else
		printf("%s\n", ERROR_MESS);
	free(lst.conv);
	return (0);
}
