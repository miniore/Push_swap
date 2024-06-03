/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: porellan <porellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:54:49 by porellan          #+#    #+#             */
/*   Updated: 2024/05/30 13:42:31 by porellan         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

void    rotate(t_list **lst)
{
    t_list    *tmp;
    t_list  *start;

    tmp = *lst;
    start = (*lst)->next;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = *lst;
    tmp = *lst;
    tmp->next = NULL;
    *lst = start;
}

void    ra_rotate_a(t_list **a)
{
    rotate(a);
    write(1, "ra\n", 3);
}

void    rb_rotate_b(t_list **b)
{
    rotate(b);
    write(1, "rb\n", 3);
}

void    rr_rotate(t_list **a, t_list **b)
{
    rotate(a);
    rotate(b);
    write(1, "rr\n", 3);
}
