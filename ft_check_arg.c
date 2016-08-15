/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 20:47:18 by pbourdon          #+#    #+#             */
/*   Updated: 2016/08/15 17:29:31 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*ft_boucle(char *arg)
{
	int		index;
	int		index2;
	char	*process;

	process = malloc(sizeof(char) * ft_strlen(arg));
	index2 = 0;
	index = 0;
	while (arg[index] == ' ' || arg[index] == '\t' || arg[index] == '\n'
		|| arg[index] == '\r')
		index++;
	while (arg[index] != '\0' && arg[index] != '\t' && arg[index] != '\n'
		&& arg[index] != ' ')
	{
		process[index2] = arg[index];
		index2++;
		index++;
	}
	process[index2] = '\0';
	index2 = 0;
	while (arg[index] == '\t' || arg[index] == ' ' || arg[index] == '\n'
		|| arg[index] == '\n')
		index++;
	return (process);
}

char		**ft_get_options(char *arg, t_dlist *list)
{
	char	**option;
	int		compteur;
	int		index;
	int		x;
	int		index4;
	int		temp;
	char	*boucle;

	index4 = 0;
	temp = 0;
	x = 1;
	index = 0;
	compteur = 0;
	boucle = ft_boucle(arg);
	option = malloc(sizeof(char *) * ft_get_size(arg));
	option = ft_set_zero(ft_get_size(arg), option);
	option[0] = ft_memalloc(ft_strlen(boucle) + 1);
	while (boucle[index] != '\0')
	{
		option[0][temp] = boucle[index];
		index++;
		temp++;
	}
	option[0][temp] = '\0';
	free(boucle);
	index = ft_strlen(option[0]);
	while (arg[index] != '\0' && (arg[index] == ' ' || arg[index] == '\t'
		|| arg[index] == '\n'))
		index++;
	while (arg[index] != '\0')
	{
		if (arg[index] == '-')
		{
			option[x] = ft_memalloc(ft_strlen(arg) + 1);
			while (arg[index] != '\0' && arg[index] != ' ' &&
				arg[index] != '\t' && arg[index] != '\n')
			{
				option[x][compteur] = arg[index];
				compteur++;
				index++;
			}
			option[x][compteur] = '\0';
			compteur = 0;
			x++;
		}
		if (index < ft_strlen(arg) && arg[index] != '\0' && arg[index] != ' ')
		{
			option[x] = ft_memalloc(ft_strlen(arg) + ft_strlen(home(list) + 1));
			while (arg[index] != '\0' && arg[index] != ' ')
			{
				if (arg[index] == '~')
				{
					while (home(list)[index4] != '\0')
					{
						option[x][compteur] = home(list)[index4];
						index4++;
						compteur++;
					}
					index++;
				}
				option[x][compteur] = arg[index];
				compteur++;
				index++;
			}
			option[x][compteur] = '\0';
			compteur = 0;
			x++;
		}
		index++;
	}
	option[x] = NULL;
	return (option);
}

char		*ft_generate_path(char *arg, t_dlist *list)
{
	int		compteur;
	char	*strjoin;
	char	*auto_path;

	compteur = ft_get_total_path(list) + 1;
	while (compteur > 0)
	{
		auto_path = ft_get_auto_path(compteur, list);
		strjoin = ft_strjoin(auto_path, arg);
		free(auto_path);
		if (access(strjoin, X_OK) == 0)
			return (strjoin);
		compteur--;
		free(strjoin);
	}
	ft_putstr("zsh: command not found (or minishell did not find the correct");
	ft_putstr(" PATH. Check your PATH env variable)\n");
	return (NULL);
}

int			ft_check_arg(char *arg, t_dlist *list)
{
	int		index;
	char	*boucle;
	char	*generated;
	char	*tmp;
	char	**options;

	boucle = ft_boucle(arg);
	options = ft_get_options(arg, list);
	index = 0;
	if (arg[index] == '/')
	{
		tmp = ft_give_path(arg);
		ft_run_exe(tmp, options, list);
		ft_free_tab(options);
		free(boucle);
		free(tmp);
		return (1);
	}
	else if (arg[index] != '\0')
	{
		generated = ft_generate_path(boucle, list);
		ft_run_exe(generated, options, list);
		ft_free_tab(options);
		free(generated);
		free(boucle);
		return (1);
	}
	else
	{
		ft_free_tab(options);
		free(boucle);
		return (0);
	}
	return (1);
}
