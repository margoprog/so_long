/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_logo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheraul <maheraul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 04:25:13 by maheraul          #+#    #+#             */
/*   Updated: 2023/02/02 04:34:32 by maheraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	putlogo2(t_mlx *mlx, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img[6], (x - 3)
		* 64, y * 64);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img[7], (x - 2)
		* 64, y * 64);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img[8], (x - 1)
		* 64, y * 64);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img[9], x * 64,
		y * 64);
}

void	putlogo3(t_data *data, t_mlx *mlx, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->nb[data->n4],
		(x - 3) * 64, y * 64);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->nb[data->n3],
		(x - 2) * 64, y * 64);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->nb[data->n2],
		(x - 1) * 64, y * 64);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->nb[data->n1], x
		* 64, y * 64);
}

void	putlogo(t_data *data, t_mlx *mlx)
{
	int	x;
	int	y;

	y = data->h;
	x = 0;
	ft_putn(data->mv, data);
	while (y < (data->h) + 4)
	{
		while (x < data->l)
		{
			if (x == (data->l) / 2 + 1 && y == data->h + 1)
				putlogo3(data, mlx, x, y);
			else if (x == (data->l) / 2 + 1 && y == (data->h) + 2)
				putlogo2(mlx, x, y);
			else
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img[0], x * 64,
					y * 64);
			x++;
		}
		x = 0;
		y++;
	}
}
