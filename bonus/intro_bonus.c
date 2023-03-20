/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheraul <maheraul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:28:23 by maheraul          #+#    #+#             */
/*   Updated: 2023/01/31 22:42:39 by maheraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	ft_win_to_close(t_op *op)
{
	return (mlx_loop_end(op->mlx));
}

int	key_opening(int keycode, t_op *op)
{
	if (keycode == ECHAP)
		return (mlx_loop_end(op->mlx));
	if (keycode == SPACE)
	{
		op->data->isgameon = 1;
		op->data->mv = 0;
		mlx_loop_end(op->mlx);
	}
	return (0);
}

int	ft_intro(t_data *data)
{
	t_op	op;
	int		r;

	ft_memset(&op, 0, sizeof(t_op));
	op.data = data;
	op.mlx = mlx_init();
	op.win = mlx_new_window(op.mlx, 1444, 960, "OPENING");
	op.intro = mlx_xpm_file_to_image(op.mlx, "images/opening.xpm", &r, &r);
	mlx_put_image_to_window(op.mlx, op.win, op.intro, 0, 0);
	mlx_key_hook(op.win, key_opening, &op);
	mlx_hook(op.win, 17, 0, &ft_win_to_close, &op);
	mlx_loop(op.mlx);
	mlx_clear_window(op.mlx, op.win);
	mlx_destroy_window(op.mlx, op.win);
	mlx_destroy_image(op.mlx, op.intro);
	mlx_destroy_display(op.mlx);
	free(op.mlx);
	if (data->isgameon == 0)
		return (1);
	return (0);
}
