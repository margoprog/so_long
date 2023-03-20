/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_farmer_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheraul <maheraul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 20:41:41 by maheraul          #+#    #+#             */
/*   Updated: 2023/01/31 22:37:27 by maheraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <time.h>

int	ft_random(t_data *data)
{
	int	random_nb;
	int	seed;

	if (data->mv % 3 == 0)
		seed = data->p_y;
	else
		seed = data->p_x;
	srand(time(NULL));
	random_nb = (rand() % 4) + 1;
	return (random_nb);
}

void	putfarmer(t_data *data, t_mlx *mlx, int y, int x)
{
	if (data->farmer_img == 0)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img[3], x * 64, y
			* 64);
	if (data->farmer_img == 1)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img[20], x * 64, y
			* 64);
	if (data->farmer_img == 2)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img[21], x * 64, y
			* 64);
	if (data->farmer_img == 3)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img[22], x * 64, y
			* 64);
	if (data->farmer_img == 4)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img[23], x * 64, y
			* 64);
}

int	ft_farmer_move(int random, t_data *data, int keycode)
{
	if (random == 1)
	{
		if (!ft_farmer_left(data, keycode))
			return (0);
	}
	if (random == 2)
	{
		if (!ft_farmer_up(data, keycode))
			return (0);
	}
	if (random == 3)
	{
		if (!ft_farmer_down(data, keycode))
			return (0);
	}
	if (random == 4)
	{
		if (!ft_farmer_right(data, keycode))
			return (0);
	}
	return (1);
}
