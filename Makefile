# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/04 13:03:16 by pbourdon          #+#    #+#              #
#    Updated: 2016/08/17 17:24:21 by pbourdon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBPATH = ./libft/
LIB = $(LIBPATH)/minishell.a

NAME = minishell

CC = @gcc

CFLAGS = -Wall -Wextra -Werror

LDFLAGS = -L $(LIBPATH) -lft

SRC =	main.c\
		dlist_new.c\
		ft_cpy_env.c\
		ft_add_data.c\
		fuck_the_norm.c\
		ft_display_list.c\
		ft_delete_list.c\
		ft_list_size.c\
		ft_choose.c\
		ft_run_cd.c\
		ft_show_prompt.c\
		ft_get_path.c\
		ft_exchange_element.c\
		ft_last_dir.c\
		ft_home.c\
		ft_prev.c\
		ft_delete_space.c\
		ft_strcmp2.c\
		ft_give_path.c\
		ft_error.c\
		ft_search_list.c\
		ft_strcut.c\
		ft_get_element.c\
		ft_ins_avant.c\
		ft_del_ele_list.c\
		ft_run_echo.c\
		ft_strupcase.c\
		ft_run_setenv.c\
		ft_check_arg.c\
		ft_run_unsetenv.c\
		ft_get_auto_path.c\
		ft_get_total_path.c\
		ft_set_zero.c\
		ft_run_exe.c\
		ft_tab_from_list.c\
		ft_check_file.c\
		ft_display_tab.c\
		ft_free_tab.c\
		ft_get_size.c\
		ft_get_options.c\
		ft_error_home.c\
	##		ft_find_option.c\
		ft_free.c\

OBJ = $(SRC:.c=.o)

all: $(LIB) $(NAME)

$(NAME):	$(OBJ)
	@$(CC) $(LDFLAGS) -o $@ $^

$(LIB):
	@make -C $(LIBPATH)

clean:
	@rm -f $(OBJ)
	@make clean -C $(LIBPATH)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBPATH)

re: fclean all

.PHONY: all re clean flcean
