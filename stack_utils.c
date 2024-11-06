/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: porellan <porellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:00:27 by porellan          #+#    #+#             */
/*   Updated: 2024/11/02 17:02:28 by porellan         ###   ########.fr       */
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