/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ins_avant.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 01:03:44 by pbourdon          #+#    #+#             */
/*   Updated: 2016/07/10 01:57:47 by pbourdon         ###   ########.fr       */
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
