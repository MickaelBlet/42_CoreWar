# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mblet <mblet@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/12 12:08:30 by mblet             #+#    #+#              #
#    Updated: 2016/10/29 22:39:48 by mblet            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	../asm
NAMEBASE    =   $(shell basename $(NAME))
LENGTHNAME	=	`printf "%s" $(NAMEBASE) | wc -c`
MAX_COLS	=	$$(echo "$$(tput cols)-24-$(LENGTHNAME)"|bc)

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror -O3

SRCDIR		=	srcs/
OBJDIR		=	objs/
INCDIR		=	includes/
LIBFT_DIR	=	../libft/
LIBFT_LIB	=	$(LIBFT_DIR)libft.a

SRCBASE		=	\
				asm.c														\
				command/check_same.c										\
				command/comment.c											\
				command/name.c												\
				errors/list_print.c											\
				errors/print.c												\
				errors/warning.c											\
				file/clean.c												\
				file/read.c													\
				file/write.c												\
				ini_cor.c													\
				label/add.c													\
				label/check_name.c											\
				label/check_same.c											\
				label/get_addr_label.c										\
				line/check_command.c										\
				line/check_label.c											\
				line/check_op.c												\
				line/creat.c												\
				line/label_scan.c											\
				line/scan.c													\
				line/scan_op.c												\
				main.c														\
				op/arg_to_cor.c												\
				op/check_name.c												\
				op/get_from_name.c											\
				op/get_type.c												\
				op/to_cor.c													\
				op_tab.c													\
				sgt/sgt_asm.c

SRCS		=	$(addprefix $(SRCDIR), $(SRCBASE))
INCS		=	$(addprefix $(INCDIR), $(INCBASE))
OBJS		=	$(addprefix $(OBJDIR), $(SRCBASE:.c=.o))

.SILENT:

all:
	$(MAKE) -j $(NAME)
	echo "\033[38;5;44m☑️  ALL    $(NAMEBASE) is done\033[0m\033[K"

$(NAME):	$(OBJDIR) $(OBJS)
	make -C $(LIBFT_DIR)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT_LIB)
	echo "\r\033[38;5;22m📗  MAKE   $(NAMEBASE)\033[0m\033[K"

$(OBJDIR):
	mkdir -p $(OBJDIR)
	mkdir -p $(dir $(OBJS))

$(OBJDIR)%.o : $(SRCDIR)%.c | $(OBJDIR)
	$(CC) $(FLAGS) -MMD -c $< -o $@											\
		-I $(LIBFT_DIR)$(INCDIR)											\
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

re:			fclean all

relib:		fclean fcleanlib all

.PHONY:		fclean fcleanlib clean re relib

-include $(OBJS:.o=.d)
