/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: porellan <porellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:51:37 by porellan          #+#    #+#             */
/*   Updated: 2024/11/06 16:54:56 by porellan         ###   ########.fr       */
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

void     set_num_at_top(t_list **a, int chunk_size, int travelled_chunk_size, int counter)
{
    if (counter < (travelled_chunk_size - (chunk_size/2)) && counter) //Si está en una posición por encima de la mitad (menos de la mitad)
    {
        while (counter--)
            ra_rotate_a(a);
    }
    else // si j  es mayor que la mitad
    {
        while (counter < chunk_size--)
            rra_reverse_rotate_a(a);
    }
}

void    search_num(int *array, int chunk_size, int travelled_chunk_size)
{
    int     max_num_on_chunk;
    int     i;
    
    max_num_on_chunk = array[travelled_chunk_size];
    while (i <= chunk_size)
    {
        if (max_num_on_chunk < array[i])
            max_num_on_chunk = array[i];
        i++;
    }
}

int     search_num_on_chunk(t_list **a, t_list **b, int *array, int chunk_size)
{
    t_list  *temp;
    int     i;
    int     counter;

    temp = *a;
    while (temp->content != NULL)
    {
        counter = 0;
        i = 0;
        while (counter <= chunk_size)
        {
            if (array[i] == *(int *)temp->content)    //Cuando un numero sea menor o igual que el maximo de ese chunk
            {
                set_num_at_top(a, chunk_size, counter, );       // Check position
                pb_push_b(b, a);
                // Funcion de ordenar en b
                counter++;
            }
            i++;
        }
    }
    return (0);
}

void    sort_big(t_list **a, t_list **b, int *array, int array_size)
{
    t_list          *temp;
    int             chunk_size;
    static int      travelled_chunk_size;
    int             counter;

    chunk_size = array_size/5;
    travelled_chunk_size = 0;
    counter = 0;
    temp = *a;
    while (search_num_on_chunk(a, b, array, chunk_size) == 1)
    {
        counter++;
        temp = temp->next;
    }
    while ()
    {
        //Funcion de pasar numeros a stack a ordenados
    }
    travelled_chunk_size = travelled_chunk_size + chunk_size;
}

void    sort(t_list **a, t_list **b, int argc)
{
    int    *array;
    int     array_size;

    array = create_array(a);
    array_size = ft_lstsize(*a);
    sorted_array(array, 0, array_size - 1);
    print_array(array, array_size);
    if (argc < 100)
        sort_small(a, b, array);
    // else if (argc >= 100)
    //     sort_big(a, b, array, array_size);
    free(array);
}

int main(int argc, char **argv)
{
    t_list *a;
    t_list *b = NULL;

    parse(argv, argc);
    a = lst_maker(argv, argc);     //Liberar las dos variables de esta funcion
    same_number_parse(&a);
    printList(a, b);
    sort(&a, &b, argc);
    printList(a, b);
    return (0);
}


// 1 2 3 4 5 6 7 8 9