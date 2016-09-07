/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libxft.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/15 16:41:31 by mblet             #+#    #+#             */
/*   Updated: 2016/06/14 21:47:36 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBXFT_H
# define LIBXFT_H

# include <unistd.h>

/*
** Keyboard qwerty mac reference by line
*/
# define LIBX_KEY_ESC				0x35

/*
** line 1
*/
# define LIBX_KEY_TILDE				0x32
# define LIBX_KEY_1					0x12
# define LIBX_KEY_2					0x13
# define LIBX_KEY_3					0x14
# define LIBX_KEY_4					0x15
# define LIBX_KEY_5					0x17
# define LIBX_KEY_6					0x16
# define LIBX_KEY_7					0x1A
# define LIBX_KEY_8					0x1C
# define LIBX_KEY_9					0x19
# define LIBX_KEY_0					0x1D
# define LIBX_KEY_SUB				0x1B
# define LIBX_KEY_ADD				0x18
# define LIBX_KEY_DELETE			0x33

/*
** line 2
*/
# define LIBX_KEY_TAB				0x30
# define LIBX_KEY_Q					0xC
# define LIBX_KEY_W					0xD
# define LIBX_KEY_E					0xE
# define LIBX_KEY_R					0xF
# define LIBX_KEY_T					0x11
# define LIBX_KEY_Y					0x10
# define LIBX_KEY_U					0x20
# define LIBX_KEY_I					0x22
# define LIBX_KEY_O					0x1F
# define LIBX_KEY_P					0x23
# define LIBX_KEY_BRACKET_OPEN		0x21
# define LIBX_KEY_BRACKET_CLOSE		0x1E
# define LIBX_KEY_PIPE				0x2A

/*
** line 3
*/
# define LIBX_KEY_A					0x0
# define LIBX_KEY_S					0x1
# define LIBX_KEY_D					0x2
# define LIBX_KEY_F					0x3
# define LIBX_KEY_G					0x5
# define LIBX_KEY_H					0x4
# define LIBX_KEY_J					0x26
# define LIBX_KEY_K					0x28
# define LIBX_KEY_L					0x25
# define LIBX_KEY_DOUBLE_DOTS		0x29
# define LIBX_KEY_QUOTE				0x27
# define LIBX_KEY_RETURN			0x24

/*
** line 4
*/
# define LIBX_KEY_SHIFT_LEFT		0x101
# define LIBX_KEY_Z					0x6
# define LIBX_KEY_X					0x7
# define LIBX_KEY_C					0x8
# define LIBX_KEY_V					0x9
# define LIBX_KEY_B					0xB
# define LIBX_KEY_N					0x2D
# define LIBX_KEY_M					0x2E
# define LIBX_KEY_INFERIOR			0x2B
# define LIBX_KEY_SUPERIOR			0x2F
# define LIBX_KEY_QUESTION_MARK		0x2C
# define LIBX_KEY_SHIFT_RIGHT		0x102

/*
** line 5
*/
# define LIBX_KEY_CTRL_LEFT			0x100
# define LIBX_KEY_ALT_LEFT			0x105
# define LIBX_KEY_CMD_LEFT			0x103
# define LIBX_KEY_SPACE				0x31
# define LIBX_KEY_CMD_RIGHT			0x104
# define LIBX_KEY_ALT_RIGHT			0x106
# define LIBX_KEY_CTRL_RIGHT		0x10D

/*
** line 1 | col 2 && line 2 | col 2
*/
# define LIBX_KEY_FN				0x117
# define LIBX_KEY_HOME				0x73
# define LIBX_KEY_PAGE_UP			0x74
# define LIBX_KEY_SUPPR				0x75
# define LIBX_KEY_END				0x77
# define LIBX_KEY_PAGE_DOWN			0x79

/*
** direction pad
*/
# define LIBX_KEY_UP				0x7E
# define LIBX_KEY_LEFT				0x7B
# define LIBX_KEY_DOWN				0x7D
# define LIBX_KEY_RIGHT				0x7C

