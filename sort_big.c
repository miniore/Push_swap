/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: porellan <porellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:55:25 by porellan          #+#    #+#             */
/*   Updated: 2024/11/13 13:41:48 by porellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	back_to_stack_a(t_list **a, t_list **b, int *array, int array_size)
{
	t_list	*temp;
	int		position;
	int		lst_size;

	temp = *b;
	lst_size = ft_lstsize(*b);
	position = 0;
	if (lst_size == 0)
		return ;
	while (temp && array[array_size] != *(int *)temp->content)
	{
		position++;
		temp = temp->next;
	}
	if (position < lst_size/2) //Si está en una posición por encima de la mitad (menos de la mitad)
	{
		while (position--)
			rb_rotate_b(b);
	}
	else // si j  es mayor que la mitad
	{
		while (position < lst_size--)
			rrb_reverse_rotate_b(b);
	}
	pa_push_a(a, b);
}

static int	search_position(t_list **a, int *array, int chunk_size)
{
	t_list	*temp;
	int		position;

	temp = *a;
	position = 0;
	while (*(int *)temp->content > array[chunk_size])
	{
    	position++;
    	temp = temp->next;
	}
	return (position);
}

static void	set_to_push(t_list **a, t_list **b, int position, int med)
{
	t_list	*temp;
	int		lst_size;

	lst_size = ft_lstsize(*a);
	if (position < lst_size/2) //Si está en una posición por encima de la mitad (menos de la mitad)
	{
		while (position--)
			ra_rotate_a(a);
	}
	else // si j  es mayor que la mitad
	{
		while (lst_size > 1 && position < lst_size--)
			rra_reverse_rotate_a(a);
	}
	pb_push_b(b, a); //Despues de hacer pb si el numero es menor que la media lo bajas abajo
	temp = *b;
	if (ft_lstsize(*b) > 1 && *(int *)temp->content <= med)
		rb_rotate_b(b);
}

void	sort_big(t_list **a, t_list **b, int *array, int array_size)
{
	int	chunk_size;
	int	max_chunk_size;
	int	position;
	int	med;
	int	i;

	chunk_size = array_size / 5;
	max_chunk_size = chunk_size - 1;
	while (ft_lstsize(*a) > 0 && a)
	{
		i = array_size / 5;
		med = array[max_chunk_size - (chunk_size / 2)];
		while (ft_lstsize(*a) > 0 && i--)
		{
			position = search_position(a, array, max_chunk_size);
			set_to_push(a, b, position, med);
		}
		if (ft_lstsize(*a) < chunk_size)
			chunk_size = ft_lstsize(*a);
		max_chunk_size = max_chunk_size + chunk_size;
	}
	while (ft_lstsize(*b))
		back_to_stack_a(a, b, array, --array_size);
}
