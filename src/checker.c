/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 14:30:36 by rnugroho          #+#    #+#             */
/*   Updated: 2018/02/26 16:10:29 by rnugroho         ###   ########.fr       */
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
			printf("%3d ", ((int*)ARRAY_START(a))[i]);
		else
			printf("    ");
		if (i < (int)b->size)
			printf("%3d \n", ((int*)ARRAY_START(b))[i]);
		else
			printf("\n");
		i--;
	}
	printf("--- ---\n");
	printf("%2s %2s\n", "a", "b");
}

int
	main(int ac, char **av)
{
	int		i;
	char	*line;
	t_array		a;
	t_array		b;
	int		temp;

	a = NEW_ARRAY(int);
	b = NEW_ARRAY(int);
	i = 1;
	if (ac > 1)
	{	
		while (i < ac)
		{
			temp = atoi(av[i]);
			fta_append(&a, &temp, 1);
			i++;
		}
		temp = 2;
		fta_append(&b, &temp, 1);
		pf_print_stack(&a, &b);
		while (get_next_line(0, &line))
		{
			printf("%s\n", line);
		}
		i = 0;
	}	
}