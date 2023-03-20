/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheraul <maheraul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 23:41:04 by maheraul          #+#    #+#             */
/*   Updated: 2022/11/21 03:09:31 by maheraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst)
		new->next = NULL;
	else
	{
		new->next = *lst;
		*lst = new;
	}
}
/*
int	main(void)
{
	t_list	*list1;
	t_list	*list2;

	list1 = ft_lstnew("jean luc lemoine");
	list2 = ft_lstnew("grosse tete");
	ft_lstadd_front(list1, list2);
}
*/
