/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:58:23 by maheraul          #+#    #+#             */
/*   Updated: 2022/12/18 01:18:44 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_2strchr(char const *str, int c)
{
	size_t	i;
	char	ch;
	char	*s;

	ch = (char)c;
	s = (char *)str;
	i = 0;
	while (s[i])
	{
		if (s[i] == ch)
			return (1);
		i++;
	}
	return (0);
}

void	ft_reset(char *buff)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
		i++;
	while (buff[i])
		buff[j++] = buff[i++];
	buff[j] = '\0';
}

char	*gnl_struct(int fd, char *buf)
{
	int			ret;
	char		*new;

	new = NULL;
	ret = 0;
	freejoin(&new, buf);
	if (!ft_2strchr(buf, '\n'))
	ret = read(fd, buf, BUFFER_SIZE);
	if (ret == -1)
		return (NULL);
	while (ret && !ft_2strchr(buf, '\n'))
	{
		buf[ret] = '\0';
		freejoin(&new, buf);
		ret = read(fd, buf, BUFFER_SIZE);
	}
	if (ret)
	{
		buf[ret] = '\0';
		freejoin(&new, buf);
	}
	ft_reset (buf);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	buf[FOPEN_MAX][BUFFER_SIZE + 1];

	if (BUFFER_SIZE <= 0 || fd > FOPEN_MAX || fd < 0)
		return (NULL);
	return (gnl_struct(fd, buf[fd]));
}

// int	main(void)
// {
// 	char	*s;
// 	int		fd;
// 	int		fd2;

// 	fd = open("test.txt", O_RDONLY);
// 	if (fd == -1)
// 		printf("%s", "open failed");
// 	fd2 = open("test2.txt", O_RDONLY);
// 	if (fd == -1)
// 		printf("%s", "open failed");
// 	s = get_next_line(fd);
// 	printf("\n1=%s\n", s);
// 	free(s);
// 	s = get_next_line(fd2);
// 	printf("2=%s\n", s);
// 	free(s);
// 	s = get_next_line(fd);
// 	printf("3=%s\n", s);
// 	free(s);
// 	s = get_next_line(fd2);
// 	printf("4=%s\n", s);
// 	free(s);
// 	s = get_next_line(fd);
// 	printf("\n1=%s\n", s);
// 	free(s);
// 	return (0);
// }
