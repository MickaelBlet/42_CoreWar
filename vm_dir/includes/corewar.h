/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 09:22:40 by mblet             #+#    #+#             */
/*   Updated: 2016/09/15 18:09:12 by mblet            ###   ########.fr       */
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

typedef struct	s_player
{
	int			id;
	char		name[PROG_NAME_LENGTH];
	char		comment[COMMENT_LENGTH];
	t_arg_type	*pc;
	t_arg_type	data[CHAMP_MAX_SIZE + sizeof(t_header)];
	int			reg[REG_NUMBER];
}				t_player;

typedef struct	s_corewar
{
	size_t		nbr_cycles;
	t_listd		*players;
	t_arg_type	ram[MEM_SIZE];
}				t_corewar;

/*
** MAIN
*/
void			corewar(void);

/*
** SGT
*/
t_corewar		**sgt_addr_corewar(void);
t_corewar		*sgt_corewar(void);

/*
** OP
*/
t_op			op_tab(int index);

/*
** PLAYER
*/
t_player		*player_creat(int id, char *file_name);

/*
** MLX
*/
# define VM_WIN_WIDTH		2000
# define VM_WIN_HEIGHT		1380
# define VM_FONT_PATH		"./resources/font/11.xpm"

typedef struct	s_vm_mlx
{
	void		*mlx;
	void		*win;
	t_libx_img	*main;
	t_libx_img	*font;
	t_libx_img	*ram;
}				t_vm_mlx;

/*
**
*/
t_bool			vm_mlx_init(void);
int				vm_hook_key(int key, t_vm_mlx *mlx);
void			vm_press_key_esc(void *mlx);
void			vm_mlx_print(void);
int				vm_mlx_loop_hook(void *mlx);

/*
** SGT
*/
t_vm_mlx		**sgt_addr_mlx(void);
t_vm_mlx		*sgt_mlx(void);

#endif
