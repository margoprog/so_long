/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheraul <maheraul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:58:23 by maheraul          #+#    #+#             */
/*   Updated: 2023/01/14 06:38:58 by maheraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	buf[BUFFER_SIZE + 1];

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	return (gnl_struct(fd, buf));
}

// int	main(void)
// {
// 	char	*path;
// 	char	*s;
// 	int		fd;

// 	path = "test.txt";
// 	fd = open("test.txt", O_RDONLY);
// 	if (fd == -1)
// 		printf("%s", "open failed");

// 	printf("fdtest=%i\n", fd);

// 	s = get_next_line(fd);
// 	printf("\n1=%s\n", s);
// 	free(s);
// 	s = get_next_line(fd);
// 	printf("2=%s\n", s);
// 	free(s);
// 	s = get_next_line(fd);
// 	printf("3=%s\n", s);
// 	free(s);
// 	s = get_next_line(fd);
// 	printf("\n1=%s\n", s);
// 	free(s);
// 	s = get_next_line(fd);
// 	printf("2=%s\n", s);
// 	free(s);
// 	s = get_next_line(fd);
// 	printf("3=%s\n", s);
// 	free(s);
// 	s = get_next_line(fd);
// 	printf("\n1=%s\n", s);
// 	free(s);
// 	s = get_next_line(fd);
// 	printf("2=%s\n", s);
// 	free(s);
// 	s = get_next_line(fd);
// 	printf("3=%s\n", s);
// 	free(s);
// 	return (0);
// }
