/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_options.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 19:34:32 by pbourdon          #+#    #+#             */
/*   Updated: 2016/08/16 18:15:30 by pbourdon         ###   ########.fr       */
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

char		**ft_get_options2(char *arg, char **options, size_t *index, int *x)
{
	int		compteur;

	compteur = 0;
	options[*x] = ft_memalloc(ft_strlen(arg) + 1);
	while (arg[*index] != '\0' && arg[*index] != ' ' && arg[*index] != '\t' &&
			arg[*index] != '\n')
	{
		options[*x][compteur] = arg[*index];
		compteur++;
		*index = *index + 1;
	}
	options[*x][compteur] = '\0';
	*x = *x + 1;
	return (options);
}

char		*ft_get_options3(char *home, int index, int compteur, char *options)
{
	while (home[index] != '\0')
	{
		options[compteur] = home[index];
		index = index + 1;
		compteur = compteur + 1;
	}
	options[compteur] = '\0';
	return (options);
}

char		*ft_get_options4(size_t *index, int compteur, char *options,
		char *arg)
{
	compteur = 0;
	while (arg[*index] != '\0' && arg[*index] != ' ')
	{
		options[compteur] = arg[*index];
		*index = *index + 1;
		compteur = compteur + 1;
	}
	options[compteur] = '\0';
	return (options);
}
