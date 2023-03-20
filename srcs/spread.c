/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheraul <maheraul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 03:42:58 by maheraul          #+#    #+#             */
/*   Updated: 2023/02/01 02:08:31 by maheraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_spread_x(char **map, int y, int x)
{
	if (map[y][x] == '0' || map[y][x] == 'C')
	{
		map[y][x] = 'X';
		ft_spread2(map, y, x);
	}
}

void	ft_spread2(char **map, int y, int x)
{
	int	px;
	int	py;

	px = x;
	py = y;
	x = px - 1;
	ft_spread_x(map, y, x);
	x = px + 1;
	ft_spread_x(map, y, x);
	x = px;
	y = py - 1;
	ft_spread_x(map, y, x);
	y = py + 1;
	ft_spread_x(map, y, x);
}

void	data_ep(t_data *data, int x, int y, int n)
{
	if (n == 0)
	{
		data->e_x = x;
		data->e_y = y;
	}
	else
	{
		data->p_x = x;
		data->p_y = y;
	}
}

int	ft_spread(char **map, t_data *data)
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
			if (map[y][x] == 'E')
				data_ep(data, x, y, 0);
			if (map[y][x] == 'P')
			{
				data_ep(data, x, y, 1);
				ft_spread2(map, y, x);
				break ;
			}
			x++;
		}
		y++;
	}
	if (ft_exit_access(map) || !ft_all_c_access(map))
		return (1);
	return (0);
}

char	**ft_all_c_access(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (cc_tichar(map[i], 'C'))
			return (NULL);
		i++;
	}
	return (map);
}
