/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheraul <maheraul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 00:29:03 by maheraul          #+#    #+#             */
/*   Updated: 2023/02/02 04:35:51 by maheraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_win(t_data *data)
{
	int	x;
	int	y;

	x = data->p_x;
	y = data->p_y;
	if ((data->map[y + 1][x] == 'E' || data->map[y - 1][x] == 'E'
			|| data->map[y][x + 1] == 'E' || data->map[y][x - 1] == 'E')
		&& data->c == 0)
	{
		closegame(data, 15, "WIN");
	}
}

int	ft_lose(int keycode, t_data *data)
{
	int	x;
	int	y;

	x = data->p_x;
	y = data->p_y;
	(void)keycode;
	if ((data->map[y + 1][x] == 'K' && (keycode == S || keycode == DOWN)) ||
		(data->map[y - 1][x] == 'K' && (keycode == W || keycode == UP)) ||
		(data->map[y][x - 1] == 'K' && (keycode == A || keycode == LEFT)) ||
		(data->map[y][x + 1] == 'K' && (keycode == D || keycode == RIGHT)) ||
		data->farmer_win == 1)
	{
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win,
			data->mlx->img[19], data->p_x * 64, data->p_y * 64);
		closegame(data, 18, "LOSE");
		return (1);
	}
	return (0);
}

void	ft_init_image(t_mlx *mlx, int r)
{
	mlx->img[0] = mlx_xpm_file_to_image(mlx->mlx, "images/sol.xpm", &r, &r);
	mlx->img[1] = mlx_xpm_file_to_image(mlx->mlx, "images/caillou.xpm", &r, &r);
	mlx->img[2] = mlx_xpm_file_to_image(mlx->mlx, "images/taureau.xpm", &r, &r);
	mlx->img[3] = mlx_xpm_file_to_image(mlx->mlx, "images/farmer.xpm", &r, &r);
	mlx->img[4] = mlx_xpm_file_to_image(mlx->mlx, "images/herbe.xpm", &r, &r);
	mlx->img[5] = mlx_xpm_file_to_image(mlx->mlx, "images/vache.xpm", &r, &r);
	mlx->img[6] = mlx_xpm_file_to_image(mlx->mlx, "images/logo_1.xpm", &r, &r);
	mlx->img[7] = mlx_xpm_file_to_image(mlx->mlx, "images/logo_2.xpm", &r, &r);
	mlx->img[8] = mlx_xpm_file_to_image(mlx->mlx, "images/logo_3.xpm", &r, &r);
	mlx->img[9] = mlx_xpm_file_to_image(mlx->mlx, "images/logo_4.xpm", &r, &r);
	mlx->img[10] = mlx_xpm_file_to_image(mlx->mlx, "images/miam.xpm", &r, &r);
	mlx->img[11] = mlx_xpm_file_to_image(mlx->mlx, "images/herbe2.xpm", &r, &r);
	mlx->img[12] = mlx_xpm_file_to_image(mlx->mlx, "images/herbe3.xpm", &r, &r);
	mlx->img[13] = mlx_xpm_file_to_image(mlx->mlx, "images/fleur2.xpm", &r, &r);
	mlx->img[14] = mlx_xpm_file_to_image(mlx->mlx, "images/fleur2.xpm", &r, &r);
	mlx->img[15] = mlx_xpm_file_to_image(mlx->mlx, "images/win.xpm", &r, &r);
	mlx->img[16] = mlx_xpm_file_to_image(mlx->mlx, "images/cow_l.xpm", &r, &r);
	mlx->img[17] = mlx_xpm_file_to_image(mlx->mlx, "images/coeur.xpm", &r, &r);
	mlx->img[18] = mlx_xpm_file_to_image(mlx->mlx, "images/lose.xpm", &r, &r);
	mlx->img[19] = mlx_xpm_file_to_image(mlx->mlx, "images/dead.xpm", &r, &r);
	mlx->img[20] = mlx_xpm_file_to_image(mlx->mlx, "images/farmup.xpm", &r, &r);
	mlx->img[21] = mlx_xpm_file_to_image(mlx->mlx, "images/farm_d.xpm", &r, &r);
	mlx->img[22] = mlx_xpm_file_to_image(mlx->mlx, "images/farm_l.xpm", &r, &r);
	mlx->img[23] = mlx_xpm_file_to_image(mlx->mlx, "images/farm_r.xpm", &r, &r);
}

void	ft_start(t_data *data, t_mlx *mlx)
{
	int	r;

	r = 0;
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, data->l * 64, (data->h + 4) * 64,
			"GAME");
	ft_init_image(mlx, r);
	mlx->nb[0] = mlx_xpm_file_to_image(mlx->mlx, "images/0.xpm", &r, &r);
	mlx->nb[1] = mlx_xpm_file_to_image(mlx->mlx, "images/1.xpm", &r, &r);
	mlx->nb[2] = mlx_xpm_file_to_image(mlx->mlx, "images/2.xpm", &r, &r);
	mlx->nb[3] = mlx_xpm_file_to_image(mlx->mlx, "images/3.xpm", &r, &r);
	mlx->nb[4] = mlx_xpm_file_to_image(mlx->mlx, "images/4.xpm", &r, &r);
	mlx->nb[5] = mlx_xpm_file_to_image(mlx->mlx, "images/5.xpm", &r, &r);
	mlx->nb[6] = mlx_xpm_file_to_image(mlx->mlx, "images/6.xpm", &r, &r);
	mlx->nb[7] = mlx_xpm_file_to_image(mlx->mlx, "images/7.xpm", &r, &r);
	mlx->nb[8] = mlx_xpm_file_to_image(mlx->mlx, "images/8.xpm", &r, &r);
	mlx->nb[9] = mlx_xpm_file_to_image(mlx->mlx, "images/9.xpm", &r, &r);
	putimage(data, mlx);
	putlogo(data, data->mlx);
	mlx_hook(mlx->win, 17, 0, &ft_close, data);
	mlx_key_hook(mlx->win, &key_hook, data);
	mlx_loop(mlx->mlx);
	ft_closewin(data);
}

void	ft_mlx(t_data *data, t_mlx *mlx)
{
	data->farmer_img = 0;
	data->profil = 0;
	data->isgameon = 0;
	data->farmer_win = 0;
	data->win = 0;
	data->lose = 0;
	if (ft_intro(data))
	{
		ft_freetab(data->map);
		exit(1);
	}
	ft_start(data, mlx);
}
