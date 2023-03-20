/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheraul <maheraul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 04:36:01 by maheraul          #+#    #+#             */
/*   Updated: 2023/02/02 04:38:07 by maheraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_closewin(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 24)
		mlx_destroy_image(data->mlx->mlx, data->mlx->img[i]);
	i = -1;
	while (++i < 10)
		mlx_destroy_image(data->mlx->mlx, data->mlx->nb[i]);
	if (data->lose == 1 || data->win == 1)
	{
		mlx_clear_window(data->mlx->mlx, data->mlx->win_win);
		mlx_destroy_window(data->mlx->mlx, data->mlx->win_win);
	}
	mlx_clear_window(data->mlx->mlx, data->mlx->win);
	mlx_destroy_window(data->mlx->mlx, data->mlx->win);
	mlx_destroy_display(data->mlx->mlx);
	free(data->mlx->mlx);
	ft_freetab(data->map);
	exit(EXIT_SUCCESS);
	return (0);
}

int	ft_close(t_data *data)
{
	ft_closewin(data);
	exit(1);
}

int	escape(int keycode, t_data *data)
{
	if (keycode == ECHAP)
		return (ft_closewin(data));
	return (0);
}

void	closegame(t_data *data, int value, char *str)
{
	data->lose = 1;
	data->mlx->win_win = mlx_new_window(data->mlx->mlx, 500, 500, str);
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win_win,
		data->mlx->img[value], 0, 0);
	mlx_hook(data->mlx->win_win, 17, 0, &ft_close, data);
	mlx_key_hook(data->mlx->win_win, &escape, data);
	data->farmer_img = 400;
}
