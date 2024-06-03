/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: porellan <porellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:57:32 by miniore           #+#    #+#             */
/*   Updated: 2024/06/03 12:07:36 by porellan         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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

void same_number_parse(t_list *lst)
{
    t_list  *numb;
    t_list  *current;

    numb = lst;
    current = lst->next;
    while (current != NULL)
    {
        if (current->content == numb->content)
        {
            write(2, "Error\n", 6);
            exit(0);
        }
        current = current->next;
    }
}
