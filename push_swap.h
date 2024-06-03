/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: porellan <porellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:43:33 by porellan          #+#    #+#             */
/*   Updated: 2024/06/03 12:07:55 by porellan         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include "Libft/Printf/ft_printf.h"

void    arg_parse(int a);
void    symbols_parse(int s, int p, int n);
void     same_number_parse(t_list *lst);
long	ft_atol(const char *str);
void    swap(t_list **lst);
void    sa_swap_a(t_list **a);
void    sb_swap_b(t_list **b);
void    ss_swap(t_list **a, t_list **b);
void    push(t_list **lst1, t_list **lst2);
void    pa_push_a(t_list **a, t_list **b);
void    pb_push_b(t_list **b, t_list **a);
void    rotate(t_list **lst);
void    ra_rotate_a(t_list **a);
void    rb_rotate_b(t_list **b);
void    rr_rotate(t_list **a, t_list **b);
void    reverse_rotate(t_list **lst);
void    rra_reverse_rotate_a(t_list **a);
void    rrb_reverse_rotate_b(t_list **b);
void    rrr_reverse_rotate(t_list **a);
void    printList(t_list* head);

#endif