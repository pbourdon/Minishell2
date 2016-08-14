#include "minishell.h"

int		main(void)
{
	char	*line1;
	char	*line2;
//	char	**args;
	t_dlist		*list;

	list = NULL;
	list = dlist_new(list);
	list = ft_cpy_env(list);
	ft_display_list(list);
//	ft_putstr("\n\n the exchange is right now\n\n");
//	list = ft_exchange_element(list);
//	ft_putstr("\n\nSTART TO TEST THE DELETE FUNCTION TO CHECK IT \n\n");
//	list = ft_del_ele_list(list, 7);
//	ft_display_list(list);
//	ft_delete_list(&list->p_head, &list->p_tail);
//	free(list);
//	return (0);
	ft_putstr("$>");
	while (get_next_line(1, &line1) == 1)
	{
		line2 = ft_delete_tab(line1);
		list = ft_choose(line2, list);
		free(line2);
		free(line1);
		if (list == NULL)
		{
			return (0);
		}
		ft_show_prompt();
	}
	return (0);
}
