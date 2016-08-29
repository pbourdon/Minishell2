/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 19:43:20 by pbourdon          #+#    #+#             */
/*   Updated: 2016/07/20 19:44:16 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			*last_dir(char *path)
{
	int		i;

	i = ft_strlen(path);
	while (i > 0 && path[i] != '/')
		i--;
	return (path + i);
}
