/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prev.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 19:47:38 by pbourdon          #+#    #+#             */
/*   Updated: 2016/08/17 17:22:11 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*prev(t_dlist *list)
{
	char	*tmp3;
	char	*tmp4;

	if (ft_search_list(list, "OLDPWD=") != 0 && ft_strlen(get_ele(list,
		ft_search_list(list, "OLDPWD="))) > 7)
		return (get_ele(list, ft_search_list(list, "OLDPWD=")) + 7);
	else
	{
		if (ft_search_list(list, "OLDPWD=") != 0)
			ft_del_ele_list(list, ft_search_list(list, "OLDPWD="),
				list->p_head, 1);
		tmp4 = getcwd(0, 0);
		tmp3 = ft_strjoin("OLDPWD=", tmp4);
		free(tmp4);
		ins_avant(list, tmp3, list->p_head, 0);
		free(tmp3);
		return (NULL);
	}
}
