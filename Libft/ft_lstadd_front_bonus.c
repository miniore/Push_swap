/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: porellan <porellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:39:57 by porellan          #+#    #+#             */
/*   Updated: 2024/05/28 12:37:08 by porellan         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

void	ft_lstadd_front(t_list **lst, void *new)
{
	t_list *newNode;
	newNode = ft_lstnew(new);
	newNode -> next = *lst;
	*lst = newNode;
}
