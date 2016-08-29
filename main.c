/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 17:14:27 by pbourdon          #+#    #+#             */
/*   Updated: 2016/08/29 18:33:53 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_first_sigint(void)
{
	write(1, "\n$#>", 4);
}

void	get_sigint(int signal)
{
	write(1, "\r\n##", 2);
	signal = 3;
}

int		main(void)
{
	char		*line1;
	char		*line2;
	t_dlist		*list;

	ft_putstr("\n WELCOME ON MINISHELL2 BY PBOURDON \n");
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
			return (0);
		ft_show_prompt();
	}
	return (0);
}
