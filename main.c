/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: porellan <porellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:51:37 by porellan          #+#    #+#             */
/*   Updated: 2024/11/27 10:12:35 by porellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	if (argc < 2)
		return (0);
	b = NULL;
	parse(argv, argc);
	a = lst_maker(argv, argc);
	same_number_parse(&a);
	sort(&a, &b);
	clear_lst(a);
	return (0);
}
