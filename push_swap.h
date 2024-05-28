/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: porellan <porellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:43:33 by porellan          #+#    #+#             */
/*   Updated: 2024/05/28 13:04:30 by porellan         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include "Libft/Printf/ft_printf.h"

void    arg_parse(int a);
void    symbols_parse(int s, int p, int n);
long	ft_atol(const char *str);
void    swap(t_list **lst);
void    sa_swap_a(t_list **lst);
void    sb_swap_b(t_list **lst);
void    ss_swap(t_list **lst);
void    pa_push_a(t_list **lst1, t_list **lst2);
void    pb_push_b(t_list **lst1, t_list **lst2);
void    ra_rotate_a(t_list **lst);
void    printList(t_list* head);
//void     same_number(    );

#endif