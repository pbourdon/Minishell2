/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prev.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 19:47:38 by pbourdon          #+#    #+#             */
/*   Updated: 2016/07/20 19:50:48 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*prev(t_dlist *list)
{
	if (ft_search_list(list, "OLDPWD") != 0)
		return (get_ele(list, ft_search_list(list, "OLDPWD=")) + 7);
	else
	{
		ins_avant(list, ft_strjoin("OLDPWD=", home(list)), 0);
		return (home(list));
	}
}
