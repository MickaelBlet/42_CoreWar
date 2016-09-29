/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 09:22:40 by mblet             #+#    #+#             */
/*   Updated: 2016/09/28 16:19:36 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "../../includes/common_corewar.h"

# include <fcntl.h>
# include <libft.h>
# include <libxft.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

# define MSG_USAGE		"./corewar [-dump nbr_cycles] [[-n number] file.cor]"

# define ERR_OPEN_FILE			"corewar: Can't open file \"%s\".\n"
# define ERR_SAME_ID			"corewar: Same file id.\n"
# define ERR_FILE_TOO_LARGE		"corewar: File \"%s\" is too large.\n"
# define ERR_FILE_NOT_VALID		"corewar: File \"%s\" not valid.\n"
# define ERR_TOO_MANY_PLAYERS	"corewar: Too many players.\n"

typedef struct		s_byte
{
	unsigned char	data;
	int				id;
	t_bool			modified;
	t_bool			live;
}					t_byte;

typedef struct		s_process
{
	int				id;
	int				index;
	int				reg[REG_NUMBER];
	t_byte			*pc;
	int				live;
	int				carry;
	int				op_cycle;
}					t_process;

typedef struct		s_file
{
	int				id;
	t_header		*header;
	char			data[CHAMP_MAX_SIZE + sizeof(t_header)];
}					t_file;

typedef struct		s_corewar
{
	size_t			nbr_cycles;
	size_t			nbr_live;
	t_byte			ram[MEM_SIZE];
	t_listd			*files;
	t_listd			*players;
}					t_corewar;

typedef void		(*t_func_op)(t_player *);

/*
** MAIN
*/
void				corewar(int argc, char **argv);

/*
** SGT
*/
t_corewar			**sgt_addr_corewar(void);
t_corewar			*sgt_corewar(void);

/*
** OPTION
*/
t_bool				vm_check_option(int argc, char **argv);

/*
** FILE
*/
void				vm_check_file(int *i, char **argv);
t_vm_file			*file_read(char *file_name);
t_header			*file_get_header(void *ptr);

/*
** OP
*/
int					get_reg_value(t_byte *b);
int					get_dir_value(t_byte *b);
int					get_ind_value(t_byte *b);
void				set_1byte_value(t_player *player, t_byte *b,
		unsigned char value);
void				set_2byte_value(t_player *player, t_byte *b,
		unsigned short value);
void				set_4byte_value(t_player *player, t_byte *b,
		unsigned int value);
void				check_op(t_player *player);
void				byte_code_to_type(int (*t)[4], unsigned char b);
t_op				op_tab(int index);
t_func_op			func_tab(int index);
void				vm_live(t_player *player);
void				vm_ld(t_player *player);
void				vm_st(t_player *player);
void				vm_add(t_player *player);
void				vm_sub(t_player *player);
void				vm_and(t_player *player);
void				vm_or(t_player *player);
void				vm_xor(t_player *player);
void				vm_zjmp(t_player *player);
void				vm_ldi(t_player *player);
void				vm_sti(t_player *player);
void				vm_fork(t_player *player);
void				vm_lld(t_player *player);
void				vm_lldi(t_player *player);
void				vm_lfork(t_player *player);
void				vm_aff(t_player *player);

/*
** PLAYER
*/
t_player			*player_creat(int id, char *file_name);
t_header			*player_get_header(void *ptr);

/*
** #############################################################################
**                                     MLX
** #############################################################################
*/
# define VM_WIN_WIDTH		2000
# define VM_WIN_HEIGHT		1190
# define VM_FONT_PATH		"./resources/font/11.xpm"

# define VM_COLOR_PLAYER1	0xA00000
# define VM_COLOR_PLAYER2	0x00A000
# define VM_COLOR_PLAYER3	0xA0A000
# define VM_COLOR_PLAYER4	0x0000A0
# define VM_COLOR_PLAYER5	0xA000A0
# define VM_COLOR_PLAYER6	0x00A0A0

typedef struct		s_vm_mlx
{
	void			*mlx;
	void			*win;
	t_libx_img		*img_main;
	t_libx_img		*img_font;
	t_libx_img		*img_ram;
}					t_vm_mlx;

/*
** ...
*/
t_bool				vm_mlx_init(void);
int					vm_hook_key(int key, t_vm_mlx *mlx);
void				vm_press_key_esc(t_vm_mlx *mlx);
void				vm_mlx_print(void);
int					vm_mlx_loop_hook(void *mlx);

/*
** SGT
*/
t_vm_mlx			**sgt_addr_mlx(void);
t_vm_mlx			*sgt_mlx(void);

#endif
