/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 14:30:36 by rnugroho          #+#    #+#             */
/*   Updated: 2018/02/26 21:48:12 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void
	pf_print_stack(t_array *a, t_array *b)
{
	int i;

	if (a->size > b->size)
		i = a->size - 1;
	else
		i = b->size - 1;
	while (i >= 0)
	{
		if (i < (int)a->size)
			printf("%2d  ", ((int*)ARRAY_START(a))[i]);
		else
			printf("    ");
		if (i < (int)b->size)
			printf("%2d \n", ((int*)ARRAY_START(b))[i]);
		else
			printf("\n");
		i--;
	}
	printf("--- ---\n");
	printf("%2s  %2s\n", "a", "b");
	printf("--------------------------------------------------\n");
}

int
	main(int ac, char **av)
{
	int		i;
	char	*line;
	t_array		a;
	t_array		b;
	int		temp;
	int		is_verbose;

	a = NEW_ARRAY(int);
	b = NEW_ARRAY(int);
	i = 1;
	is_verbose = 0;
	if (ft_strcmp(av[1], "-v") == 0)
	{
		is_verbose = 1;
		i++;
	}
	if (ac > 1)
	{	
		while (i < ac)
		{
			temp = atoi(av[i]);
			fta_append(&a, &temp, 1);
			i++;
		}
		while (get_next_line(0, &line))
		{
			if (is_verbose)
				printf("Exec %s:\n", line);
			if (line[0] == 's')
			{
				if (line[1] == 'a')
					pf_swap(&a);
				else
					pf_swap(&b);
			}
			else if (line[0] == 'p')
			{
				if (line[1] == 'a')
					pf_push(&b, &a);
				else
					pf_push(&a, &b);
			}
			else if (line[0] == 'r' && ft_strlen(line) == 2)
			{
				if (line[1] == 'a')
					pf_rotate(&a);
				else if (line[1] == 'b')
					pf_rotate(&b);
				else
					{
						pf_rotate(&a);
						pf_rotate(&b);
					}
			}
			else if (line[0] == 'r' && ft_strlen(line) == 3)
			{
				if (line[2] == 'a')
					pf_rev_rotate(&a);
				else if (line[2] == 'b')
					pf_rev_rotate(&b);
				else
					{
						pf_rev_rotate(&a);
						pf_rev_rotate(&b);
					}

			}
			if (is_verbose)
				pf_print_stack(&a, &b);
		}
		if (b.size == 0 && pf_is_sorted(&a))
			printf("OK\n");
		else
			printf("KO\n");
	}	
}