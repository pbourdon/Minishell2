#include "libft.h"

char		*ft_delete_tab(char *str)
{
	char	*tmp;
	int		index;
	int		index2;

	index = 0;
	index2 = 0;
	tmp = malloc(sizeof(char) * ft_strlen(str) + 1);
	while (str[index] != '\0' && (str[index] == ' ' || str[index] == '\t'))
		index++;
	while (str[index] != '\0')
	{
		if (str[index] == '\t')
			tmp[index2++] = ' ';
		else
			tmp[index2++] = str[index];
		index++;
	}
	tmp[index2] = '\0';
	return (tmp);
}
