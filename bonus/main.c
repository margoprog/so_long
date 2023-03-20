/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheraul <maheraul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 03:40:09 by maheraul          #+#    #+#             */
/*   Updated: 2023/01/31 22:43:21 by maheraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**readmap(char *name)
{
	int		fd;
	char	*line;
	char	*buff;
	char	**tab;

	fd = open(name, O_RDONLY);
	line = get_next_line(fd, 0);
	buff = NULL;
	while (line)
	{
		buff = ft_realloc(buff, line);
		free(line);
		line = get_next_line(fd, 0);
	}
	free(line);
	if (!buff)
		return (ft_error(1), NULL);
	close(fd);
	tab = ft_split(buff, '\n');
	if (!tab)
		return (ft_error(2), free(buff), NULL);
	free(buff);
	return (tab);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_data	data;
	t_mlx	mlx;

	data.mlx = &mlx;
	data.map = NULL;
	if (argc != 2)
		return (ft_error(1));
	if (ft_no_ber(argv[1]))
		return (ft_error(2));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_error(3));
	if (ft_parse_map(fd, argv[1], &data))
		exit(1);
	if (data.map)
		ft_freetab(data.map);
	data.map = readmap(argv[1]);
	farmer_libre(&data);
	ft_mlx(&data, &mlx);
	return (0);
}
