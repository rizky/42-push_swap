/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 14:30:36 by rnugroho          #+#    #+#             */
/*   Updated: 2018/03/03 21:51:11 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	pw_merge(t_array *a, t_array *b)
{
	while (b->size > 0)
	{
		pw_push(b, a);
		ft_printfln("pa");
	}
}

int
	pw_partition_array(t_array *v, int left, int right, int pivot)
{
	int temp;

	while (left <= right)
	{
		while (ARRAY_DATA(v, left) > pivot)
			left++;
		while (ARRAY_DATA(v, right) < pivot)
			right--;
		if (left <= right)
		{
			temp = ARRAY_DATA(v, right);
			ARRAY_DATA(v, right) = ARRAY_DATA(v, left);
			ARRAY_DATA(v, left) = temp;
			left++;
			right--;
			ft_printfln("pb");
			ft_printfln("rra");
			ft_printfln("pa");
			ft_printfln("rrb");
		}
	}
	return left;
}

void
	pw_quicksort_array(t_array *v, int left, int right)
{
	int pivot;
	int index;

	if (left >= right)
		return ;
	pivot = ARRAY_DATA(v, (right + left) / 2);
	index = pw_partition_array(v, left, right, pivot);
	pw_quicksort_array(v, left, index - 1);
	pw_quicksort_array(v, index, right);
}

void
	pw_sortdata_quick(t_array *v)
{
	pw_quicksort_array(v, 0, (int)v->size - 1);
}

// void
// 	pw_sort_quick(t_array *a, t_array *b)
// {
// 	pw_quicksort(a, b);
// }

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
		// pw_print_stack(&a, &b);
		pw_sortdata_quick(&da);
		// pw_print_stack(&a, &da);
		// pw_split(&a, &b);
		// pw_print_stack(&a, &b);
		// pw_bubblesort(&a);
		// pw_print_stack(&a, &b);
		// pw_bubblesort_desc(&b);
		// pw_print_stack(&a, &b);
		// pw_merge(&a, &b);
		// pw_print_stack(&a, &b);
	}
}
