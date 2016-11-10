# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mblet <mblet@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/04/15 16:40:45 by mblet             #+#    #+#              #
#    Updated: 2016/11/10 02:05:21 by mblet            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libxft.a

NAMEBASE    =   $(shell basename $(NAME) .a)

LENGTHNAME	=	`printf "%s" $(NAMEBASE) | wc -c`

MAX_COLS	=	$$(echo "$$(tput cols)-24-$(LENGTHNAME)"|bc)

CC			=	gcc

FLAGS		=	-Wall -Wextra -Werror -O3

SRCDIR		=	srcs/

OBJDIR		=	objs/

INCDIR		=	includes/

MLX_DIR		=	../../minilibx_macos/

SRCBASE		=	\
				color_to_int.c												\
				destroy_image.c												\
				draw_circle_to_image.c										\
				draw_line_to_image.c										\
				draw_square_to_image.c										\
				func_key.c													\
				get_color_in_image.c										\
				image_fill.c												\
				image_to_image.c											\
				image_to_image_png.c										\
				int_to_color.c												\
				new_image.c													\
				put_pixel_to_image.c										\
				string_to_image.c											\
				xpm_file_to_image.c

INCBASE		=	\
				libxft.h

SRCS		=	$(addprefix $(SRCDIR), $(SRCBASE))

INCS		=	$(addprefix $(INCDIR), $(INCBASE))

OBJS		=	$(addprefix $(OBJDIR), $(SRCBASE:.c=.o))

.SILENT:

all:		$(NAME)

$(NAME):	$(OBJDIR) $(OBJS)
	ar rc $(NAME) $(OBJS) $(OBJSPRINTF)
	ranlib $(NAME)
	echo "\r\033[38;5;25m📘  MAKE   $(NAMEBASE)\033[0m\033[K"

$(OBJDIR):
	mkdir -p $(OBJDIR)
	mkdir -p $(dir $(OBJS))

$(OBJDIR)%.o : $(SRCDIR)%.c | $(OBJDIR)
	$(CC) $(FLAGS) -MMD -c $< -o $@ -I $(INCDIR) -I $(MLX_DIR)
	printf "\r\033[38;5;11m⌛  MAKE   %s plz wait ...%*s\033[0m\033[K"		\
		$(NAMEBASE) $(MAX_COLS) "($@)"

clean:
	printf "\r\033[38;5;11m⌛  CLEAN  $(NAMEBASE) plz wait ...\033[0m\033[K"
	if [[ `rm -R $(OBJDIR) &> /dev/null 2>&1; echo $$?` == "0" ]]; then		\
		echo -en "\r\033[38;5;124m📕  CLEAN  $(NAMEBASE)\033[0m\033[K";		\
	else																	\
		printf "\r";														\
	fi

fclean:		clean
	printf "\r\033[38;5;11m⌛  FCLEAN $(NAMEBASE) plz wait ...\033[0m\033[K"
	if [[ `rm $(NAME) &> /dev/null 2>&1; echo $$?` == "0" ]]; then			\
		echo -en "\r\033[38;5;124m📕  FCLEAN $(NAMEBASE)\033[0m\033[K";		\
	else																	\
		printf "\r";														\
	fi

re:			fclean all

.PHONY:		fclean clean re
