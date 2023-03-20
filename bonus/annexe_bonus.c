/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annexe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheraul <maheraul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 04:33:34 by maheraul          #+#    #+#             */
/*   Updated: 2023/02/02 17:39:56 by maheraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_putn(int n, t_data *data)
{
	if (n > 9999)
		data->mv = 0;
	if (n <= 9999)
	{
		data->n1 = n % 10;
		n = n / 10;
		data->n2 = n % 10;
		n = n / 10;
		data->n3 = n % 10;
		n = n / 10;
		data->n4 = n % 10;
	}
}

int	space_eat(t_data *data, char c, char f, int space)
{
	(void)space;
	if (data->map[data->p_y + 1][data->p_x] == c)
		data->map[data->p_y + 1][data->p_x] = f;
	else if (data->map[data->p_y - 1][data->p_x] == c)
		data->map[data->p_y - 1][data->p_x] = f;
	else if (data->map[data->p_y][data->p_x + 1] == c)
		data->map[data->p_y][data->p_x + 1] = f;
	else if (data->map[data->p_y][data->p_x - 1] == c)
		data->map[data->p_y][data->p_x - 1] = f;
	else
		return (0);
	return (1);
}

void	ft_printtab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		printf("%s\n", tab[i++]);
}
