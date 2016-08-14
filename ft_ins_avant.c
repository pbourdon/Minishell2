/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ins_avant.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 01:03:44 by pbourdon          #+#    #+#             */
/*   Updated: 2016/08/14 16:52:55 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_dlist		*ins_avant(t_dlist *liste, char *data, int pos)
{
	int			i;
	t_node		*n;
	t_node		*courant;

	courant = liste->p_head;
	i = 1;
	while (courant != NULL && i <= pos)
	{
		if (pos == i)
		{
			if (courant->p_next == NULL)
				liste = dlist_append(liste, data);
			else if (courant->p_prev == NULL)
				liste = dlist_prepend(liste, data);
			else
			{
				n = malloc(sizeof(*n));
				if (n != NULL)
				{
					n->data = data;
					courant->p_next->p_prev = n;
					courant->p_prev->p_next = n;
					n->p_prev = courant->p_prev;
					n->p_next = courant;
				}
			}
		}
		else
			courant = courant->p_next;
		i++;
	}
	return (liste);
}
