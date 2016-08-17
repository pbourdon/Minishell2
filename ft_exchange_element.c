/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exchange_element.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 19:37:39 by pbourdon          #+#    #+#             */
/*   Updated: 2016/08/17 15:03:18 by pbourdon         ###   ########.fr       */
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
	char	*test4;

	pos = ft_search_list(line, "PWD=");
	if (pos != 0 && ft_strlen(get_ele(line, pos)) > 4)
		oldpwd = ft_strdup(get_ele(line, pos));
	else
	{
		test4 = getcwd(0, 0);
		oldpwd = ft_strjoin("PWD=", test4);
		free(test4);
	}
	line = ft_del_ele_list(line, pos, line->p_head, 1);
	new_pwd = getcwd(0, 0);
	test1 = ft_strjoin("PWD=", new_pwd);
	if (pos == 0)
		line = ft_add_data(line, test1);
	else
		line = ins_avant(line, test1, line->p_head, pos);
	free(test1);
	pos = ft_search_list(line, "OLDPWD=");
	line = ft_del_ele_list(line, pos, line->p_head, 1);
	test2 = ft_strjoin("OLDPWD=", oldpwd + 4);
	if (pos == 0)
		line = ft_add_data(line, test2);
	else
		line = ins_avant(line, test2, line->p_head, pos);
	free(test2);
	free(oldpwd);
	free(new_pwd);
	return (line);
}
