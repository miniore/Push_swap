/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: porellan <porellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:51:37 by porellan          #+#    #+#             */
/*   Updated: 2024/05/16 14:57:01 by porellan         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

int main(int argc, char *argv[])
{
    int i;
    int j;
    char    **result;
    
    j = 1;
    if (argc < 2)
        write(2, "Error\n", 6);
    while (j < argc)
    {
        i = 0;
        while (argv[j][i])
        {
            if ((argv[j][i] < 48 || argv[j][i] > 57) && 
                (argv[j][i] != 43 && argv[j][i] != 45 && argv[j][i] != 34 && 
                argv[j][i] != 32))
                write(2, "Error\n", 6);
            if ((argv[j][i] == 43 || argv[j][i] == 45) && 
                (argv[j][i+1] < 48 || argv[j][i+1] > 57))
                write(2, "Error\n", 6);
            i++;
        }
        result = ft_split(argv[j], 32);
        while (*result)
        {
            ft_printf("%s\n", *result); //incluir en stack
            result++;
        }
        j++;
    }
}
