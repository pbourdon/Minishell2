/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exchange_element.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 19:37:39 by pbourdon          #+#    #+#             */
/*   Updated: 2016/08/15 17:00:44 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_dlist		*ft_exchange_element(t_dlist *line)
{
	int		pos;
	char	*oldpwd;
	char	*new_pwd;
	char	*test1;
	char	*test2;

	pos = ft_search_list(line, "PWD");
	oldpwd = ft_strdup(get_ele(line, pos));
	line = ft_del_ele_list(line, pos, line->p_head, 1);
	new_pwd = getcwd(0, 0);
	test1 = ft_strjoin("PWD=", new_pwd);
	line = ins_avant(line, test1, line->p_head, pos);
	free(test1);
	pos = ft_search_list(line, "OLDPWD");
	line = ft_del_ele_list(line, pos, line->p_head, 1);
	test2 = ft_strjoin("OLDPWD=", oldpwd + 4);
	line = ins_avant(line, test2, line->p_head, pos);
	free(test2);
	free(oldpwd);
	free(new_pwd);
	return (line);
}
