/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 13:03:36 by pbourdon          #+#    #+#             */
/*   Updated: 2016/08/15 20:31:23 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBLS_H
# define LIBLS_H

# include "stdlib.h"
# include <unistd.h>
# include <stdlib.h>
# include <dirent.h>
# include <sys/stat.h>
# include <pwd.h>
# include <sys/types.h>
# include <uuid/uuid.h>
# include <sys/xattr.h>
# include <time.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <grp.h>

typedef struct		s_yolo
{
	int			*read;
	int			uid;
	int			a;
	int			option_a;
	int			option_rr;
	int			option_l;
	int			option_t;
	int			option_r;
}					t_arg;

typedef struct		s_node
{
	char			*data;
	struct s_node	*p_next;
	struct s_node	*p_prev;
}					t_node;

typedef struct		s_dlist
{
//	size_t			length;
	struct s_node	*p_tail;
	struct s_node	*p_head;
}					t_dlist;

t_dlist				*ft_choose(char *str, t_dlist *liste);
void				ft_run_ls(char *arg);
void				ft_find_options(t_arg *arg, char *command);
void				ft_run_cd(char *arg, t_dlist *list, char *tmp, char *tmp2);
void				dlist_delete(t_dlist **p_list);
t_dlist				*dlist_prepend(t_dlist *p_list, char *data);
t_dlist				*dlist_append(t_dlist *p_list, char *data);
t_dlist				*ft_add_data(t_dlist *p_list, char *data);
t_dlist				*nik_the_norm2(t_dlist *p_list, t_node *p_new, int i);
t_dlist				*nik_the_norm3(t_dlist *p_list, t_node *p_new, int i);
t_dlist				*dlist_new(t_dlist *p_new);
t_dlist				*ft_cpy_env(t_dlist *list);
pid_t				create_process(void);
int					ft_search_list(t_dlist *liste, char *data);
t_dlist				*ins_avant(t_dlist *liste, char *data, t_node *courant,
					int pos);
char				*get_ele(t_dlist *liste, int pos);
int					ft_run_exe(char *path, char **options, t_dlist *list);
char				*ft_get_path(char *arg);
int					ft_list_size(t_node *head);
char				**ft_tab_from_list(t_dlist(*list));
int					ft_check_file(char *path);
char				*last_dir(char *path);
void				ft_show_prompt(void);
void				ft_error(char *arg, int version);
int					ft_check_arg(char *arg, t_dlist *list);
void				ft_run_echo(char *arg, t_dlist *list);
void				ft_run_setenv(char *arg, t_dlist *list);
char				*ft_strcup(char *arg);
t_dlist				*ft_run_unsetenv(char *arg, t_dlist *list);
char				*ft_get_path(char *arg);
t_dlist				*ft_exchange_element(t_dlist *list);
char				*ft_last_dir(char *path);
char				*home(t_dlist *list);
char				*prev(t_dlist *list);
char				*ft_delete_space(char *arg);
char				ft_strcmp2(char *s1, char *s2);
char				*ft_give_path(char *arg);
char				*ft_get_auto_path(int x, t_dlist *list, int drop,
					int index);
int					ft_get_total_path(t_dlist *list);
void				ft_delete_list(t_dlist **p_list);
void				ft_free(char **options);
char				**ft_set_zero(int index, char **options);
t_dlist				*ft_del_ele_list(t_dlist *list, size_t position, t_node
					*p_temp, size_t i);
char				**ft_get_options1(char *arg, char **options);
char				*ft_boucle(char *arg);
char				**ft_get_options2(char *arg, char **options, int index,
					int x);
char				**ft_get_options3(char *home, int x, int *compteur,
					char **options);
char				*ft_get_options4(int *index, int *compteur, char *options,
					char *arg);

void				ft_display_tab(char **arg);
char				*ft_strcut(char *str, int index);
char				*ft_strupcase(char *str);
void				ft_putstr(char *str);
void				ft_putchar(char c);
void				*ft_memcpy(void *dest, const void *src, size_t n);
size_t				ft_strlen(const char *str);
void				ft_putnbr(int nbr);
char				*ft_itoa(int n);
void				ft_putchar_fd(char c, int fd);
int					ft_strcmp(const char *s1, const char *s2);
int					s(const char *s1);
int					e(const char *s1);
void				ft_putstr_fd(char *str, int fd);
void				ft_putnbr_fd(int nbr, int fd);
char				*ft_strjoin_special(char const *s1, char const *s2);
char				*t(char const *s1, char const *s2);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strdup(const char *s1);
int					get_next_line(int const fd, char **line);
void				ft_memmove(void *dest, const void *source, size_t len);
char				*ft_delete_tab(char *str);
int					ft_display_list(t_dlist *p_list);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strcpy(char *dst, const char *src);
void				ft_free_tab(char **tab);
void				*ft_memalloc(size_t size);
int					ft_get_size(char *str);

#endif
