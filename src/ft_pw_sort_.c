/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pw_sort_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 14:30:36 by rnugroho          #+#    #+#             */
/*   Updated: 2018/03/11 02:04:15 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int
	pw_get_max_limit(t_array *d, int limit)
{
	size_t	i;
	int		max;

	if (d->size == 0)
		return (0);
	i = 0;
	max = 0;
	while (i < d->size)
	{
		if (max < ARRAY_DATA(d, i) && ARRAY_DATA(d, i) < limit)
			max = ARRAY_DATA(d, i);
		i++;
	}
	return (max);
}

void
	pw_smart_rotate(t_array *a, t_array *b, int limit)
{
	int i;

	i = -1;
	while (++i < (int)a->size)
		if (ARRAY_DATA(a, i) == pw_get_max_limit(a, limit))
			break ;
	if (i <= (int)a->size / 2)
	{
		pw_rev_rotate(a, b);
		pw_log(b, a, "rrb");
	}
	else
	{

		pw_rotate(a, b);
		pw_log(b, a, "rb");
	}
}

void
	pw_sort_segment(t_array *a, t_array *b, int limit)
{
	while (b->size > 0 && pw_get_min(b) < limit)
	{
		if (pw_get_max_limit(b, limit) == ARRAY_DATA(b, b->size - 1))
		{
			pw_push(a, b);
			pw_log(a, b, "pa");
		}
		else
		{
			if (ARRAY_DATA(b, b->size - 1) == pw_get_min(b))
			{
				pw_push(a, b);
				pw_log(a, b, "pa");
				pw_rotate(a, b);
				pw_log(a, b, "ra");
			}
			pw_smart_rotate(b, a, limit);
		}
	}
	while ((((int*)a->data)[a->size - 1] == ((int*)a->data)[0] + 1 ||
		((int*)a->data)[a->size - 1] == 1) && !pw_is_sorted(a))
	{
		pw_rotate(a, b);
		pw_log(a, b, "ra");
	}
}

void
	pw_split_to_b(t_array *a, t_array *b, int avg, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (ARRAY_DATA(a, a->size - 1) < avg)
		{
			pw_push(b, a);
			pw_log(a, b, "pb");
			if (ARRAY_DATA(b, b->size - 1) > (int)((avg + pw_get_min(b)) / 2.0 + 0.5))
			{
				pw_rotate(b, a);
				pw_log(a, b, "rb");
			}
		}
		else
		{
			pw_rotate(a, b);
			pw_log(a, b, "ra");
		}
		i++;
	}
}

void
	pw_backtrack(t_array *a, t_array *b, int limit)
{
	while (ARRAY_DATA(a, a->size - 1) <= limit &&
			ARRAY_DATA(a, a->size - 1) != 1)
	{
		if (((int*)a->data)[a->size - 1] == ((int*)a->data)[0] + 1)
		{
			pw_rotate(a, b);
			pw_log(a, b, "ra");
		}
		else
		{
			pw_push(b, a);
			pw_log(a, b, "pb");
		}
	}
	if (pw_get_min(b) == ARRAY_DATA(a, 0) + 1)
		ft_push_swap(a, b);
}

void
	pw_split_to_a(t_array *a, t_array *b, int avg, int size)
{
	while (size-- > 0)
	{
		if (b->size < 15)
		{
			if (pw_get_max(b) == ARRAY_DATA(b, b->size - 1))
			{
				pw_push(a, b);
				pw_log(a, b, "pa");
			}
			else
			{
				if (ARRAY_DATA(b, b->size - 1) == pw_get_min(b))
				{
					pw_push(a, b);
					pw_log(a, b, "pa");
					pw_rotate(a, b);
					pw_log(a, b, "ra");
				}
				pw_smart_rotate(b, a, pw_get_max(b) + 1);
			}
		}
		else
		{
			if (avg <= ARRAY_DATA(b, b->size - 1))
			{
				pw_push(a, b);
				pw_log(a, b, "pa");
			}
			else
			{
				pw_rotate(b, a);
				pw_log(a, b, "rb");
			}
		}
	}
}

void
	pw_backtrack_2(t_array *a, t_array *b, int limit)
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
			pw_rotate(a, b);
			pw_log(a, b, "ra");
			c++;
		}
		else
		{
			pw_push(b, a);
			pw_log(a, b, "pb");
		}
	}
	if (c == 0)
		return ;
	i = 0;
	while (i < c)
	{
		pw_rev_rotate(a, b);
		pw_log(a, b, "rra");
		i++;
	}
	if (pw_get_min(b) == ARRAY_DATA(a, 0) + 1)
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
	while ((((int*)a->data)[a->size - 1] == ((int*)a->data)[0] + 1 ||
		((int*)a->data)[a->size - 1] == 1) && !pw_is_sorted(a))
	{
		pw_rotate(a, b);
		pw_log(a, b, "ra");
	}
	ft_push_swap(a, b);
	pw_backtrack(a, b, max);
}

void
	ft_push_swap_segment(t_array *a, t_array *b)
{
	if (pw_is_sorted(a))
		return ;
	pw_split_to_b(a, b, pw_get_avg(a), a->size);
	pw_sort_segment(a, b, pw_get_avg(b));
	pw_sort_segment(a, b, pw_get_max(b) + 1);
	pw_split_to_b(a, b, pw_get_max(a) + 1, (int)a->size / 2);
	pw_sort_segment(a, b, pw_get_avg(b));
	pw_sort_segment(a, b, pw_get_max(b) + 1);
	// pw_backtrack_2(a, b, pw_get_max(a));
	// pw_backtrack_2(a, b, pw_get_max(a));
	// pw_backtrack(a, b, pw_get_max(a));
	fta_clear(a);
	fta_clear(b);
}
