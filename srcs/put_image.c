/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheraul <maheraul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 02:09:19 by maheraul          #+#    #+#             */
/*   Updated: 2023/02/02 18:28:27 by maheraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_orientation(t_data *data, t_mlx *mlx, int y, int x)
{
	if (data->profil == -1)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img[16], x * 64, y
			* 64);
	else
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img[5], x * 64, y
			* 64);
}

void	ft_gime_flower(t_data *data, t_mlx *mlx, int y, int x)
{
	if (data->c == 0)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img[13], x * 64, y
			* 64);
	else
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img[2], x * 64, y
			* 64);
}

void	ft_love(t_data *data, t_mlx *mlx, int y, int x)
{
	if (data->c == 0)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img[17], x * 64, y
			* 64);
	else
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img[1], x * 64, y
			* 64);
}

void	ft_foret_de_if(t_data *data, t_mlx *mlx, int y, int x)
{
	if (data->map[y][x] == 'O')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img[10], x * 64, y
			* 64);
	else if (data->map[y][x] == '2')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img[11], x * 64, y
			* 64);
	else if (data->map[y][x] == '3')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img[12], x * 64, y
			* 64);
}

void	putimage(t_data *data, t_mlx *mlx)
{
	int	y;
	int	x;

	y = -1;
	while (++y < data->h)
	{
		x = -1;
		while (++x < data->l)
		{
			if (data->map[y][x] == '1')
				ft_love(data, mlx, y, x);
			else if (data->map[y][x] == '0')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img[0], x * 64,
					y * 64);
			else if (data->map[y][x] == 'P')
				ft_orientation(data, mlx, y, x);
			else if (data->map[y][x] == 'E')
				ft_gime_flower(data, mlx, y, x);
			else if (data->map[y][x] == 'C')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img[4], x * 64,
					y * 64);
			else
				ft_foret_de_if(data, mlx, y, x);
		}
	}
}
