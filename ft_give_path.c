/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_give_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/21 00:26:59 by pbourdon          #+#    #+#             */
/*   Updated: 2016/08/14 19:05:09 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_give_path(char *arg)
{
	int		index;

	index = 0;
	while (arg[index] != '\0' && arg[index] != ' ' && arg[index] != '\t'
			&& arg[index] != '\n' && arg[index] != '\r')
		index++;
	return (ft_strcut(arg, index));
}
