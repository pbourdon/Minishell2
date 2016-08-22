/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_unsetenv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 02:13:50 by pbourdon          #+#    #+#             */
/*   Updated: 2016/08/22 16:36:20 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_dlist			*ft_run_unsetenv(char *arg, t_dlist *list)
{
	int		index;
	int		pos;

	index = 0;
	while (arg[index] == '\t' || arg[index] == ' ' || arg[index] == '\n' ||
			arg[index] == '\r')
		index++;
	pos = ft_search_list(list, arg + index);
	if (pos == 0)
	{
		ft_putstr("Nothing to be done, this variable doesn't exist\n");
		return (list);
	}
	list = ft_del_ele_list(list, pos, list->p_head, 1);
	return (list);
}
