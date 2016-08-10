/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ins_avant.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 01:03:44 by pbourdon          #+#    #+#             */
/*   Updated: 2016/08/10 20:03:39 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_dlist		*ins_avant(t_dlist *liste, char *data, int pos)
{
	int			i;
	t_node		*n;
	t_node		*courant;

	i = 1;
	n = malloc(sizeof(*n));
	if (n == NULL)
		return (liste);
	n->data = malloc(sizeof(char) * ft_strlen(data) + 1);
	n->data = ft_strdup(data);
	courant = liste->p_head;
	while (i++ < pos)
		courant = courant->p_next;
	n->p_next = courant;
	n->p_prev = courant->p_prev;
	if (courant->p_prev == NULL)
		liste->p_head = n;
	else
		courant->p_prev->p_next = n;
	courant->p_prev = n;
	return (liste);
}
