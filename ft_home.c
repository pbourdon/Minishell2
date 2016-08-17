/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_home.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 19:45:05 by pbourdon          #+#    #+#             */
/*   Updated: 2016/08/17 14:33:23 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*home(t_dlist *list)
{
	if (ft_search_list(list, "HOME=") != 0 && ft_strlen(get_ele(list,
		ft_search_list(list, "HOME="))) > 5)
		return (get_ele(list, ft_search_list(list, "HOME=")) + 5);
	else
		return (NULL);
}
