/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_options.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 19:34:32 by pbourdon          #+#    #+#             */
/*   Updated: 2016/08/15 20:36:45 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		**ft_get_options1(char *arg, char **options)
{
	char	*boucle;
	int		index;
	int		temp;

	index = 0;
	temp = 0;
	boucle = ft_boucle(arg);
	options = malloc(sizeof(char *) * ft_get_size(arg));
	options = ft_set_zero(ft_get_size(arg), options);
	options[0] = ft_memalloc(ft_strlen(boucle) + 1);
	while (boucle[index] != '\0')
	{
		options[0][temp] = boucle[index];
		index++;
		temp++;
	}
	options[0][temp] = '\0';
	free(boucle);
	return (options);
}

char		**ft_get_options2(char *arg, char **options, int index, int x)
{
	int		compteur;

	compteur = 0;
	options[x] = ft_memalloc(ft_strlen(arg) + 1);
	while (arg[index] != '\0' && arg[index] != ' ' && arg[index] != '\t' &&
			arg[index] != '\n')
	{
		options[x][compteur] = arg[index];
		compteur++;
		index++;
	}
	options[x][compteur] = '\0';
	x++;
	return (options);
}

char		**ft_get_options3(char *home, int x, int *compteur, char **options)
{
	int		index4;

	index4 = 0;
	while (home[index4] != '\0')
	{
		options[x][*compteur] = home[index4];
		index4++;
		*compteur = *compteur + 1;
	}
	return (options);
}

char		*ft_get_options4(int *index, int *compteur, char *options, char *arg)
{
	while (arg[*index] != '\0' && arg[*index] != ' ')
	{
		options[*compteur] = arg[*index];
		*index = *index + 1;
		*compteur = *compteur + 1;
	}
	return (options);
}
