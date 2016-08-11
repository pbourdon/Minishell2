/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_cd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 14:24:12 by pbourdon          #+#    #+#             */
/*   Updated: 2016/08/11 15:56:43 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_run_cd(char *arg, t_dlist *line)
{
	char	*tmp;
	char	*tmp2;

	tmp2 = ft_delete_space(arg);
	tmp = ft_get_path(arg);
	if (ft_strcmp("-", tmp) == 0)
	{
		free(tmp);
		tmp = ft_strdup(prev(line));
	}
	else if (tmp[0] == '~' && tmp[1] == '/')
	{
		free(tmp);
		tmp = ft_strjoin(ft_strdup(home(line)), tmp + 1);
	}
	else if (ft_strcmp("~", tmp) == 0 || ft_strcmp2("cd", tmp2) == 0)
	{
		free(tmp);
		tmp = ft_strdup(home(line));
	}
	if (chdir(tmp) == 0)
	{
		free(tmp);
		line = ft_exchange_element(line);
	}
	else
	{
		free(tmp);
		ft_error(tmp, 2);
	}
	free(tmp2);
}
