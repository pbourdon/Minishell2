/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 18:27:56 by pbourdon          #+#    #+#             */
/*   Updated: 2016/08/10 19:39:34 by pbourdon         ###   ########.fr       */
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
		free(courant->data);
		free(courant->p_next);
		courant = next;
	}
	free(*head);
//	free(courant);
	*head = NULL;
}
