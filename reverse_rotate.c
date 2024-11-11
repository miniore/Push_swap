/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: porellan <porellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:53:04 by porellan          #+#    #+#             */
/*   Updated: 2024/11/11 17:03:05 by porellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    reverse_rotate(t_list **lst)
{
    t_list  *tmp;
    t_list  *actual;
    
    tmp = NULL;
    actual = *lst;
    while (actual->next != NULL)
    {
        tmp = actual;
        actual = actual->next;
    }
    if(tmp != NULL)
        tmp->next = NULL;
    actual->next = *lst;
    *lst = actual;
}

void    rra_reverse_rotate_a(t_list **a)
{
    reverse_rotate(a);
    write(1, "rra\n", 4);
}

void    rrb_reverse_rotate_b(t_list **b)
{
    reverse_rotate(b);
    write(1, "rrb\n", 4);
}

void    rrr_reverse_rotate(t_list **a)
{
    reverse_rotate(a);
    write(1, "rra\n", 4);
}
