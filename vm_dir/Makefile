# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mblet <mblet@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/07 09:22:24 by mblet             #+#    #+#              #
#    Updated: 2016/09/15 17:35:40 by mblet            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	../corewar
NAMEBASE    =   $(shell basename $(NAME))
LENGTHNAME	=	`printf "%s" $(NAMEBASE) | wc -c`
MAX_COLS	=	$$(echo "$$(tput cols)-24-$(LENGTHNAME)"|bc)

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror -Ofast -ggdb

SRCDIR		=	srcs/
OBJDIR		=	objs/
INCDIR		=	includes/
MLX_DIR		=	../minilibx_macos/
MLX_FLAGS_O	=	-L ./$(MLX_DIR) -framework OPENGL -framework AppKit -lmlx
LIBFT_DIR	=	../libft/
LIBFT_LIB	=	$(LIBFT_DIR)libft.a
LIBXFT_DIR	=	libxft/
LIBXFT_LIB	=	$(LIBXFT_DIR)libxft.a

SRCBASE		=	\
				corewar.c													\
				main.c														\
				mlx/hook.c													\
				mlx/loop_hook.c												\
				mlx/mlx_ini.c												\
				mlx/print.c													\
				op_tab.c													\
				player/creat.c												\
				sgt/sgt_corewar.c											\
				sgt/sgt_mlx.c

SRCS		=	$(addprefix $(SRCDIR), $(SRCBASE))
INCS		=	$(addprefix $(INCDIR), $(INCBASE))
OBJS		=	$(addprefix $(OBJDIR), $(SRCBASE:.c=.o))

.SILENT:

all:		$(NAME)
	echo "\033[38;5;44m☑️  ALL    $(NAMEBASE) is done\033[0m\033[K"

$(NAME):	$(OBJDIR) $(OBJS)
	make -j -C $(MLX_DIR)
	make -j -C $(LIBFT_DIR)
	make -j -C $(LIBXFT_DIR)
	$(CC) $(FLAGS) $(MLX_FLAGS_O) -o $(NAME) $(OBJS)						\
		$(LIBFT_LIB)														\
		$(LIBXFT_LIB)
	echo "\r\033[38;5;22m📗  MAKE   $(NAMEBASE)\033[0m\033[K"

$(OBJDIR):
	mkdir -p $(OBJDIR)
	mkdir -p $(dir $(OBJS))

$(OBJDIR)%.o : $(SRCDIR)%.c | $(OBJDIR)
	$(CC) $(FLAGS) -MMD -c $< -o $@											\
		-I $(LIBFT_DIR)$(INCDIR)											\
		-I $(LIBXFT_DIR)$(INCDIR)											\
		-I $(MLX_DIR)														\
		-I $(INCDIR)
	printf "\r\033[38;5;11m%s%*.*s\033[0m\033[K"							\
		"⌛  MAKE   "$(NAMEBASE)" plz wait ..."								\
		$(MAX_COLS) $(MAX_COLS) "($(@))"

clean:
	printf "\r\033[38;5;11m⌛  CLEAN  $(NAMEBASE) plz wait ...\033[0m\033[K"
	if [[ `rm -R $(OBJDIR) &> /dev/null 2>&1; echo $$?` == "0" ]]; then		\
		echo "\r\033[38;5;124m📕  CLEAN  $(NAMEBASE)\033[0m\033[K";			\
	else																	\
		printf "\r";														\
	fi

fclean:		clean
	printf "\r\033[38;5;11m⌛  FCLEAN $(NAMEBASE) plz wait ...\033[0m\033[K"
	if [[ `rm $(NAME) &> /dev/null 2>&1; echo $$?` == "0" ]]; then			\
		echo "\r\033[38;5;124m📕  FCLEAN $(NAMEBASE)\033[0m\033[K";			\
	else																	\
		printf "\r";														\
	fi

fcleanlib:	fclean
	make -C $(LIBFT_DIR) fclean
	make -C $(LIBXFT_DIR) fclean
	make -C $(MLX_DIR) clean

re:			fclean all

relib:		fclean fcleanlib all

.PHONY:		fclean fcleanlib clean re relib

-include $(OBJS:.o=.d)
