/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpy_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 19:33:48 by pbourdon          #+#    #+#             */
/*   Updated: 2016/08/15 17:05:53 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_dlist			*ft_cpy_env(t_dlist *list)
{
	int				i;
	extern char		**environ;

	i = 0;
	while (environ[i])
	{
		list = ft_add_data(list, environ[i]);
		i++;
	}
	return (list);
}
