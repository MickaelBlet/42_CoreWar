# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mblet <mblet@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/12 12:10:01 by mblet             #+#    #+#              #
#    Updated: 2016/11/21 09:19:12 by mblet            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	_
NAMEBASE    =   $(shell basename $(NAME))
LENGTHNAME	=	`printf "%s" $(NAMEBASE) | wc -c`
MAX_COLS	=	$$(echo "$$(tput cols)-24-$(LENGTHNAME)"|bc)

LIBFT_DIR	=	libft/
ASM_DIR		=	asm_dir/
DASM_DIR	=	dasm_dir/
VM_DIR		=	vm_dir/

.SILENT:

all:
	$(MAKE) -j $(NAME)

$(NAME):
	make -C $(LIBFT_DIR)
	make -C $(ASM_DIR)
	make -C $(DASM_DIR)
	make -C $(VM_DIR)
	echo "\r\033[38;5;184m👥  GROUP MEMBER(S):\033[0m\033[K"
	echo "\r\033[38;5;15m`cat auteur | sed s/^/\ \ \ \ -/g`\033[0m\033[K"

clean:
	make -C $(ASM_DIR) clean
	make -C $(DASM_DIR) clean
	make -C $(VM_DIR) clean

fclean:		clean
	make -C $(ASM_DIR) fclean
	make -C $(DASM_DIR) fclean
	make -C $(VM_DIR) fclean

fcleanlib:	fclean
	make -C $(ASM_DIR) fcleanlib
	make -C $(DASM_DIR) fcleanlib
	make -C $(VM_DIR) fcleanlib
	make -C $(LIBFT_DIR) fclean

re:			fclean all

relib:		fclean fcleanlib all

.PHONY:		fclean fcleanlib clean re relib
