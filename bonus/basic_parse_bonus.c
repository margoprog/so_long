/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheraul <maheraul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 03:58:07 by maheraul          #+#    #+#             */
/*   Updated: 2023/02/01 01:43:33 by maheraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_no_ber(char *fichier)
{
	char	*extens;

	extens = ft_strnstr(fichier, ".ber", ft_strlen(fichier));
	if (!extens || ft_strlen(extens) != 4)
		return (1);
	return (0);
}

int	ft_only_1(char *line)
{
	int	i;

	i = 0;
	if (line[i] != '1')
		return (1);
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_cpe10(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != 'C' && line[i] != 'P' && line[i] != 'E' && line[i] != 'K'
			&& line[i] != '1' && line[i] != '0' && line[i] != '\n')
			return (2);
		i++;
	}
	return (0);
}

int	ft_epc(char *beurk, int c, t_data *data)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (beurk[i++])
		if (beurk[i] == c)
			count++;
	if ((c == 'E' || c == 'P') && count != 1)
		return (1);
	if (c == 'C')
	{
		if (count < 1)
			return (1);
		else
			data->c = count;
	}
	if ((c == 'K' && count != 1))
	{
		free(beurk);
		return (!ft_error(5));
	}
	return (0);
}

int	cc_tichar(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}
