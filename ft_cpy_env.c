/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpy_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 19:33:48 by pbourdon          #+#    #+#             */
/*   Updated: 2016/07/27 18:50:26 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern char		**environ;

t_dlist		*ft_cpy_env(t_dlist *list)
{
	int		i;

	i = 0;
	while (environ[i])
	{
		list = ft_add_data(list, environ[i]);
		i++;
	}
	return (list);
}
