/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: porellan <porellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:27:19 by porellan          #+#    #+#             */
/*   Updated: 2024/05/30 13:05:12 by porellan         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

void    push(t_list **lst1, t_list **lst2)
{
    t_list *tmp;
    
    if (!lst2)
        return ;
    tmp = *lst2;
    *lst2 = (*lst2)->next;
    tmp->next = *lst1;
    *lst1 = tmp;
}

void    pa_push_a(t_list **a, t_list **b)
{
    push(a, b);
    write(1, "pa\n", 3);
}

void    pb_push_b(t_list **b, t_list **a)
{
    push(b, a);
    write(1, "pb\n", 3);
}
