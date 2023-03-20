/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 23:28:20 by maheraul          #+#    #+#             */
/*   Updated: 2022/12/18 01:20:25 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

size_t	ft_2strlen(const char *str);
int		ft_2strchr(char const *str, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*gnl_struct(int fd, char *buf);
char	*get_next_line(int fd);
void	freejoin(char **new, char *buf);
void	ft_reset(char *buff);

#endif
