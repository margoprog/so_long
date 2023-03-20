/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheraul <maheraul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 03:38:16 by maheraul          #+#    #+#             */
/*   Updated: 2023/02/02 17:58:08 by maheraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_error(int i)
{
	if (i == 1)
		ft_printf("%s", "Error\n donne juste un fichier .ber stp");
	if (i == 2)
		ft_printf("%s", "Error\njmange que du .ber please");
	if (i == 3)
		ft_printf("%s", "Error\n inaccessible");
	if (i == 4)
		ft_printf("%s", "Error\n cette map est toute PETEE");
	if (i == 5)
		ft_printf("%s", "Error\n drop juste 1 farmer -> K\n");
	if (i == 6)
		ft_printf("%s", "Error\n les murs devraient etre que des 1\n");
	if (i == 9)
		ft_printf("%s", "Error\n il est keblo mr.fermier\n");
	exit(EXIT_FAILURE);
	return (0);
}

int	ft_parse_map(int fd, char *argv, t_data *data)
{
	int		x;
	char	*line;

	line = get_next_line(fd, 0);
	if (!line)
		return (ft_error(4));
	if (ft_only_1(line))
	{
		close(fd);
		get_next_line(1, 1);
		return (free(line), ft_error(6));
	}
	x = ft_strlen(line);
	data->l = x - 1;
	ft_parse_map2(fd, argv, data, line);
	return (0);
}

int	ft_parse_map2(int fd, char *argv, t_data *data, char *line)
{
	int	y;

	y = 0;
	while (line)
	{
		free(line);
		line = get_next_line(fd, 0);
		if ((line && ft_cpe10(line) == 2))
		{
			close(fd);
			free(line);
			get_next_line(1, 1);
			return (ft_error(4));
		}
		y++;
	}
	data->h = y;
	get_next_line(1, 1);
	close(fd);
	ft_parse_map3(fd, argv, data, y);
	return (0);
}

int	ft_parse_map3(int fd, char *argv, t_data *data, int y)
{
	int		i;
	int		x;
	char	*line;

	i = 0;
	x = data->l + 1;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (ft_error(3));
	while (i != y)
	{
		line = get_next_line(fd, 0);
		if (i < y - 1 && (ft_strlen(line) != x || line[0] != '1' || line[x
					- 2] != '1'))
		{
			close(fd);
			free(line);
			get_next_line(1, 1);
			return (ft_error(4));
		}
		if (i < y - 1)
			free(line);
		i++;
	}
	return (ft_parse_map4(fd, data, argv, line));
}

int	ft_parse_map4(int fd, t_data *data, char *argv, char *line)
{
	int	x;

	x = data->l + 1;
	get_next_line(1, 1);
	close(fd);
	if (!line || ft_only_1(line) || ft_strlen(line) != x - 1)
	{
		free(line);
		return (ft_error(4));
	}
	free(line);
	data->map = ft_bourrin(fd, argv, data);
	if (!data->map)
		return (ft_error(4));
	return (0);
}
