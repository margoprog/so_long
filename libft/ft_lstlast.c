/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheraul <maheraul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:47:40 by maheraul          #+#    #+#             */
/*   Updated: 2022/11/21 03:11:11 by maheraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int		i;
	int		size;
	t_list	*temp;

	i = 0;
	if (!lst)
		return (lst);
	else
	{
		temp = lst;
		size = ft_lstsize(lst);
		while (i < size - 1)
		{
			temp = temp->next;
			i++;
		}
		return (temp);
	}
}
