/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_access.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheraul <maheraul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 02:07:59 by maheraul          #+#    #+#             */
/*   Updated: 2023/02/01 02:15:10 by maheraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_exit_access(char **map)
{
	int	x;
	int	y;

	y = -1;
	x = 0;
	while (map[++y])
	{
		x = 0;
		while (map[y][x++])
		{
			if (map[y][x] == 'E')
				if (map[y - 1][x] == 'X' || map[y + 1][x] == 'X' ||
					map[y][x - 1] == 'X' || map[y][x + 1] == 'X')
					return (0);
		}
	}
	return (1);
}
