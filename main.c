/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: porellan <porellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:51:37 by porellan          #+#    #+#             */
/*   Updated: 2024/11/11 20:02:22 by porellan         ###   ########.fr       */
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


// int    search_num(int *array, int chunk_size, int travelled_chunk_size)
// {
//     int     max_num_on_chunk;
//     int     i;
    
//     max_num_on_chunk = array[travelled_chunk_size];
//     while (i <= chunk_size)
//     {
//         if (max_num_on_chunk < array[i])
//             max_num_on_chunk = array[i];
//         i++;
//     }
//     return (max_num_on_chunk);
// }

// int     search_num_on_chunk(t_list **a, t_list **b, int *array, int chunk_size)
// {
//     t_list  *temp;
//     int     i;
//     int     counter;

//     temp = *a;
//     while (temp->content != NULL)
//     {
//         counter = 0;
//         i = 0;
//         while (counter <= chunk_size)
//         {
//             if (array[i] == *(int *)temp->content)    //Cuando un numero sea menor o igual que el maximo de ese chunk
//             {
//                 set_num_at_top(a, chunk_size, counter, );       // Check position
//                 pb_push_b(b, a);
//                 // Funcion de ordenar en b
//                 counter++;
//             }
//             i++;
//         }
//     }
//     return (0);
// }

// void    sort_big(t_list **a, t_list **b, int *array, int array_size)
// {
//     t_list          *temp;
//     int             chunk_size;
//     static int      travelled_chunk_size;
//     int             counter;

//     chunk_size = array_size/5;
//     travelled_chunk_size = 0;
//     counter = 0;
//     temp = *a;
//     while (search_num_on_chunk(a, b, array, chunk_size) == 1)
//     {
//         counter++;
//         temp = temp->next;
//     }
//     while ()
//     {
//         //Funcion de pasar numeros a stack a ordenados
//     }
//     travelled_chunk_size = travelled_chunk_size + chunk_size;
// }

// Buscar el numero maximo de cada chunk
// encontrar un numero que pertennezca a ese chunk (menor que el mayor)
// Pasar ese numero a b
// Repetir los ultimos dos pasos hasta pasar todos los numeros del chunk  (comprobar si has pasado un total de numeros igua que el chunk size)

void    back_to_stack_a(t_list **a, t_list **b, int *array, int array_size)
{
    t_list  *temp;
    int     position;
    int     lst_size;

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
    //ft_printf("Position b: %i\n", position);
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
        
        // if (*(int *)temp->content == array[array_size])
        // {
        //     pa_push_a(a, b);  
        //     array_size--;
        // }
        // if (*(int *)temp->content < *(int *)temp->next->content)
        //     sb_swap_b(b);
        // rrb_reverse_rotate_b(b);
    pa_push_a(a, b);
    //printList(*a, *b);
    back_to_stack_a(a, b, array, --array_size);
}

int search_position(t_list **a, int *array, int chunk_size)
{
    t_list  *temp;
    int     position;
    
    temp = *a;
    position = 0;
    //ft_printf("Buscar numero menor que: %i\n", array[chunk_size]);
    while (*(int *)temp->content > array[chunk_size])
    {
        position++;
        temp = temp->next;
    }
    return(position);
}

void     set_to_push(t_list **a, t_list **b, int position, int med)
{
    t_list  *temp;
    int lst_size;
    
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
    //printList(*a, *b);
}

void    sort_big(t_list **a, t_list **b, int *array, int array_size)
{
    int chunk_size;
    int max_chunk_size;
    int position;
    int med;
    int i;

    chunk_size = array_size/5;
    max_chunk_size = chunk_size - 1;
    //ft_printf("Size del array: %i\n", array_size);
    while (ft_lstsize(*a) > 0 && a)
    {
        i = array_size/5;
        ft_printf("Size del chunk: %i\n", chunk_size);
        med = array[max_chunk_size - (chunk_size / 2)]; // Por que no sale la media?
        ft_printf("Valor de la media: %i\n", med);
        while (ft_lstsize(*a) > 0 && i--)
        {
            position = search_position(a, array, max_chunk_size - 1); //Mover a set to push
            //ft_printf("Posicion del numero: %i\n", position);
            set_to_push(a, b, position, med);
        }
        if (ft_lstsize(*a) < chunk_size)
            chunk_size = ft_lstsize(*a);
        //ft_printf("Valor de i: %i\n", i);
        max_chunk_size = max_chunk_size + chunk_size;
        //ft_printf("Size del chunk  - 1max: %i\n", max_chunk_size);
    }
    back_to_stack_a(a, b, array, array_size - 1);
}

void    sort(t_list **a, t_list **b, int argc)
{
    int    *array;
    int     array_size;

    array = create_array(a);
    array_size = ft_lstsize(*a);
    sorted_array(array, 0, array_size - 1);
    if (argc < 20)
        sort_small(a, b, array);
    else if (argc >= 20)
        sort_big(a, b, array, array_size);
    free(array);
}
 - 1
int main(int argc, char **argv)
{
    t_list *a;
    t_list *b = NULL;

    parse(argv, argc);
    a = lst_maker(argv, argc);     // - 1Liberar las dos variables de esta funcion
    same_number_parse(&a);
    sort(&a, &b, argc);
    return (0);
}
