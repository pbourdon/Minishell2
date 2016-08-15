/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_unsetenv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 02:13:50 by pbourdon          #+#    #+#             */
/*   Updated: 2016/08/15 17:02:18 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_dlist			*ft_run_unsetenv(char *arg, t_dlist *list)
{
	int		index;
	int		pos;
	char	*tmp;

	index = 0;
	while (arg[index] == '\t' || arg[index] == ' ' || arg[index] == '\n' ||
			arg[index] == '\r')
		index++;
	tmp = ft_strcup(arg + index);
	pos = ft_search_list(list, tmp);
	if (pos == 0)
	{
		free(tmp);
		return (list);
	}
	list = ft_del_ele_list(list, pos, list->p_head, 1);
	free(tmp);
	return (list);
}
