/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sl2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheraul <maheraul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 03:38:16 by maheraul          #+#    #+#             */
/*   Updated: 2023/02/02 18:23:00 by maheraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	create_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return (EXIT_FAILURE);
	return (0);
}

char	*ft_realloc(char *s1, char const *s2)
{
	char	*new;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (new == NULL)
		return (NULL);
	while (s1[i])
		new[j++] = s1[i++];
	i = 0;
	while (s2[i])
		new[j++] = s2[i++];
	new[j] = '\0';
	free(s1);
	return (new);
}

char	**ft_bourrin(int fd, char *argv, t_data *data)
{
	char	*line;
	char	*beurk;

	close(fd);
	fd = open(argv, O_RDONLY);
	line = get_next_line(fd, 0);
	beurk = NULL;
	while (line)
	{
		beurk = ft_realloc(beurk, line);
		free(line);
		line = get_next_line(fd, 0);
	}
	free(line);
	close(fd);
	return (ft_bourrin2(data, beurk));
}

char	**ft_bourrin2(t_data *data, char *beurk)
{
	char	**map;

	if (ft_epc(beurk, 'E', data) || ft_epc(beurk,
			'P', data) || ft_epc(beurk, 'C', data))
	{
		free(beurk);
		return (NULL);
	}
	map = ft_split(beurk, '\n');
	free(beurk);
	if (ft_spread(map, data))
	{
		ft_freetab(map);
		printf("Error\n collectible ou sortie innaccessible\n");
		exit(EXIT_FAILURE);
		return (NULL);
	}
	return (map);
}
