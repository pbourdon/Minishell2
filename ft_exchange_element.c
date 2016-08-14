/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exchange_element.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 19:37:39 by pbourdon          #+#    #+#             */
/*   Updated: 2016/08/14 16:23:49 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_dlist		*ft_exchange_element(t_dlist *line)
{
	int		pos;
	char	*oldpwd;
	char	*new_pwd;
	char	*test1;

	pos = ft_search_list(line, "PWD");
	oldpwd = ft_strdup(get_ele(line, pos));
	line = ft_del_ele_list(line, pos);
//	line = supp(line, pos);
	new_pwd = getcwd(0, 0);
	test1 = ft_strjoin("PWD", new_pwd);
	line = ins_avant(line, test1, pos);
	free(test1);
//	ft_putstr("\nNEW LIST WITH NEW PWD\n");
//	ft_display_list(line);
//	ft_putchar('\n');
	pos = ft_search_list(line, "OLDPWD");
	line = ft_del_ele_list(line, pos);
//	line = supp(line, pos);
	line = ins_avant(line, ft_strjoin("OLDPWD=", oldpwd + 4), pos);
//	free(oldpwd);
	return (line);
}
