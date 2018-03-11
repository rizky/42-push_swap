/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pw_sort_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 14:30:36 by rnugroho          #+#    #+#             */
/*   Updated: 2018/03/11 05:02:45 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	pw_smart_rotate_a(t_array *a, t_array *b)
{
	int i;

	i = -1;
	while (++i < (int)a->size)
		if (ARRAY_DATA(a, i) == pw_get_min(a))
			break ;
	if (i <= (int)a->size / 2)
		pw_rev_rotate(a, b, "rra");
	else
		pw_rotate(a, b, "ra");
}

void
	pw_split(t_array *a, t_array *b)
{
	int avg;

	avg = pw_get_avg(a);
	while (pw_get_min(a) < avg)
	{
		if (ARRAY_DATA(a, a->size - 1) < avg)
		{
			if (ARRAY_DATA(a, 0) + 1 == ARRAY_DATA(a, a->size - 1))
			{
				pw_smart_rotate_a(a, b);
				if (pw_is_sorted(a))
					return ;
			}
			pw_push(b, a, "pb");
		}
		else
		{
			pw_smart_rotate_a(a, b);
		}
	}
}

void
	pw_sort(t_array *a, t_array *b)
{
	int	i;

	if (a->size == 0)
		return ;
	i = a->size - 1;
	while (i > 0)
	{
		if (ARRAY_DATA(a, a->size - 2) == pw_get_min(a) &&
			ARRAY_DATA(a, a->size - 1) == pw_get_max(a))
			pw_rotate(a, b, "ra");
		if (ARRAY_DATA(a, i - 1) < ARRAY_DATA(a, i))
		{
			while (i < (int)a->size - 1)
			{
				pw_rotate(a, b, "ra");
				i++;
			}
			if (ARRAY_DATA(a, a->size - 2) == pw_get_min(a) &&
			ARRAY_DATA(a, a->size - 1) == pw_get_max(a))
				pw_rotate(a, b, "ra");
			else
				pw_swap(a, b, "sa");
		}
		i--;
	}
}

void
	pw_sort_desc(t_array *a, t_array *b)
{
	int	i;

	if (b->size == 0)
		return ;
	i = b->size - 1;
	while (i > 0)
	{
		if (ARRAY_DATA(b, b->size - 1) == pw_get_min(b) &&
			ARRAY_DATA(b, b->size - 2) == pw_get_max(b))
			pw_rotate(b, a, "rb");
		if (ARRAY_DATA(b, i - 1) > ARRAY_DATA(b, i))
		{
			while (i < (int)b->size - 1)
			{
				pw_rotate(b, a, "rb");
				i++;
			}
			if (ARRAY_DATA(b, b->size - 1) == pw_get_min(b) &&
			ARRAY_DATA(b, b->size - 2) == pw_get_max(b))
				pw_rotate(b, a, "rb");
			else
				pw_swap(b, a, "sb");
		}
		i--;
	}
}

void
	ft_push_swap_simple(t_array *a, t_array *b)
{
	if (pw_is_sorted(a))
		return ;
	if (a->size > 4)
		pw_split(a, b);
	pw_sort(a, b);
	pw_sort_desc(a, b);
	pw_merge(a, b);
}
