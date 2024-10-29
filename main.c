/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: porellan <porellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:51:37 by porellan          #+#    #+#             */
/*   Updated: 2024/10/29 18:46:45 by porellan         ###   ########.fr       */
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


int main(int argc, char **argv)
{
    int    *array;
    int     array_size;
    t_list *a;
    //t_list *b;

    parse(argv, argc);
    //a = stack_maker(argv);
    a = lst_maker(argv, argc);
    // ft_printf("ey\n");
    // same_number_parse(&a);
    printList(a);
    array = create_array(&a);
    array_size = ft_lstsize(a);
    sorted_array(array, 0, array_size - 1);
    print_array(array, array_size);
    sort_3_num(&a, array);
    printList(a);
    return (0);
}

