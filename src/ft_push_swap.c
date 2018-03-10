/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 14:30:36 by rnugroho          #+#    #+#             */
/*   Updated: 2018/03/10 05:22:33 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int g_isverbose;

void
	pw_log(t_array *a, t_array *b, char *instr)
{
	if (g_isverbose)
		pw_print_stack(a, b);
	else
		ft_printfln("%s", instr);
}

void
	pw_merge(t_array *a, t_array *b)
{
	while (b->size > 0)
	{
		pw_push(a, b);
		pw_log(a, b, "pa");
	}
}

void
	pw_smart_rotate(t_array *a, t_array *b)
{
	int i;

	i = -1;
	while (++i < (int)a->size)
		if (ARRAY_DATA(a, i) == pw_get_min(a))
			break ;
	if (i <= (int)a->size / 2)
	{
		pw_rotate(a, b);
		pw_log(a, b, "ra");
	}
	else
	{
		pw_rev_rotate(a, b);
		pw_log(a, b, "rra");
	}
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
				pw_smart_rotate(a, b);
				if (pw_is_sorted(a))
					return ;
			}
			pw_push(b, a);
			pw_log(a, b, "pb");
		}
		else
		{
			pw_smart_rotate(a, b);
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
		{
			pw_rev_rotate(a, b);
			pw_log(a, b, "rra");
		}
		if (ARRAY_DATA(a, i - 1) < ARRAY_DATA(a, i))
		{
			while (i < (int)a->size - 1)
			{
				pw_rev_rotate(a, b);
				pw_log(a, b, "rra");
				i++;
			}
			if (ARRAY_DATA(a, a->size - 2) == pw_get_min(a) &&
			ARRAY_DATA(a, a->size - 1) == pw_get_max(a))
			{
				pw_rev_rotate(a, b);
				pw_log(a, b, "rra");
			}
			else
			{
				pw_swap(a, b);
				pw_log(a, b, "sa");
			}
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
		{
			pw_rev_rotate(b, a);
			pw_log(a, b, "rrb");
		}
		if (ARRAY_DATA(b, i - 1) > ARRAY_DATA(b, i))
		{
			while (i < (int)b->size - 1)
			{
				pw_rev_rotate(b, a);
				pw_log(a, b, "rrb");
				i++;
			}
			if (ARRAY_DATA(b, b->size - 1) == pw_get_min(b) &&
			ARRAY_DATA(b, b->size - 2) == pw_get_max(b))
			{
				pw_rev_rotate(b, a);
				pw_log(a, b, "rrb");
			}
			else
			{
				pw_swap(b, a);
				pw_log(a, b, "sb");
			}
		}
		i--;
	}
}

int
	main(int ac, char **av)
{
	int			i;
	t_array		a;
	t_array		b;

	if (ac > 1)
	{
		i = pw_getoptions(av, &g_isverbose);
		pw_get_arg(&a, i, ac, av);
		pw_get_arg(&b, i, ac, av);
		if (pw_is_sorted(&a))
			return (0);
		pw_sortdata_quick(&b, 0, b.size - 1);
		pw_rank(&a, &b);
		pw_split(&a, &b);
		pw_sort(&a, &b);
		pw_sort_desc(&a, &b);
		pw_merge(&a, &b);
	}
}
