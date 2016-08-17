/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 17:14:27 by pbourdon          #+#    #+#             */
/*   Updated: 2016/08/17 16:47:45 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(void)
{
	char		*line1;
	char		*line2;
	t_dlist		*list;

	list = NULL;
	list = dlist_new(list);
	list = ft_cpy_env(list);
	if (ft_list_size(list->p_head) == 0)
		list = ft_cpy_env2(list);
	ft_putstr("$>");
	while (get_next_line(1, &line1, 0) == 1)
	{
		line2 = ft_delete_tab(line1);
		list = ft_choose(line2, list);
		free(line2);
		free(line1);
		if (list == NULL)
		{
			return (0);
		}
		ft_show_prompt();
	}
	return (0);
}
