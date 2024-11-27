/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: porellan <porellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:43:33 by porellan          #+#    #+#             */
/*   Updated: 2024/11/27 10:12:47 by porellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include "Libft/Printf/ft_printf.h"

void	parse(char **argv, int argc);
void	arg_parse(int argc);
void	symbols_parse(char **argv, int argc);
void	num_limits_parse(char **argv, int argc);
void	same_number_parse(t_list **lst);
void	sort(t_list **a, t_list **b);
t_list	*lst_maker(char **argv, int argc);
int		*create_array(t_list **lst, int array_size);
void	sorted_array(int *array, int first_elem, int last_elem);
void	sort_small(t_list **a, t_list **b, int *array);
void	sort_big(t_list **a, t_list **b, int *array, int array_size);
void	free_split(char **s);
int		clear_lst(t_list *lst);
long	ft_atol(const char *str);
void	swap(t_list **lst);
void	sa_swap_a(t_list **a);
void	sb_swap_b(t_list **b);
void	ss_swap(t_list **a, t_list **b);
void	push(t_list **lst1, t_list **lst2);
void	pa_push_a(t_list **a, t_list **b);
void	pb_push_b(t_list **b, t_list **a);
void	rotate(t_list **lst);
void	ra_rotate_a(t_list **a);
void	rb_rotate_b(t_list **b);
void	rr_rotate(t_list **a, t_list **b);
void	reverse_rotate(t_list **lst);
void	rra_reverse_rotate_a(t_list **a);
void	rrb_reverse_rotate_b(t_list **b);
void	rrr_reverse_rotate(t_list **a, t_list **b);

#endif