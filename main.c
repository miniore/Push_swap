/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: porellan <porellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:51:37 by porellan          #+#    #+#             */
/*   Updated: 2024/06/20 14:17:03 by porellan         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

int main(int argc, char *argv[]){
    int     i;
    int     j;
    char    **result;
    long    *number;
    struct s_list *a = NULL;
    //struct s_list *b = ft_lstnew((long *)17);
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
        result = ft_split(argv[j], 32);
        while (*result){
            number = (long *)malloc(sizeof(long));
            if (!number)
                return (0);
            number = (long *)ft_atol(*result);
            //ft_lstnew(number);
            ft_lstadd_back(&a, ft_lstnew(number));
            same_number_parse(a);
            result++;
            //free(number);
        }
        j++;
    }
    //create_array(a);
    printList(a);
}


// long    **create_array(t_list *lst)
// {
//     t_list  *current;
//     static long    array[10];
//     int i;
//     //int j;
    
//     //j = 0;
//     current = lst;
//     array[0] = (long)current->content;
//     while (current != NULL)
//     {
//         i = 0;
//         while (current->content > array[i])
//             i++;
//         if (current->content < array[i])
//         {
//             array[i+1] = array[i];
//             array[i] = current->content;  
//         }
//         current = current->next;
//     }
// }


long    *create_array(t_list *lst)
{
    t_list  *current;
    long    *array[10];
    int     i;

    current = lst;
    while (current != NULL)
    {
        *array[i] = (long)current->content;
        ft_printf("%ld\n", array[i]);
        current = current->next;
        i++;
    }
    return (*array);
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
