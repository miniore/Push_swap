/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniore <miniore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:57:32 by miniore           #+#    #+#             */
/*   Updated: 2024/05/24 16:54:10 by miniore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    arg_parse(int a)
{
    if (a < 2)
    {
        write(2, "Error\n", 6);
        exit(0);
    }
}

void symbols_parse(int s, int p, int n)
{
    if ((s < 48 || s > 57) && (s != 43 && s != 45) && (s != 34 && s != 32))
    {
        write(2, "Error\n", 6);
        exit(0);
    }
    if ((s == 43 || s == 45) && ((n < 48 || n > 57) || (p > 48 && p < 57)))
    {
        write(2, "Error\n", 6);
        exit(0);
    }
}

// void same_number()
// {
    
// }


// void printList(Node* head) {
//     Node* current = head;
//     while (current != NULL) {
//         printf("%d -> ", (long int*)current->data);
//         current = current->next;
//     }
//     printf("NULL\n");
// }

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

// t_list	*ft_lstnew(void *content)
// {
// 	t_list	*new;

// 	new = (t_list*)malloc(sizeof(t_list));
// 	if (!new)
// 		return (0);
// 	new -> content = content;
// 	new -> next = NULL;
// 	return (new);
// }