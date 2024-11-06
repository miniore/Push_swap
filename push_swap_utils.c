/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: porellan <porellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:09:59 by porellan          #+#    #+#             */
/*   Updated: 2024/11/02 17:14:12 by porellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	long	result;
	long	sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

void    print_array(int *array, int size)
{
    int i = 0;
    while (i < size)
    {
        ft_printf("'%i'\n", array[i]);
        i++;
    }
}

void printList(t_list *a, t_list *b) 
{
    // t_list *current = head;
    // int* data = (int*)(head);
    // int size = ft_lstsize(current);
    // //ft_printf("%i\n", size);
    // while (size--) {
    //     printf(" %d\n", *data);
    //     current = current->next;
    // }
    t_list *head_a = a;
    t_list *head_b = b;


    printf("==========STACK_A==========\n");
    while (head_a)
    {
        printf(" %d\n", *(int *)(head_a->content));
        head_a = head_a->next;
    }
    printf("============================\n");
    
        printf("==========STACK_B==========\n");
    while (head_b)
    {
        printf(" %d\n", *(int *)(head_b->content));
        head_b = head_b->next;
    }
    printf("============================\n");


}
