/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniore <miniore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:43:33 by porellan          #+#    #+#             */
/*   Updated: 2024/05/28 10:49:29 by miniore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
void    printList(t_list* head);
//void     same_number(    );

#endif