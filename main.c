#include "minishell.h"

int		main(void)
{
	char	*line1;
	char	*line2;
//	char	**args;
	t_dlist		*list;

	list = NULL;
	list = dlist_new();
	list = ft_cpy_env(list);
	ft_display_list(list);
	ft_putstr("$>");
	while (get_next_line(1, &line1) == 1)
	{
		line2 = ft_delete_tab(line1);
		list = ft_choose(line2, list);
		free(line2);
		ft_putstr("here");
		if (ft_list_size(list->p_head) == 0)
			return (0);
//		ft_show_prompt();
//		ft_delete_list(list);
	//	free(line1);
	//	free(line2);
	}
	return (0);
}
