/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: porellan <porellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:57:32 by miniore           #+#    #+#             */
/*   Updated: 2024/11/19 14:01:51 by porellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse(char **argv, int argc)
{
	symbols_parse(argv, argc);
	num_limits_parse(argv, argc);
}

void	symbols_parse(char **argv, int argc)
{
	int	i;
	int	j;

	j = 1;
	while (j < argc)
	{
		i = 0;
		while (argv[j][i])
		{
			if (!ft_isdigit(argv[j][i]) && (argv[j][i] != 43
			&& argv[j][i] != 45) && (argv[j][i] != 34 && argv[j][i] != 32))
			{
				write(2, "Error 1\n", 6);
				exit(0);
			}
			if ((argv[j][i] == 43 || argv[j][i] == 45) &&
			(argv[j][i + 1] < 48 || argv[j][i + 1] > 57))
			{
				write(2, "Error 1\n", 6);
				exit(0);
			}
			i++;
		}
		j++;
	}
}

void	num_limits_parse(char **argv, int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_atol(argv[i]) < -2147483648 || ft_atol(argv[i]) > 2147483647)
		{
			write(2, "Error 1\n", 6);
			exit(0);
		}
		i++;
	}
}

void	same_number_parse(t_list **lst)
{
	t_list	*numb;
	t_list	*current;

	numb = *lst;
	while (numb != NULL)
	{
		current = numb->next;
		while (current != NULL)
		{
			if (*(int *)current->content == *(int *)numb->content)
			{
				write(2, "Error 1\n", 6);
				clear_lst(*lst);
				exit(0);
			}
			current = current->next;
		}
		numb = numb->next;
	}
}
