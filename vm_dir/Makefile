# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mblet <mblet@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/07 09:22:24 by mblet             #+#    #+#              #
#    Updated: 2016/11/07 00:52:58 by mblet            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	../corewar
NAMEBASE    =   $(shell basename $(NAME))
LENGTHNAME	=	`printf "%s" $(NAMEBASE) | wc -c`
MAX_COLS	=	$$(echo "$$(tput cols)-24-$(LENGTHNAME)"|bc)

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror -O3

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
				cycle.c														\
				dump.c														\
				file/check.c												\
				file/get_header.c											\
				file/read.c													\
				func_tab.c													\
				func_verbose_tab.c											\
				main.c														\
				mlx/draw/background.c										\
				mlx/draw/fill_transparent_rect.c							\
				mlx/draw/info.c												\
				mlx/draw/memory.c											\
				mlx/draw/pause.c											\
				mlx/draw/rect.c												\
				mlx/draw/tooltip.c											\
				mlx/get_position_memory_from_pc.c							\
				mlx/keys/add.c												\
				mlx/keys/esc.c												\
				mlx/keys/key_0.c											\
				mlx/keys/key_9.c											\
				mlx/keys/s.c												\
				mlx/keys/space.c											\
				mlx/keys/sub.c												\
				mlx/launch.c												\
				mlx/loop_hook.c												\
				mlx/mlx_init.c												\
				mlx/mouse/byte_position_mouse.c								\
				mlx/mouse/motion.c											\
				mlx/threads/info.c											\
				mlx/threads/memory.c										\
				mlx/tooltip/info_byte/get_info.c							\
				op/add.c													\
				op/aff.c													\
				op/and.c													\
				op/byte_code_to_type.c										\
				op/check_type_args.c										\
				op/fork.c													\
				op/ld.c														\
				op/ldi.c													\
				op/lfork.c													\
				op/live.c													\
				op/lld.c													\
				op/lldi.c													\
				op/or.c														\
				op/st.c														\
				op/sti.c													\
				op/sub.c													\
				op/xor.c													\
				op/zjmp.c													\
				option.c													\
				op_tab.c													\
				player/creat.c												\
				process/action.c											\
				process/check_live.c										\
				process/creat.c												\
				process/fork.c												\
				process/jump.c												\
				ram/get_values.c											\
				ram/ini_ram.c												\
				ram/set_values.c											\
				sgt/sgt_corewar.c											\
				sgt/sgt_mlx.c												\
				thread/launch.c												\
				thread/vm.c													\
				usage.c														\
				verbosity/cycle.c											\
				verbosity/cycle_to_die.c									\
				verbosity/death.c											\
				verbosity/live.c											\
				verbosity/move.c											\
				verbosity/op/add.c											\
				verbosity/op/aff.c											\
				verbosity/op/and.c											\
				verbosity/op/fork.c											\
				verbosity/op/ld.c											\
				verbosity/op/ldi.c											\
				verbosity/op/lfork.c										\
				verbosity/op/live.c											\
				verbosity/op/lld.c											\
				verbosity/op/lldi.c											\
				verbosity/op/or.c											\
				verbosity/op/st.c											\
				verbosity/op/sti.c											\
				verbosity/op/sub.c											\
				verbosity/op/xor.c											\
				verbosity/op/zjmp.c											\
				verbosity/op.c												\
				win.c

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
