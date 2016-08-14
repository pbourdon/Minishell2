/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_auto_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 16:26:38 by pbourdon          #+#    #+#             */
/*   Updated: 2016/08/14 19:41:58 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_reset(char *str)
{
	int		index;

	index = 0;
	while (str[index] != '\0')
	{
		str[index] = '\0';
		index++;
	}
	return (str);
}
char	*ft_get_auto_path(int x, t_dlist *list)
{
	char	*temp;
	char	*retur;
	int		index;
	int		compteur;
	int		drop;

	drop = 0;
	index = 0;
	compteur = 0;
	retur = malloc(sizeof(char) * ft_strlen(get_ele(list, ft_search_list(list, "PATH"))) + 5);
	temp = get_ele(list, ft_search_list(list, "PATH=")) + 5;
	while (temp[index] != '\0')
	{
		while (temp[index] != '\0' && temp[index] != ':')
		{
			retur[compteur] = temp[index];
			index++;
			compteur++;
		}
		drop++;
		retur[compteur] = '/';
		retur[compteur + 1] = '\0';
		if (drop == x)
		{
			return (retur);
		}
		compteur = 0;
		retur = ft_reset(retur);
		index++;
	}
	return ("awdawD");
}
