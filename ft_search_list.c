/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 23:04:57 by pbourdon          #+#    #+#             */
/*   Updated: 2016/07/19 00:59:00 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_search_list(t_dlist *liste, char *data)
{
	int			i;
	t_node		*courant;

	i = 0;
	courant = liste->p_head;
	if (liste == NULL)
		return (-1);
	while (courant != NULL)
	{
		i++;
/*
			ft_putchar(courant->data[ft_strlen(data) - 1]);
			ft_putstr(" of ");
			ft_putstr(courant->data);
			ft_putstr(" VS ");
			ft_putchar(data[ft_strlen(data)]);
			ft_putstr(" of ");
			ft_putstr(data);
			ft_putchar('\n');
			*/
		if (ft_strncmp(data, courant->data, ft_strlen(data)) == 0)
		{
			return (i);
		}
		courant = courant->p_next;
	}
	return (0);
}
