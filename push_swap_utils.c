/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: porellan <porellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:09:59 by porellan          #+#    #+#             */
/*   Updated: 2024/10/30 18:22:05 by porellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void    stack_adder(char **result, t_list *lst)
// {
//     int     *number;
//     //t_list  *temp;
//     int     i;
    
//     i = 0;
//     //ft_printf("%s\n", result[i]);
//     while (result[i])
//     {
//         number = (int *)malloc(sizeof(int));
//         if (!number)
//             return;
//         *number = ft_atoi(result[i]);
//         //ft_printf("Number:%i",number[i]);
//         //temp = ft_lstnew(number);
//         //ft_printf("Temp:%d\n", *(int *)temp->content);
//         ft_lstadd_back(&lst, ft_lstnew(number));
//         printf("Temp:%d\n", *(int *)lst->content);
//         i++;
//     }
// }

// t_list    *stack_maker(char **argv)
// {
//     t_list  *lst;
//     char    **result;
//     int     i;
    
//     i = 1;
//     lst = 0;
//     while (argv[i])
//     {
//         result = ft_split(argv[i], 32);
//         ft_printf("%s\n", result[i - 1]);
//         stack_adder(result, lst);
//         i++;
//     }
//     return (lst);
// }


t_list  *lst_maker(char **argv, int argc)
{
    int     *number;
    t_list  *lst;
    char    **result;
    int     i;
    int     j;


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
    }
    return (lst);
}

int   *create_array(t_list **lst)
{
    t_list  *current;
    int     *array;
    int     array_size;
    int     i;

    current = *lst;
    array_size = ft_lstsize(*lst);
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

void    sorted_array(int *array, int first_elem, int last_elem)
{
    int i = first_elem;
    int j = last_elem;
    int pivote;
    int x;

    pivote = array[(first_elem + last_elem) / 2];
    while (i <= j)
    {
        while (array[i] < pivote && i < last_elem)
            i++;
        while (array[j] > pivote && j > first_elem)
            j--;
        if (i <= j)
        {
            x = array[i];
            array[i] = array[j];
            array[j] = x;
            i++;
            j--;
        }
    }
    if (first_elem < j)
        sorted_array(array, first_elem, j);
    if (i < last_elem)
        sorted_array(array, i, last_elem);
}

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

void printList(t_list *head) 
{
    // t_list *current = head;
    // int* data = (int*)(head);
    // int size = ft_lstsize(current);
    // //ft_printf("%i\n", size);
    // while (size--) {
    //     printf(" %d\n", *data);
    //     current = current->next;
    // }

    printf("==========STACK_A==========\n");
    while (head)
    {
        printf(" %d\n", *(int *)(head->content));
        head = head->next;
    }
    printf("============================\n");
    


}
