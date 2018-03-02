/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 14:30:36 by rnugroho          #+#    #+#             */
/*   Updated: 2018/03/02 12:30:34 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void
	pw_split(t_array *a, t_array *b)
{
	int i;
	int median;
	int fmedian;

	i = a->size;
	fmedian = pw_get_avg(a);
	median = 0;
	while (pw_get_min(a) < pw_get_max(b))
	{
		median = pw_get_avg(a);
		if (median >= ARRAY_DATA(a, a->size - 1))
			pw_push(a, b);
		else
			pw_rev_rotate(a);
		pw_print_stack(a, b);
		i--;
	}
}

int
	main(int ac, char **av)
{
	int			i;
	t_array		a;
	t_array		b;
	int			temp;
	int			is_verbose;

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
		pw_print_stack(&a, &b);
		pw_split(&a, &b);
		pw_print_stack(&a, &b);
	}
}
