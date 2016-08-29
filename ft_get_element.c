/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_element.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 18:39:12 by pbourdon          #+#    #+#             */
/*   Updated: 2016/08/17 14:52:21 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_ele(t_dlist *liste, int pos)
{
	int			i;
	t_node		*courant;

	i = 1;
	courant = liste->p_head;
	while (i++ < pos)
		courant = courant->p_next;
	return (courant->data);
}
