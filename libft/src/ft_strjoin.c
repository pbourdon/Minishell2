/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 21:35:05 by pbourdon          #+#    #+#             */
/*   Updated: 2016/07/20 01:25:48 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	char	*temp_ret;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (ret == NULL)
		return (NULL);
	temp_ret = ret;
	while (*s1 != '\0')
		*temp_ret++ = *s1++;
	while (*s2 != '\0')
		*temp_ret++ = *s2++;
	*temp_ret = '\0';
	return (ret);
}

char	*ft_strjoin_special(char const *s1, char const *s2)
{
	char	*str;
	int		a;
	int		b;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (s1[ft_strlen(s1) - 1] != '/')
		s1 = ft_strjoin(s1, "/");
	a = 0;
	b = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	return (str);
}

char	*t(char const *s1, char const *s2)
{
	char	*str;
	int		a;
	int		b;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (s1[ft_strlen(s1) - 1] != '/')
		s1 = ft_strjoin(s1, "/");
	a = 0;
	b = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	return (str);
}
