/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: porellan <porellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:40:22 by porellan          #+#    #+#             */
/*   Updated: 2024/11/13 13:46:43 by porellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	stack_ordered(t_list **lst)
{
	t_list 	*temp;
	t_list 	*comp;

	temp = *lst;
	while (temp)
	{
		comp = temp->next;
		while (comp)
		{
			if ((*(int *)temp->content) > (*(int *)comp->content))
				return (1);
			comp = comp->next;
		}
		temp = temp->next;
	}
	return (0);
}

static void	sort_3_num(t_list **a, int *sorted_array)
{
	t_list	*actual;
	int		f;
	int		s;
	int		t;

	actual = *a;
	f = *(int *)actual->content;
	s = *(int *)actual->next->content;
	t = *(int *)actual->next->next->content;
	if (stack_ordered(a) == 0)
		return ;
	if (f < s)
		rra_reverse_rotate_a(a);
	else if (f > s)
		sa_swap_a(a);
	else if (f > s && t < s)
	{
		ra_rotate_a(a);
		return ;
	}
	sort_3_num(a, sorted_array);
}

static void	lst_sort(t_list **a, t_list **b, int *array, int i)
{
	t_list	*actual;
	int		size;
	int		counter;

    //if (ft_lstsize(*a) == 3 || stack_ordered(a) == 0)
    //    return ;
	actual = *a;
	counter = 0;
	size = ft_lstsize(*a);
	while (array[i] != *(int *)actual->content)
	{
		counter++;
		actual = actual->next;
	}
	if (counter < (size/2) && counter) //Si está en una posición por encima de la mitad (menos de la mitad)
	{
		while (counter--)
			ra_rotate_a(a);
	}
	else // si j  es mayor que la mitad
	{
		while (counter < size--)
			rra_reverse_rotate_a(a);
	}
	pb_push_b(b, a);
	//lst_sort(a, b, array, i + 1);
}

void	sort_small(t_list **a, t_list **b, int *array)
{
	int	i;

	i = 0;
	if (stack_ordered(a) == 0)
		return ;
	if (ft_lstsize(*a) <= 2)
	{
		if (ft_lstsize(*a) == 1)
			return ;
		sa_swap_a(a);
		return ;
	}
	while (ft_lstsize(*a) != 3 && stack_ordered(a) != 0)
	{
		lst_sort(a, b, array, i);
		i++;
	}
	if (ft_lstsize(*a) == 3)
		sort_3_num(a, array);
	while (ft_lstsize(*b))
		pa_push_a(a, b);
}
