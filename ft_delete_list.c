/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 18:27:56 by pbourdon          #+#    #+#             */
/*   Updated: 2016/08/11 16:29:02 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_delete_list(t_node **head, t_node **tail)
{
	t_node		*next;
	t_node		*courant;

	courant = *head;
	while (courant != NULL)
	{
		next = courant->p_next;
//		free(courant->data);
//		ATTENTION SI TU FREE COURANT DATA SA DECONNE SEC
		free(courant->p_next);
		courant = next;
	}
	free(*head);
	*head = NULL;
}