/*
** numpad
*/
# define LIBX_KEY_CLEAR				0x47
# define LIBX_KEY_NUMPAD_EQUAL		0x51
# define LIBX_KEY_NUMPAD_DIV		0x4B
# define LIBX_KEY_NUMPAD_MUL		0x43
# define LIBX_KEY_NUMPAD_7			0x59
# define LIBX_KEY_NUMPAD_8			0x5B
# define LIBX_KEY_NUMPAD_9			0x5C
# define LIBX_KEY_NUMPAD_SUB		0x4E
# define LIBX_KEY_NUMPAD_4			0x56
# define LIBX_KEY_NUMPAD_5			0x57
# define LIBX_KEY_NUMPAD_6			0x58
# define LIBX_KEY_NUMPAD_ADD		0x45
# define LIBX_KEY_NUMPAD_1			0x53
# define LIBX_KEY_NUMPAD_2			0x54
# define LIBX_KEY_NUMPAD_3			0x55
# define LIBX_KEY_NUMPAD_0			0x52
# define LIBX_KEY_NUMPAD_DOT		0x41
# define LIBX_KEY_NUMPAD_ENTER		0x4C

# define LIBX_MOUSE_BUTTON_LEFT		1
# define LIBX_MOUSE_BUTTON_RIGHT	2
# define LIBX_MOUSE_BUTTON_MIDDLE	3
# define LIBX_MOUSE_SCROLL_UP		4
# define LIBX_MOUSE_SCROLL_DOWN		5

typedef struct	s_libx_color
{
	double		r;
	double		g;
	double		b;
}				t_libx_color;

