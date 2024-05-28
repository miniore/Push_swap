/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: porellan <porellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:27:19 by porellan          #+#    #+#             */
/*   Updated: 2024/05/28 13:02:32 by porellan         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

void    pa_push_a(t_list **lst1, t_list **lst2)
{
    void    *tmp;
    
    if (!lst1)
        return ;
    tmp = (*lst2)->content;
    *lst2 = (*lst2)->next;
    ft_lstadd_front(lst1, tmp);
}

void    pb_push_b(t_list **lst1, t_list **lst2)
{
    void    *tmp;
    
    if (!lst2)
        return ;
    tmp = (*lst1)->content;
    *lst1 = (*lst1)->next;
    ft_lstadd_front(lst2, tmp);
}