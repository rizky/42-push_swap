/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pw_helper_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 14:30:36 by rnugroho          #+#    #+#             */
/*   Updated: 2018/03/11 18:18:00 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	pw_smart_rotate(t_array *a, t_array *b)
{
	int i;

	i = -1;
	while (++i < (int)a->size)
		if (ARRAY_DATA(a, i) == pw_get_max(a))
			break ;
	if (i <= (int)a->size / 2)
		pw_rev_rotate(a, b, "rrb");
	else
		pw_rotate(a, b, "rb");
}

void
	pw_get_max_to_a(t_array *a, t_array *b)
{
	if (pw_get_max(b) == ARRAY_DATA(b, b->size - 1))
		pw_push(a, b, "pa");
	else
	{
		if (ARRAY_DATA(b, b->size - 1) == ARRAY_DATA(a, 0) + 1 ||
			ARRAY_DATA(b, b->size - 1) == 1)
		{
			pw_push(a, b, "pa");
			pw_rotate(a, b, "ra");
		}
		else
			pw_smart_rotate(b, a);
	}
}

void
	pw_split_to_a(t_array *a, t_array *b, int avg, int size)
{
	while (size-- > 0)
	{
		if (b->size < 13)
			pw_get_max_to_a(a, b);
		else
		{
			if (avg <= ARRAY_DATA(b, b->size - 1))
				pw_push(a, b, "pa");
			else
			{
				if (ARRAY_DATA(b, b->size - 1) == ARRAY_DATA(a, 0) + 1 ||
					ARRAY_DATA(b, b->size - 1) == 1)
				{
					pw_push(a, b, "pa");
					pw_rotate(a, b, "ra");
				}
				else
					pw_rotate(b, a, "rb");
			}
		}
	}
}

void
	pw_split_to_b(t_array *a, t_array *b, int avg, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (avg > ARRAY_DATA(a, a->size - 1))
			pw_push(b, a, "pb");
		else
			pw_rotate(a, b, "ra");
		i++;
	}
}
