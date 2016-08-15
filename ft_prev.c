/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prev.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 19:47:38 by pbourdon          #+#    #+#             */
/*   Updated: 2016/08/15 17:00:53 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*prev(t_dlist *list)
{
	char	*tmp3;

	if (ft_search_list(list, "OLDPWD") != 0)
		return (get_ele(list, ft_search_list(list, "OLDPWD=")) + 7);
	else
	{
		tmp3 = ft_strjoin("OLDPWD", home(list));
		ins_avant(list, tmp3, list->p_head, 0);
		free(tmp3);
		return (home(list));
	}
}
