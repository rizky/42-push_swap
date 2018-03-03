/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 14:30:36 by rnugroho          #+#    #+#             */
/*   Updated: 2018/03/04 00:31:33 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	pw_split_min(t_array *a, t_array *b, int size)
{
	int avg;
	int	i;

	avg = pw_get_avg(a);
	i = 0;
	while (i < size)
	{
		if (avg >= ARRAY_DATA(a, a->size - 1))
		{
			ft_printfln("pb");
			pw_push(a, b);
		}
		else
		{
			ft_printfln("rra");
			pw_rev_rotate(a);
		}
		i++;
	}
}

void
	pw_split_max(t_array *a, t_array *b, int size)
{
	int avg;
	int	i;

	avg = pw_get_avg(a);
	i = 0;
	while (i < size)
	{
		if (avg <= ARRAY_DATA(a, a->size - 1))
		{
			ft_printfln("pa");
			pw_push(a, b);
		}
		else
		{
			ft_printfln("rrb");
			pw_rev_rotate(a);
		}
		i++;
	}
}

int
	main(int ac, char **av)
{
	int			i;
	t_array		a;
	t_array		da;
	t_array		b;
	int			temp;

	a = NEW_ARRAY(int);
	da = NEW_ARRAY(int);
	b = NEW_ARRAY(int);

	i = 1;
	if (ac > 1)
	{
		while (i < ac)
		{
			temp = atoi(av[i]);
			fta_append(&a, &temp, 1);
			fta_append(&da, &temp, 1);
			i++;
		}
		pw_bubblesort(&da);
		pw_print_stripe(&a, &da);
		pw_rank(&a, &da);
		pw_print_stripe(&a, &b);
		pw_split_min(&a, &b, a.size);
		while (!pw_is_sorted(&a) || b.size > 0)
		{
			while (b.size > 0)
				pw_split_max(&b, &a, b.size);
			if (((int*)a.data)[a.size - 1] == pw_get_min(&a))
			{
				ft_printfln("rra");
				pw_rev_rotate(&a);
			}
			while (((int*)a.data)[a.size - 1] > ((int*)a.data)[0])
			{
				ft_printfln("rra");
				pw_rev_rotate(&a);
			}
			while (((int*)a.data)[a.size - 1] < ((int*)a.data)[0]
				&& ((int*)a.data)[a.size - 1] != pw_get_min(&a))
			{
				ft_printfln("pb");
				pw_push(&a, &b);
			}
			while (b.size > 0 && ((int*)a.data)[0] > ((int*)b.data)[0])
			{
				ft_printfln("ra");
				pw_rotate(&a);
			}
		}
		pw_print_stripe(&a, &b);
	}
}
