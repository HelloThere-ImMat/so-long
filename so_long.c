/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorr <mdorr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:23:23 by mdorr             #+#    #+#             */
/*   Updated: 2023/01/24 19:08:16 by mdorr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	image_init(t_data *data)
{
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &(*data).img.bpp, &(*data).img.line_len, &(*data).img.endian);
}

int quit_window(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	free(data->mlx_ptr);

	printf("DESTROYED ;)\n");
	exit(EXIT_SUCCESS);
}

int handle_key_input(int keycode, t_data *data)
{
	if (keycode == ESCAPE)
	{
		mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
		free(data->mlx_ptr);
		printf("DESTROYED ;)\n");
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data data;
	int test;

	if (check_arg(argc, argv) == 1)
	{
		printf("argument error\n");
		return (1);
	}

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "first window");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}
	image_init(&data);
	mlx_hook(data.win_ptr, KEY_PRESS, KeyPressMask, &handle_key_input, &data);
	mlx_hook(data.win_ptr, CLOSE_WINDOW, LeaveWindowMask, &quit_window, &data);
	mlx_loop(data.mlx_ptr);

}