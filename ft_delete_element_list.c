/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_element_list.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 23:58:26 by pbourdon          #+#    #+#             */
/*   Updated: 2016/08/10 20:06:11 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_dlist *supp(t_dlist *liste, size_t pos)
{
	size_t		i;
	t_node		*supp_element;
	t_node		*courant;

	i = 1;
	if (pos == 1)
	{
		supp_element = liste->p_tail;
		liste->p_tail = liste->p_tail->p_next;
		if (liste->p_tail == NULL)
			liste->p_tail = NULL;
		else
			liste->p_head->p_prev = NULL;
	}
	else
	{
		courant = liste->p_head;
		while (i < pos)
		{
			courant = courant->p_next;
			i++;
		}
		supp_element = courant;
		courant->p_prev->p_next = courant->p_next;
		courant->p_next->p_prev = courant->p_prev;
	}
	free(supp_element->data);
	free(supp_element);
	return (liste);
}
