/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: porellan <porellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:51:37 by porellan          #+#    #+#             */
/*   Updated: 2024/05/28 14:00:30 by porellan         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

int main(int argc, char *argv[]){
    int     i;
    int     j;
    char    **result;
    long    *number;
    struct s_list *a = NULL;
    //struct s_list *b = NULL;

    result = NULL;
    j = 1;
    arg_parse(argc);
    while (j < argc){
        i = 0;
        while (argv[j][i]){
            symbols_parse(argv[j][i], argv[j][i-1], argv[j][i+1]);
            i++;
        }
        //if (argv[j][0] == 34)
        result = ft_split(argv[j], 32);
        while (*result){
            //ft_printf("%s\n", *result);
            number = (long *)malloc(sizeof(long));
            if (!number)
                return (0);
            number = (long *)ft_atol(*result);
            ft_lstnew(number);
            ft_lstadd_front(&a, number);       // Llamada a funcion para añadir a lista
            //ft_printf("%d\n", number);
            result++;
            //free(number);
        }
        j++;
    }
    printList(a);
    ra_rotate_a(&a);
    printList(a);
    //printList(b);
    // same_number(argv[j][i], )
}

void printList(t_list* head) {
    t_list *current = head;
    while (current != NULL) {
        long int* data = (long int*)(current);
        printf(" %ld\n", *data);
        current = current->next;
    }
    printf("===\n a\n");
}

// // Función para liberar la memoria de la lista
// void freeList(Node* head) {
//     Node* current = head;
//     Node* nextNode;
//     while (current != NULL) {
//         nextNode = current->next;
//         free(current);
//         current = nextNode;
//     }
// }
