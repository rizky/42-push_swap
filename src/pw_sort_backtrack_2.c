/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pw_sort_backtrack_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 14:30:36 by rnugroho          #+#    #+#             */
/*   Updated: 2018/03/11 18:05:41 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	pw_backtrack(t_array *a, t_array *b, int limit)
{
	while (ARRAY_DATA(a, a->size - 1) <= limit &&
			ARRAY_DATA(a, a->size - 1) != 1)
	{
		if (ARRAY_DATA(a, a->size - 1) == ARRAY_DATA(a, 0) + 1)
			pw_rotate(a, b, "ra");
		else
			pw_push(b, a, "pb");
	}
	if (pw_get_min(b) == ARRAY_DATA(a, 0) + 1)
		ft_push_swap(a, b);
}

void
	pw_backtrack_split(t_array *a, t_array *b, int limit)
{
	int c;
	int i;
	int avg;

	c = 0;
	avg = pw_get_avg_limit(a, limit);
	while (ARRAY_DATA(a, a->size - 1) <= limit &&
			ARRAY_DATA(a, a->size - 1) != 1)
	{
		if (ARRAY_DATA(a, a->size - 1) >= avg)
		{
			pw_rotate(a, b, "ra");
			c++;
		}
		else
			pw_push(b, a, "pb");
	}
	i = -1;
	while (++i < c)
		if (ARRAY_DATA(b, b->size - 1) != pw_get_max(b))
			pw_rev_rotate_r(a, b, "rrr");
		else
			pw_rev_rotate(a, b, "rra");
	if (pw_get_min(b) == ARRAY_DATA(a, 0) + 1 && c > 0)
		ft_push_swap(a, b);
}

void
	ft_push_swap(t_array *a, t_array *b)
{
	int max;

	if (b->size == 0)
		return ;
	max = pw_get_max(b);
	pw_split_to_a(a, b, pw_get_avg(b), b->size);
	while ((ARRAY_DATA(a, a->size - 1) == ARRAY_DATA(a, 0) + 1 ||
		ARRAY_DATA(a, a->size - 1) == 1) && !pw_is_sorted(a))
		pw_rotate(a, b, "ra");
	ft_push_swap(a, b);
	if (pw_get_size(a, max) >= 20)
		pw_backtrack_split(a, b, max);
	pw_backtrack(a, b, max);
}
