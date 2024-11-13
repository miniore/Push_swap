/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: porellan <porellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:59:18 by porellan          #+#    #+#             */
/*   Updated: 2024/11/13 13:49:20 by porellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_list **a, t_list **b, int argc)
{
	int	*array;
	int	array_size;

	array_size = ft_lstsize(*a);
	array = create_array(a, array_size);
	sorted_array(array, 0, array_size - 1);
	if (argc < 20)
		sort_small(a, b, array);
	else if (argc >= 20)
		sort_big(a, b, array, array_size);
	free(array);
}
