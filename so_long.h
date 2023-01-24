/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorr <mdorr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:27:00 by mdorr             #+#    #+#             */
/*   Updated: 2023/01/24 19:09:44 by mdorr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include <stdlib.h>
#include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "get_next_line.h"

# define WINDOW_WIDTH 1200
# define WINDOW_HEIGHT 800

# define CLOSE_WINDOW 17
# define KEY_PRESS 2

# define ESCAPE 65307

# define MLX_ERROR 1

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	void *mlx_ptr;
	void *win_ptr;
	t_img img;
}	t_data;


//SO LONG

int	main(int argc, char **argv);
int handle_key_input(int keycode, t_data *data);
int quit_window(t_data *data);
void	image_init(t_data *data);


//CHECK ARG

int	check_arg(int argc, char **argv);
int	parsing(char *map_file);

//STR UTILS

char *cpy_part(char *dest, char *src);
int	ft_strcmp(char *s1, char *s2);
int	ft_strlen(char *str);