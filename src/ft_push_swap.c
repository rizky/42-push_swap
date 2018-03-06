/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 14:30:36 by rnugroho          #+#    #+#             */
/*   Updated: 2018/03/06 14:20:09 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	pw_smart_rotate(t_array *a, t_array *b)
{
	int i;

	i = -1;
	while (++i < (int)a->size)
		if (ARRAY_DATA(a, i) == pw_get_max(a))
			break ;
	if (i <= (int)a->size / 2)
	{
		pw_rotate(a, b);
		pw_log(b, a, "rb");
	}
	else
	{
		pw_rev_rotate(a, b);
		pw_log(b, a, "rrb");
	}
}

void
	pw_split_avg(t_array *a, t_array *b, int avg, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (b->size < 10)
		{
			if (pw_get_max(b) == ARRAY_DATA(b, b->size - 1))
			{
				pw_push(a, b);
				pw_log(a, b, "pa");
			}
			else
				pw_smart_rotate(b, a);
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
				pw_rev_rotate(b, a);
				pw_log(a, b, "rrb");
			}
		}
		i++;
		
	}
}

void
	pw_split_avg_rev(t_array *a, t_array *b, int avg, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (avg > ARRAY_DATA(a, a->size - 1))
		{
			pw_push(b, a);
			pw_log(a, b, "pb");
		}
		else
		{
			pw_rev_rotate(a, b);
			pw_log(a, b, "rra");
		}
		i++;
	}
}

void
	pw_backtrack(t_array *a, t_array *b, int size)
{
	while (ARRAY_DATA(a, a->size - 1) <= size && ARRAY_DATA(a, a->size - 1) != 1)
	{
		if (((int*)a->data)[a->size - 1] == ((int*)a->data)[0] + 1)
		{
			pw_rev_rotate(a, b);
			pw_log(a, b, "rra");
		}
		else
		{
			pw_push(b, a);
			pw_log(a, b, "pb");
		}
	}
	if (pw_get_min(b) == ARRAY_DATA(a,0) + 1)
		ft_push_swap(a, b);
}

void
	ft_push_swap(t_array *a, t_array *b)
{
	int avg;
	int max;

	if (b->size == 0)
		return ;
	avg = pw_get_avg(b, b->size);
	max = pw_get_max(b);
	pw_split_avg(a, b, avg, b->size);
	while ((((int*)a->data)[a->size - 1] == ((int*)a->data)[0] + 1 ||
		((int*)a->data)[a->size - 1] == 1) && !pw_is_sorted(a))
	{
		pw_rev_rotate(a, b);
		pw_log(a, b, "rra");
	}
	ft_push_swap(a, b);
	pw_backtrack(a, b, avg);
	pw_backtrack(a, b, max);
}

int
	main(int ac, char **av)
{
	int			i;
	int			num;
	t_array		a;
	t_array		b;

	a = NEW_ARRAY(int);
	b = NEW_ARRAY(int);
	i = 1;
	g_isverbose = 0;
	if (ac > 1)
	{
		while (i < ac)
		{
			num = ft_atoi(av[i]);
			fta_append(&a, &num, 1);
			fta_append(&b, &num, 1);
			i++;
		}
		pw_sortdata_quick(&b);
		pw_rank(&a, &b);
		fta_clear(&b);
		b = NEW_ARRAY(int);
		pw_split_avg_rev(&a, &b, pw_get_avg(&a, a.size), a.size);
		ft_push_swap(&a, &b);
		pw_backtrack(&a, &b, pw_get_max(&a));
	}
}
