/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniore <miniore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:48:09 by miniore           #+#    #+#             */
/*   Updated: 2024/05/28 10:50:53 by miniore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap(t_list **lst)
{
    void    *tmp;
    
    if (!*lst || !(*lst)->next)
        return
    tmp = (*lst)->content;
    (*lst)->content = (*lst)->next->content;
    (*lst)->next->content = tmp;
}

void    sa_swap_a(t_list **lst)
{
    swap(lst);
    write(1, "sa\n", 3);
}

void    sb_swap_b(t_list **lst)
{
    swap(lst);
    write(1, "sb\n", 3);
}

void    ss_swap(t_list **lst)
{
    swap(lst);
    swap(lst);
    write(1, "ss\n", 3);
}