typedef struct	s_libx_img
{
	void		*img_ptr;
	int			width;
	int			height;
	char		*buffer;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_libx_img;

typedef void	(*t_libx_key_func)(void*);

/*
** libx_init
*/
void			libx_func_key(int key, t_libx_key_func f);
void			libx_hook_key(int key, void *e);

/*
** libx_new_image
** parameters :
** void			*mlx	// (void * mlx = mlx_init())
** int			width
** int			height
** return :
** (malloc)t_libx_img	new
*/
t_libx_img		*libx_new_image(void *mlx, int width, int height);

/*
** libx_new_image
** parameters :
** void			*mlx	// (void * mlx = mlx_init())
** t_libx_img	*img
*/
void			libx_destroy_image(void *mlx, t_libx_img *img);

/*
** libx_xpm_file_to_image
** parameters :
** void			*mlx		// (void * mlx = mlx_init())
** char			*path_file
** return :
** (malloc)t_libx_img	new
*/
t_libx_img		*libx_xpm_file_to_image(void *mlx, char *path_file);

/*
** basic functions
*/
void			libx_put_pixel_to_image(t_libx_img *img,
		int x, int y, int color);

/*
** WARNING : if you want use this function please make sure int cast :
**			-x1
**			-y1
**			-x2
**			-y2
**			-color
** libx_draw_line_to_image
** parameters :
** t_libx_img	*img
** int			x1
** int			y1
** int			x2
** int			y2
** int			color
*/
void			libx_draw_line_to_image(t_libx_img *img, ...);

/*
** WARNING : if you want use this function please make sure int cast :
**			-x1
**			-y1
**			-x2
**			-y2
**			-color
** libx_circle_to_image
** parameters :
** t_libx_img	*img
** int			x
** int			y
** int			w
** int			h
** int			color
*/
void			libx_draw_circle_to_image(t_libx_img *img, ...);

/*
** WARNING : if you want use this function please make sure int cast :
**			-x1
**			-y1
**			-x2
**			-y2
**			-color
** libx_circle_to_image
** parameters :
** t_libx_img	*img
** int			x
** int			y
** int			w
** int			h
** int			color
*/
void			libx_draw_square_to_image(t_libx_img *img, ...);

/*
** WARNING : if you want use this function please make sure int cast :
**			-x
**			-y
**			-color
** libx_string_to_image
** parameters :
** t_libx_img	*img
** t_libx_img	*font
** char			*string
** int			x
** int			y
** int			color
*/
void			libx_string_to_image(t_libx_img *img, t_libx_img *font,
		const char *str, ...);

/*
** libx_int_to_color
** parameters :
** int			color
** return :
** t_libx_color	color
*/
t_libx_color	libx_int_to_color(int color);

/*
** libx_color_to_int
** parameters :
** t_libx_color	color
** return :
** int			color
*/
int				libx_color_to_int(t_libx_color color);

/*
** libx_image_to_image
** paramters :
** t_libx_img	*dst
** t_libx_img	*src
** int			x
** int			y
** return :
** int			color
*/
int				libx_get_color_in_image(t_libx_img *img, int x, int y);

/*
** libx_image_to_image
** paramters :
** t_libx_img	*dst
** t_libx_img	*src
** int			dst.x
** int			dst.y
** int			src.x
** int			src.y
** int			width	// if (width <= 0) width = src->width
** int			height	// if (width <= 0) height = src->height
*/
void			libx_image_to_image(t_libx_img *dst, t_libx_img *src,
		...);

/*
** libx_image_to_image_png
** paramters :
** t_libx_img	*dst
** t_libx_img	*src
** int			dst.x
** int			dst.y
** int			src.x
** int			src.y
** int			width	// if (width <= 0) width = src->width
** int			height	// if (width <= 0) height = src->height
** int			color
*/
void			libx_image_to_image_png(t_libx_img *dst, t_libx_img *src,
		...);

/*
** libx_image_fill
** paramters :
** t_libx_img	*img
** int			color
*/
void			libx_image_fill(t_libx_img *img, int color);

/*
** counts the number of args
*/
# define NARGS_SEQ(_1, _2, _3, _4, _5, _6, _7, _8, N, ...) N
# define NARGS(...) NARGS_SEQ(__VA_ARGS__, 8, 7, 6, 5, 4, 3, 2, 1)

/*
** will let macros expand before concating them
*/
# define PRIMITIVE_CAT(x, y) x ## y
# define CAT(x, y) PRIMITIVE_CAT(x, y)

/*
** will call a macro on each argument passed in
*/
# define APPLY(macro, ...) CAT(APPLY_, NARGS(__VA_ARGS__))(macro, __VA_ARGS__)
# define APPLY_1(m,a) m(a)
# define APPLY_2(m,a,b) m(a),m(b)
# define APPLY_3(m,a,b,c) m(a),m(b),m(c)
# define APPLY_4(m,a,b,c,d) m(a),m(b),m(c),m(d)
# define APPLY_5(m,a,b,c,d,e) m(a),m(b),m(c),m(d),m(e)
# define APPLY_6(m,a,b,c,d,e,f) m(a),m(b),m(c),m(d),m(e),m(f)
# define APPLY_7(m,a,b,c,d,e,f,g) m(a),m(b),m(c),m(d),m(e),m(f),m(g)
# define APPLY_8(m,a,b,c,d,e,f,g,h) m(a),m(b),m(c),m(d),m(e),m(f),m(g),m(h)

# define __D0		libx_draw_line_to_image
# define __D1		libx_draw_circle_to_image
# define __D2		libx_draw_square_to_image
# define __D3		libx_string_to_image
# define __D8		libx_image_to_image
# define __D9		libx_image_to_image_png
# define __D0_C(x)	(int)(x)

# define LIBX_DRAW_LINE_TO_IMAGE(i,...) __D0(i,APPLY(__D0_C, __VA_ARGS__))
# define LIBX_DRAW_CIRCLE_TO_IMAGE(i,...) __D1(i,APPLY(__D0_C, __VA_ARGS__))
# define LIBX_DRAW_SQUARE_TO_IMAGE(i,...) __D2(i,APPLY(__D0_C, __VA_ARGS__))
# define LIBX_STRING_TO_IMAGE(i,f,s,...) __D3(i,f,s,APPLY(__D0_C, __VA_ARGS__))
# define LIBX_IMAGE_TO_IMAGE(d,s,...) __D8(d,s,APPLY(__D0_C, __VA_ARGS__))
# define LIBX_IMAGE_TO_IMAGE_PNG(d,s,...) __D9(d,s,APPLY(__D0_C, __VA_ARGS__))

#endif
