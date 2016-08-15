/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_setenv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 01:16:38 by pbourdon          #+#    #+#             */
/*   Updated: 2016/08/15 17:13:38 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			*ft_strcup(char *arg)
{
	int		index2;
	int		index;
	char	*str;

	index2 = 0;
	index = 0;
	str = malloc(sizeof(char) * ft_strlen(arg));
	while (arg[index2] != '\0' && arg[index2] != ' ' && arg[index2] != '\t'
		&& arg[index2] != '\n' && arg[index2] != '=')
	{
		str[index] = arg[index2];
		index2++;
		index++;
	}
	str[index] = '\0';
	return (str);
}

t_dlist			*modify_element(t_dlist *list, char *arg, int index)
{
	int		pos;
	char	*new;
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	tmp = ft_strcup(arg + index);
	tmp2 = ft_strjoin(tmp, "=");
	pos = ft_search_list(list, tmp);
	if (pos == 0)
		return (list);
	new = ft_strdup(arg + index + ft_strlen(tmp));
	list = ft_del_ele_list(list, pos, list->p_head, 1);
	tmp3 = ft_strjoin(tmp2, new + 1);
	free(new);
	ft_display_list(list);
	list = ins_avant(list, tmp3, list->p_head, pos);
	free(tmp);
	free(tmp2);
	free(tmp3);
	return (list);
}

void			ft_run_setenv(char *arg, t_dlist *list)
{
	int			index;

	index = 8;
	ft_putstr("WELCOME IN RUN SETENV");
	while (arg[index] == '\t' || arg[index] == ' ' || arg[index] == '\n' ||
		arg[index] == '\r')
		index++;
	list = modify_element(list, arg, index);
}
