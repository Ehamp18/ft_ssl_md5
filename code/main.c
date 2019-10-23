/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 21:59:19 by elhampto          #+#    #+#             */
/*   Updated: 2019/10/23 16:33:48 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_md5.h"

#define I lst->i

void		ma_loop(t_slfl *fla, t_woer *lst)
{
	fla->type = -1;
	while (++fla->type < 2)
		if (ft_strcmp((char*)lst->conv, g_check[fla->type].name) == 0)
		{
			if (lst->word == NULL || !lst->word)
			{
				ft_printf("%s\n", NO_FIle_ST);
				return ;
			};
			g_check[fla->type].funct(lst, fla);
			break ;
		}
}

static void	helper(t_woer *lst, char *str, t_slfl *fla)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strnew(BUFF_SIZE);
	lst->word = ft_strdup(str);
	lst->str = (char*)ft_memalloc(1);
	ft_bzero(lst->str, 2);
	tmp2 = ft_strnew(1);
	while (read(fla->fd, tmp, BUFF_SIZE) > 0)
	{
		tmp2 = free_copy(lst->str, tmp2);
		ft_bzero(lst->str, ft_strlen(lst->str));
		lst->str = ft_strjoin(tmp2, tmp);
	}
	ma_loop(fla, lst);
	free(lst->word);
	free(lst->str);
	free(tmp);
	free(tmp2);
}

void		first_loop(char **av, t_slfl *fla, t_woer *lst)
{
	I = 1;
	while (av[I])
	{
		if (!fla->s && av[I][0] != '-' &&
			ft_strcmp((char*)lst->conv, av[I]) != 0)
		{
			fla->fd = open(av[I], O_RDONLY);
			if (fla->fd > 0)
				helper(lst, av[I], fla);
			else
				ft_printf("value inputed is a string. Add flag \"-s\"\n");
			close(fla->fd);
		}
		else if (fla->s && ft_strcmp((char*)lst->conv, av[I]) != 0)
		{
			lst->str = ft_strdup(av[I]);
			lst->word = ft_strdup(av[I]);
			ma_loop(fla, lst);
			free(lst->word);
			free(lst->str);
		}
		else if (av[I][0] == '-')
			mdflags(av[I], &fla);
		I++;
	}
}

int			main(int ac, char **av)
{
	t_slfl	*fla;
	t_woer	lst;

	fla = (t_slfl*)ft_memalloc(sizeof(t_slfl));
	ft_bzero(&lst, sizeof(&lst));
	lst.conv = (unsigned char*)ft_strdup(av[1]);
	if (ac >= 2)
		first_loop(av, fla, &lst);
	else
		ft_printf("%s\n", ERROR_MESS);
	free(lst.conv);
	free(fla);
	return (0);
}
