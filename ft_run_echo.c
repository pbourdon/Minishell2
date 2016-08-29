/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_echo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 23:18:40 by pbourdon          #+#    #+#             */
/*   Updated: 2016/08/29 20:21:25 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_echo_var_env(int index, char *arg, t_dlist *list)
{
	char		*tmp;

	tmp = ft_strjoin(arg + index + 1, "=");
	if (arg[index] == '$' && ft_search_list(list, ft_strupcase(tmp)) != 0)
	{
		ft_putstr(get_ele(list, ft_search_list(list, ft_strupcase(tmp))) +
			ft_strlen(arg + index));
		ft_putchar('\n');
	}
	free(tmp);
}

void		ft_run_echo(char *arg, t_dlist *list)
{
	int			index;

	index = 4;
	while (arg[index] == '\t' || arg[index] == '\n' || arg[index] == '\r' ||
		arg[index] == ' ')
		index++;
	if (arg[index] == '$')
		ft_echo_var_env(index, arg, list);
	if (arg[index] == '-' && arg[index + 1] == 'n')
	{
		index = index + 2;
		while (arg[index] == '\t' || arg[index] == '\n' || arg[index] == '\r'
		|| arg[index] == ' ')
			index++;
		ft_putstr(arg + index);
	}
	else
	{
		ft_putstr(arg + index);
		ft_putchar('\n');
	}
}
