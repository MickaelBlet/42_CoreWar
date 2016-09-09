# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mblet <mblet@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/07 09:22:24 by mblet             #+#    #+#              #
#    Updated: 2016/09/08 15:52:26 by mblet            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	corewar
NAMEBASE    =   $(shell basename $(NAME))
LENGTHNAME	=	`printf "%s" $(NAMEBASE) | wc -c`
MAX_COLS	=	$$(echo "$$(tput cols)-24-$(LENGTHNAME)"|bc)

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror -O3

SRCDIR		=	srcs/
OBJDIR		=	objs/
INCDIR		=	includes/
LIBFT_DIR	=	libft/
LIBFT_LIB	=	$(LIBFT_DIR)libft.a
LIBXFT_DIR	=	libxft/
LIBXFT_LIB	=	$(LIBXFT_DIR)libxft.a
MLX_DIR		=	.minilibx_macos/
MLX_FLAGS_O	=	-L ./$(MLX_DIR) -framework OPENGL -framework AppKit -lmlx

SRCBASE		=	\
				corewar.c													\
				main.c														\
				op/check_args.c												\
				op/ini_op.c													\
				op/ld.c														\
				op/live.c													\
				player/creat.c												\
				sgt/sgt_corewar.c

SRCS		=	$(addprefix $(SRCDIR), $(SRCBASE))
INCS		=	$(addprefix $(INCDIR), $(INCBASE))
OBJS		=	$(addprefix $(OBJDIR), $(SRCBASE:.c=.o))

.SILENT:

all:
	$(MAKE) -j $(NAME)
	echo "\033[38;5;44m☑️  ALL    $(NAMEBASE) is done\033[0m\033[K"

$(NAME):	$(OBJDIR) $(OBJS)
	make -C $(MLX_DIR)
	make -C $(LIBFT_DIR)
	make -C $(LIBXFT_DIR)
	$(CC) $(FLAGS) $(MLX_FLAGS_O) -o $(NAME) $(OBJS)						\
		$(LIBFT_LIB)														\
		$(LIBXFT_LIB)
	echo "\r\033[38;5;22m📗  MAKE   $(NAMEBASE)\033[0m\033[K"
	echo "\r\033[38;5;184m👥  GROUP MEMBER(S):\033[0m\033[K"
	echo "\r\033[38;5;15m`cat auteur | sed s/^/\ \ \ \ -/g`\033[0m\033[K"

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
