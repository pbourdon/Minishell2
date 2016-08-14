/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 15:43:35 by pbourdon          #+#    #+#             */
/*   Updated: 2016/08/14 19:10:36 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

pid_t create_process(void)
{
	pid_t pid;

	do {
		pid = fork();
	} while ((pid == -1) && (errno == EAGAIN));

	return pid;
}

void son_process(char *path, char *arg[], t_dlist *line)
{
	if (ft_check_file(path))
	{
		if (execve(path, arg, ft_tab_from_list(line)) == -1) 
		{
			perror("execv.");
			exit(EXIT_FAILURE);
		}
	}
}

int		ft_run_exe(char *path, char **options, t_dlist *list)
{
	pid_t pid;
//	char *options2[] = { "ls", "-lar", NULL };
//	char *tab2[] = { NULL };
	if (path == NULL)
		return (0);

	pid = fork();
	if (pid > 0)
		waitpid(pid, 0, 0);
	if (pid == 0)
	{
		ft_display_tab(ft_tab_from_list(list));
		execve(path, options, ft_tab_from_list(list));
		// execve("/bin/ls", options2, tab2);
		ft_putstr("error execve");
		exit(0);
	}
	return EXIT_SUCCESS;
}
