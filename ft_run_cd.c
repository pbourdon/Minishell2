/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_cd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 14:24:12 by pbourdon          #+#    #+#             */
/*   Updated: 2016/08/17 15:28:55 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_run_cd(char *arg, t_dlist *line, char *tmp, char *tmp2)
{
	tmp2 = ft_delete_space(arg);
	tmp = ft_get_path(arg);
	if (ft_strcmp("-", tmp) == 0)
	{
		free(tmp);
		if (prev(line) != NULL)
			tmp = ft_strdup(prev(line));
		else
			tmp = getcwd(0, 0);
		ft_putstr(tmp);
		ft_putchar('\n');
	}
	else if (tmp[0] == '~' && tmp[1] == '/')
	{
		free(tmp);
		if (home(line) != NULL)
			tmp = ft_strjoin(home(line), tmp + 1);
		else
		{
			ft_putstr(" A problem just happened, you need to add the home");
			ft_putstr(" environment variable to perform this operation \n");
			free(tmp2);
			return (1);
		}
	}
	else if (ft_strcmp("~", tmp) == 0 || ft_strcmp2("cd", tmp2) == 0)
	{
		free(tmp);
		if (home(line) != NULL)
			tmp = ft_strdup(home(line));
		else
		{
			ft_putstr("A problem just happened, you need to add the home");
			ft_putstr(" environment variable to perform this operation \n");
			free(tmp2);
			return (1);
		}
	}
	if (chdir(tmp) == 0)
		line = ft_exchange_element(line);
	else
		ft_error(tmp, 2);
	free(tmp);
	free(tmp2);
	return (0);
}
