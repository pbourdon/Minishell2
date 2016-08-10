/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 15:35:22 by pbourdon          #+#    #+#             */
/*   Updated: 2016/08/10 18:46:36 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_dlist	*dlist_new(void)
{
	t_dlist *p_new;

	p_new = malloc(sizeof(*p_new));
	if (p_new != NULL)
	{
	//	p_new->length = 0;
		p_new->p_head = NULL;
		p_new->p_tail = NULL;
	}
	return (p_new);
}
