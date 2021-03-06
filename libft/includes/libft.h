/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 08:38:32 by pbourdon          #+#    #+#             */
/*   Updated: 2016/08/16 01:01:27 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 9

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

char			*ft_itoa(int n);
void			ft_putnbr(int nbr);
char			*ft_strjoin(char const *str1, char const *str2);
char			*ft_strjoin_special(char const *str1, char const *str2);
size_t			ft_strlen(const char *str);
size_t			l(const char *str);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strcat(char *s1, const char *s2);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			ft_putstr(char const *s);
void			ft_putchar(char c);
int				ft_strcmp(const char *s1, const char *s2);
int				s(const char *s1);
int				e(const char *s1);
void			ft_putnbr_fd (int n, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putchar_fd(char c, int fd);
char			*ft_strdup(const char *s1);
int				get_next_line(int const fd, char **line, int check);
void			*ft_memmove(void *dest, const void *source, size_t len);
char			*ft_strchr(const char *haystack, int needle);
char			*ft_delete_tab(char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			ft_bzero(void *s1, size_t n);
void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memalloc(size_t size);
char			*ft_strnew(size_t size);
char			*ft_strcpy(char *dst, const char *src);

#endif
