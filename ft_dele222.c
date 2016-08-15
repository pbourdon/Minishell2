/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_ele_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/13 01:06:27 by pbourdon          #+#    #+#             */
/*   Updated: 2016/08/15 13:29:27 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_dlist		*ft_fuck_norm(t_dlist *list, t_node *p_temp)
{
	list->p_tail = p_temp->p_prev;
	list->p_tail->p_next = NULL;
	return (list);
}

t_dlist		*ft_fuck_norm2(t_dlist *list, t_node *p_temp)
{
	list->p_head = p_temp->p_next;
	list->p_head->p_prev = NULL;
	return (list);
}

t_node		*ft_fuck_norm3(t_dlist *list, t_node *p_temp)
{
	p_temp->p_next->p_prev = p_temp->p_prev;
	p_temp->p_prev->p_next = p_temp->p_next;
	return (p_temp);
}
t_dlist		*ft_del_ele_list(t_dlist *list, size_t position)
{
	t_node		*p_temp;
	size_t		i;

	i = 1;
	p_temp = list->p_head;
	if (list != NULL)
	{
		while (p_temp != NULL && i <= position)
		{
			if (position == i)
			{
				if (p_temp->p_next == NULL)
				{
			//		list = ft_fuck_norm(list, p_temp);
				list->p_tail = p_temp->p_prev;
				list->p_tail->p_next = NULL;
				}
				else if (p_temp->p_prev == NULL)
				{
				//	list = ft_fuck_norm2(list, p_temp);
					list->p_head = p_temp->p_next;
					list->p_head->p_prev = NULL;
				}
				else
				{
				//	p_temp = ft_fuck_norm3(list, p_temp);
					p_temp->p_next->p_prev = p_temp->p_prev;
					p_temp->p_prev->p_next = p_temp->p_next;
				}
				free(p_temp);
			}
			else
			{
				p_temp = p_temp->p_next;
			}
			i++;
		}
	}
	return (list);
}
