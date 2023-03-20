/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheraul <maheraul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:02:26 by maheraul          #+#    #+#             */
/*   Updated: 2023/02/03 00:15:24 by maheraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	condition(t_data *data, int y, int x)
{
	if (data->map[y][x] != '1' && data->map[y][x] != 'C'
		&& data->map[y][x] != '2' && data->map[y][x] != 'E')
		return (1);
	return (0);
}

int	ft_vertical(int keycode, t_data *data)
{
	int	n;
	int	x;
	int	y;

	n = 0;
	x = data->p_x;
	y = data->p_y;
	if (keycode == W || keycode == UP || keycode == S || keycode == DOWN)
	{
		if (keycode == W || keycode == UP)
			n = -1;
		if (keycode == S || keycode == DOWN)
			n = 1;
		if (condition(data, y + n, x))
		{
			data->map[y + n][x] = 'P';
			data->map[y][x] = '0';
			data->p_y = y + n;
			data->mv++;
			putimage(data, data->mlx);
		}
		ft_printf("MOUVEMENT=%d\n", data->mv);
	}
	return (1);
}

int	ft_horizontal(int keycode, t_data *data)
{
	int	n;
	int	x;

	n = 0;
	x = data->p_x;
	if (keycode == A || keycode == LEFT || keycode == D || keycode == RIGHT)
	{
		if (keycode == A || keycode == LEFT)
			n = -1;
		if (keycode == D || keycode == RIGHT)
			n = 1;
		if (condition(data, data->p_y, x + n))
		{
			data->map[data->p_y][x + n] = 'P';
			data->map[data->p_y][x] = '0';
			data->p_x = x + n;
			data->profil = n;
			data->mv++;
			putimage(data, data->mlx);
		}
		ft_printf("MOUVEMENT=%d\n", data->mv);
	}
	return (1);
}

int	ft_miam(int keycode, t_data *data, int x, int y)
{
	static int	space;
	static int	spa;

	if (keycode == SPACE)
	{
		spa++;
		if (spa % 2)
			data->map[y][x] = 'O';
		else
			data->map[y][x] = 'P';
		putimage(data, data->mlx);
	}
	if (keycode == SPACE && space == 0)
		space_eat(data, 'C', '2', space++);
	else if ((keycode == SPACE && space))
	{
		if (space_eat(data, '2', '3', 0))
			data->c--;
		space = 0;
	}
	return (putimage(data, data->mlx), 1);
}

int	key_hook(int keycode, t_data *data)
{
	int	x;
	int	y;

	x = data->p_x;
	y = data->p_y;
	if (keycode == ECHAP)
		return (mlx_loop_end(data->mlx->mlx));
	if (!ft_vertical(keycode, data) || !ft_horizontal(keycode, data))
		return (0);
	if (!ft_miam(keycode, data, x, y))
		return (0);
	putimage(data, data->mlx);
	data->win = 0;
	ft_win(data);
	return (0);
}
