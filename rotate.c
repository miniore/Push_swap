/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: porellan <porellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:54:49 by porellan          #+#    #+#             */
/*   Updated: 2024/05/28 14:25:28 by porellan         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

void    ra_rotate_a(t_list **lst)
{
    t_list    *tmp;
    t_list  *start;

    tmp = (*lst);
    start = (*lst)->next;
    while ((*lst) != NULL)
        (*lst) = (*lst)->next;
    tmp->next = NULL;
    (*lst) = tmp;
    (*lst) = start;
    //printf("%ld\n", (*lst)->next->content);
    // tmp->next = NULL;
    // ft_lstadd_back(lst, tmp);
    // while ()
    // {
    //     (*lst) = (*lst)->next;
    // }
}
