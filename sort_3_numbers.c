/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: porellan <porellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:34:16 by porellan          #+#    #+#             */
/*   Updated: 2024/10/15 17:49:43 by porellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int lst_compare(t_list **lst, long *sorted_array)
// {
//     t_list  *current;
//     int     i;
    
//     current = *lst;
//     i = 0;
//     while(current && current->content != NULL)
//     {
//         if ((long int)current->content != sorted_array[i])
//             return (1);
//         current = current->next;
//         i++;
//     }
//     return (0);
// }

static int    stack_compare(t_list **lst)
{
    t_list  *temp;
    t_list  *comp;

    temp = *lst;
    while(temp)
    {
        comp = temp->next;
        while(comp)
        {
            if(((long int)temp->content) > ((long int)comp->content))
            {
                ft_printf("Des");
                return (1);
            }
            comp = comp->next;
        }
        temp = temp->next;
    }
    return (0);
}

void    sort_3_num(t_list **a, int *sorted_array)
{
    t_list  *actual;
    long    f;
    long    s;
    long    t;

    actual = *a;
    f = (long int)actual->content;
    s = (long int)actual->next->content;
    t = (long int)actual->next->next->content;
    if (stack_compare(a) == 0)
        return;
    if (f < s)
        rra_reverse_rotate_a(a);
    else if (f > s)
        sa_swap_a(a);
    else if (f > s && t > s)
    {
        ra_rotate_a(a);
        return ;
    }
    sort_3_num(a, sorted_array);
}

// void    sort_5_num(t_list **a, t_list **b, long *sorted_array)
// {
//     t_list  *actual;
//     int i;

//     actual = *a;
//     i = 0;
//     while (i < 2)
//     {
//         if (actual->content == sorted_array[i])
//             pb_push_b(b, a);
//         actual = actual->next;
//         i++;
//     }
//     sort_3_num(a, sorted_array);
// }





/*
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1



*/