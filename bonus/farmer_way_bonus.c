/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   farmer_way.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheraul <maheraul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 21:49:04 by maheraul          #+#    #+#             */
/*   Updated: 2023/02/01 04:06:07 by maheraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_farmer_up(t_data *data, int keycode)
{
	int	x;
	int	y;

	x = data->k_x;
	y = data->k_y;
	if (data->map[y - 1][x] == 'P')
	{
		data->farmer_win = 1;
		data->farmer_img = 1;
		putimage(data, data->mlx);
		ft_lose(keycode, data);
		return (0);
	}
	if (data->map[y - 1][x] == '0' || data->map[y
		- 1][x] == '3')
	{
		data->map[y - 1][x] = 'K';
		data->map[y][x] = '0';
		data->k_y = y - 1;
		putimage(data, data->mlx);
	}
	else
		ft_farmer_down(data, keycode);
	return (1);
}

int	ft_farmer_down(t_data *data, int keycode)
{
	int	x;
	int	y;

	x = data->k_x;
	y = data->k_y;
	if (data->map[y + 1][x] == 'P')
	{
		data->farmer_win = 1;
		data->farmer_img = 2;
		putimage(data, data->mlx);
		ft_lose(keycode, data);
		return (0);
	}
	if (data->map[y + 1][x] == '0' || data->map[y
		+ 1][x] == '3')
	{
		data->map[y + 1][x] = 'K';
		data->map[y][x] = '0';
		data->k_y = y + 1;
		putimage(data, data->mlx);
	}
	else
		ft_farmer_left(data, keycode);
	return (1);
}

int	ft_farmer_left(t_data *data, int keycode)
{
	int	x;
	int	y;

	x = data->k_x;
	y = data->k_y;
	if (data->map[y][x - 1] == 'P')
	{
		data->farmer_win = 1;
		data->farmer_img = 3;
		putimage(data, data->mlx);
		ft_lose(keycode, data);
		return (0);
	}
	if (data->map[y][x - 1] == '0' || data->map[y][x - 1] == '3')
	{
		data->map[y][x - 1] = 'K';
		data->map[y][x] = '0';
		data->k_x = x - 1;
		putimage(data, data->mlx);
	}
	else
		ft_farmer_right(data, keycode);
	return (1);
}

int	ft_farmer_right(t_data *data, int keycode)
{
	int	x;
	int	y;

	x = data->k_x;
	y = data->k_y;
	if (data->map[y][x + 1] == 'P')
	{
		data->farmer_win = 1;
		data->farmer_img = 4;
		putimage(data, data->mlx);
		ft_lose(keycode, data);
		return (0);
	}
	if (data->map[y][x + 1] == '0' || data->map[y][x + 1] == '3')
	{
		data->map[y][x + 1] = 'K';
		data->map[y][x] = '0';
		data->k_x = x + 1;
		putimage(data, data->mlx);
	}
	else
		ft_farmer_up(data, keycode);
	return (1);
}

void	data_farmer(char **map, t_data *data)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'K')
			{
				data->k_x = x;
				data->k_y = y;
			}
			x++;
		}
		y++;
	}
}
