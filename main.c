/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: porellan <porellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:51:37 by porellan          #+#    #+#             */
/*   Updated: 2024/10/30 20:00:04 by porellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// // Función para liberar la memoria de la liarray, 0, array_size - 1
//     Node* nextNode;
//     while (current != NULL) {
//         nextNode = current->next;
//         free(current);
//         current = nextNode;
//     }
// }


void    lst_sort(t_list **a, t_list **b, int *array, int i)
{
    t_list  *actual;
    int     j;

    if (ft_lstsize(*a) == 3 || stack_ordered(a) == 0)
        return ;
    actual = *a;
    j = 0;
    while (array[i] != *(int *)actual->content)
    {
        j++;
        actual = actual->next;
    }
    if (j < ft_lstsize(*a)/2) //Si está en una posición por encima de la mitad
    {
        while (j--)
            rra_reverse_rotate_a(a);
        pb_push_b(b, a);
    }
    else
    {
        while (j--)
            ra_rotate_a(a);
        pb_push_b(b, a);
    }
    lst_sort(a, b, array, i++);
}

void    sort_small(t_list **a, t_list **b, int *array)
{
    if (stack_ordered(a) == 0)
        return ;
    if (ft_lstsize(*a) <= 2)
    {
        if (ft_lstsize(*a) == 1)
            return ;
        sa_swap_a(a);
        return ;
    }
    lst_sort(a, b, array, 0);
    if (ft_lstsize(*a) == 3)
    {
        sort_3_num(a, array);
        return ;
    }
}

void    sort(t_list **a, t_list **b, int argc)
{
    int    *array;
    int     array_size;

    array = create_array(a);
    array_size = ft_lstsize(*a);
    sorted_array(array, 0, array_size - 1);
    print_array(array, array_size);
    if (argc < 101)
        sort_small(a, b, array);
    free(array);
}

int main(int argc, char **argv)
{
    t_list *a;
    t_list *b = NULL;

    parse(argv, argc);
    //a = stack_maker(argv);
    a = lst_maker(argv, argc);
    same_number_parse(&a);
    printList(a);
    //sort_3_num(&a, array);
    sort(&a, &b, argc);
    printList(a);
    printList(b);

    return (0);
}
