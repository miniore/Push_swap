/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: porellan <porellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:00:27 by porellan          #+#    #+#             */
/*   Updated: 2024/11/21 11:41:17 by porellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_nums_in_array(int *array, int i, int j)
{
	int	x;

	x = array[i];
	array[i] = array[j];
	array[j] = x;
}

void	sorted_array(int *array, int first_elem, int last_elem)
{
	int	i;
	int	j;
	int	pivote;

	i = first_elem;
	j = last_elem;
	pivote = array[(first_elem + last_elem) / 2];
	while (i <= j)
	{
		while (array[i] < pivote && i < last_elem)
			i++;
		while (array[j] > pivote && j > first_elem)
			j--;
		if (i <= j)
		{
			sort_nums_in_array(array, i, j);
			i++;
			j--;
		}
	}
	if (first_elem < j)
		sorted_array(array, first_elem, j);
	if (i < last_elem)
		sorted_array(array, i, last_elem);
}

int	*create_array(t_list **lst, int array_size)
{
	t_list	*current;
	int		*array;
	int		i;

	current = *lst;
	array = (int *)malloc(array_size * sizeof(int));
	if (!array)
		return (0);
	i = 0;
	while (array_size--)
	{
		array[i] = *(int *)current->content;
		current = current->next;
		i++;
	}
	return (array);
}

t_list	*lst_maker(char **argv, int argc)
{
	int		*number;
	t_list	*lst;
	char	**result;
	int		i;
	int		j;

	lst = NULL;
	j = 1;
	while (j < argc)
	{
		result = ft_split(argv[j], 32);
		i = 0;
		while (result[i])
		{
			number = (int *)malloc(sizeof(int));
			if (!number)
				return (0);
			*number = ft_atoi(result[i]);
			ft_lstadd_back(&lst, ft_lstnew(number));
			i++;
		}
		j++;
		free_split(result);
	}
	return (lst);
}
