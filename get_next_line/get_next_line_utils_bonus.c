/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheraul <maheraul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 22:33:21 by maheraul          #+#    #+#             */
/*   Updated: 2023/01/15 23:35:28 by maheraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_2strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*new;

	i = 0;
	j = 0;
	if (s2[0] == 0)
		return (NULL);
	if (s1 == NULL)
		new = malloc(sizeof(*new) * (ft_2strlen(s2) + 1));
	else
		new = malloc(sizeof(*new) * (ft_2strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (NULL);
	while (s1 && s1[i])
		new[j++] = s1[i++];
	i = 0;
	while (s2[i] && s2[i] != '\n')
		new[j++] = s2[i++];
	if (s2[i] == '\n')
		new[j++] = '\n';
	new[j] = '\0';
	free(s1);
	return (new);
}

void	freejoin(char **new, char *buf)
{
	char	*temp;

	temp = *new;
	*new = ft_strjoin (*new, buf);
	if (temp)
		free (temp);
}
