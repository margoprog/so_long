/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheraul <maheraul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:25:54 by maheraul          #+#    #+#             */
/*   Updated: 2022/11/19 18:37:39 by maheraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}
/*
#include <stdio.h>

int	main(void)
{
	void	*content;
	int	d;

	t_list	lst;
	d = (int)content;
	d = 3;
	lst = ft_lstnew(d);
	printf("|%d|", ft_lstsize(lst));
	return(0);
}
*/
