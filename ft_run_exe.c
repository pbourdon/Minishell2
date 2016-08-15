/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 15:43:35 by pbourdon          #+#    #+#             */
/*   Updated: 2016/08/15 17:12:43 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

pid_t		create_process(void)
{
	pid_t	pid;

	pid = -1;
	while (-1 == (pid = fork()) && errno == EAGAIN)
	{
		pid = fork();
	}
	return (pid);
}

void		son_process(char *path, char *arg[], t_dlist *line)
{
	int		test;

	if (ft_check_file(path))
	{
		test = execve(path, arg, ft_tab_from_list(line));
		if (test == -1)
		{
			perror("execv.");
			exit(EXIT_FAILURE);
		}
	}
}

int			ft_run_exe(char *path, char **options, t_dlist *list)
{
	pid_t	pid;

	if (path == NULL)
		return (0);
	pid = fork();
	if (pid > 0)
		waitpid(pid, 0, 0);
	if (pid == 0)
	{
		execve(path, options, ft_tab_from_list(list));
		ft_putstr("error execve");
		exit(0);
	}
	return (EXIT_SUCCESS);
}
