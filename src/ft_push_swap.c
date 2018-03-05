/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 14:30:36 by rnugroho          #+#    #+#             */
/*   Updated: 2018/03/05 20:45:36 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int
	pw_split_min(t_array *a, t_array *b, int size)
{
	int avg;
	int	i;
	int	rr;

	avg = pw_get_avg(a, size);
	i = 0;
	rr = 0;
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
			rr++;
		}
		i++;
	}
	return (rr);
}

void
	pw_split_max(t_array *a, t_array *b, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (a->size < 7)
		{
			if (pw_get_max(a) == ARRAY_DATA(a, a->size - 1))
			{
				ft_printfln("pa");
				pw_push(a, b);
			}
			else
			{
				ft_printfln("rrb");
				pw_rev_rotate(a);
			}
		}
		else
		{
			if (pw_get_avg(a, a->size) <= ARRAY_DATA(a, a->size - 1))
			{
				ft_printfln("pa");
				pw_push(a, b);
			}
			else
			{
				ft_printfln("rrb");
				pw_rev_rotate(a);
			}
		}
		i++;
	}
}

void
	ft_push_swap_1(t_array a, t_array b)
{
	pw_split_min(&a, &b, a.size);
	while (!pw_is_sorted(&a) || b.size > 0)
	{
		while (b.size > 0)
			pw_split_max(&b, &a, b.size);
		if (pw_is_sorted(&a))
			break ;
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
}

int
	pw_get_nmin(t_array *d, int n)
{
	size_t	i;
	int		min;

	if (d->size == 0)
		return (0);
	i = d->size - 1;
	min = ARRAY_DATA(d, i);
	while (i > d->size - n)
	{
		if (min > ARRAY_DATA(d, i))
			min = ARRAY_DATA(d, i);
		i--;
	}
	return (min);
}

void
	ft_push_swap_2(t_array a, t_array b)
{
	int counter;
	counter = 0;
	pw_split_min(&a, &b, a.size);
	while (!pw_is_sorted(&a) || b.size > 0)
	{
		while (b.size > 0)
			pw_split_max(&b, &a, b.size);
		if (pw_is_sorted(&a))
			break ;
		if (((int*)a.data)[a.size - 1] == pw_get_min(&a))
		{
			ft_printfln("rra");
			pw_rev_rotate(&a);
			counter++;
		}
		while (((int*)a.data)[a.size - 1] == ((int*)a.data)[0] + 1)
		{
			ft_printfln("rra");
			pw_rev_rotate(&a);
			counter++;
		}
		if (pw_is_sorted(&a))
			break ;
		while (((int*)a.data)[a.size - 1] != pw_get_min(&a))
		{
			if (((int*)a.data)[a.size - 1] == ((int*)a.data)[0] + 1)
			{
				ft_printfln("rra");
				pw_rev_rotate(&a);
				counter++;
			}
			else
			{
				ft_printfln("pb");
				pw_push(&a, &b);
			}
		}
	}
}

void
	ft_push_swap_3(t_array a, t_array b)
{
	pw_split_min(&a, &b, a.size);
	while (!pw_is_sorted(&a) || b.size > 0)
	{
		while (b.size > 0)
			pw_split_max(&b, &a, b.size);
		if (pw_is_sorted(&a))
			break ;
		if (((int*)a.data)[a.size - 1] == pw_get_min(&a))
		{
			ft_printfln("rra");
			pw_rev_rotate(&a);
		}
		while (((int*)a.data)[a.size - 1] == ((int*)a.data)[0] + 1)
		{
			ft_printfln("rra");
			pw_rev_rotate(&a);
		}
		if (pw_is_sorted(&a))
			break ;
		while (((int*)a.data)[a.size - 1] != ((int*)a.data)[0] + 1)
		{
			ft_printfln("pb");
			pw_push(&a, &b);
		}
		ft_printfln("rra");
		pw_rev_rotate(&a);
	}
}

void
	pw_split_mt_avg_verbose(t_array *a, t_array *b)
{
	int avg;
	int i;
	int size;
	int max;
	static int depth = 0;

	size = b->size;
	avg = pw_get_avg(b, b->size);
	max = pw_get_max(b);
	depth++;
	ft_printfln("%d - Split avg(%d) max(%d)", depth, avg, max);
	i = 0;
	while (i < size)
	{
		if (b->size < 10)
		{
			if (pw_get_max(b) == ARRAY_DATA(b, b->size - 1))
				pw_push(b, a);
			else
				pw_rotate(b);
		}
		else
		{
			if (avg <= ARRAY_DATA(b, b->size - 1))
				pw_push(b, a);
			else
				pw_rev_rotate(b);
		}
		i++;
		pw_print_stripe(a, b);
		ft_printfln("%d - Split by avg: (%d)", depth, avg);
	}
	if (pw_is_sorted(a))
		return ;
	if (((int*)a->data)[a->size - 1] == 1)
	{
		pw_rev_rotate(a);
		pw_print_stripe(a, b);
		ft_printfln("%d - First Push", depth);
	}
	while (((int*)a->data)[a->size - 1] == ((int*)a->data)[0] + 1)
	{
		pw_rev_rotate(a);
		pw_print_stripe(a, b);
		ft_printfln("%d - Sorted avg(%d) max(%d)", depth, avg, max);
	}
	if (pw_get_min(b) == ARRAY_DATA(a,0) + 1 || pw_get_min(b) == 1)
		pw_split_mt_avg_verbose(a, b);
	while (ARRAY_DATA(a, a->size - 1) <= avg && ARRAY_DATA(a, a->size - 1) != 1)
	{
		pw_push(a, b);
		pw_print_stripe(a, b);
		ft_printfln("%d - Backtrack Avg: (%d)", depth, avg);
	}
	if (pw_get_min(b) == ARRAY_DATA(a,0) + 1)
		pw_split_mt_avg_verbose(a, b);
	while (ARRAY_DATA(a, a->size - 1) <= max && ARRAY_DATA(a, a->size - 1) != 1)
	{
		if (((int*)a->data)[a->size - 1] == ((int*)a->data)[0] + 1)
			pw_rev_rotate(a);
		else
			pw_push(a, b);
		pw_print_stripe(a, b);
		ft_printfln("%d - Backtrack Max: (%d)", depth, max);
	}
	if (pw_get_min(b) == ARRAY_DATA(a,0) + 1)
		pw_split_mt_avg_verbose(a, b);
	depth--;
}

void
	ft_push_swap_4_verbose(t_array a, t_array b)
{
	while (a.size > 0)
	{
		pw_push(&a, &b);
		// pw_print_stripe(&a, &b);
	}
	pw_split_mt_avg_verbose(&a, &b);
}

void
	pw_split_mt_avg(t_array *a, t_array *b)
{
	int avg;
	int i;
	int size;
	int max;

	if (b->size == 0)
		return ;
	avg = pw_get_avg(b, b->size);
	max = pw_get_max(b);
	i = 0;
	size = b->size;
	while (i < size)
	{
		if (b->size < 7)
		{
			if (pw_get_max(b) == ARRAY_DATA(b, b->size - 1))
			{
				pw_push(b, a);
				ft_printfln("pa");
			}
			else
			{
				pw_rev_rotate(b);
				ft_printfln("rrb");
			}
		}
		else
		{
			if (avg <= ARRAY_DATA(b, b->size - 1))
			{
				ft_printfln("pa");
				pw_push(b, a);
			}
			else
			{
				ft_printfln("rrb");
				pw_rev_rotate(b);
			}
		}
		i++;
	}
	if (pw_is_sorted(a))
		return ;
	if (((int*)a->data)[a->size - 1] == 1)
	{
		pw_rev_rotate(a);
		ft_printfln("rra");
	}
	while (((int*)a->data)[a->size - 1] == ((int*)a->data)[0] + 1)
	{
		pw_rev_rotate(a);
		ft_printfln("rra");
	}
	pw_split_mt_avg(a, b);
	if (pw_is_sorted(a))
		return ;
	while (ARRAY_DATA(a, a->size - 1) <= avg && ARRAY_DATA(a, a->size - 1) != 1)
	{
		pw_push(a, b);
		ft_printfln("pb");
	}
	if (pw_get_min(b) == ARRAY_DATA(a,0) + 1)
		pw_split_mt_avg(a, b);
	while (ARRAY_DATA(a, a->size - 1) != ((int*)a->data)[0] + 1 && ARRAY_DATA(a, a->size - 1) != 1)
	{
		pw_push(a, b);
		ft_printfln("pb");
	}
}

void
	ft_push_swap_4(t_array a, t_array b)
{
	while (a.size > 0)
	{
		pw_push(&a, &b);
		ft_printfln("pb");
	}
	while (!pw_is_sorted(&a) || a.size == 0 || b.size != 0)
		pw_split_mt_avg(&a, &b);
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
			temp = ft_atoi(av[i]);
			fta_append(&a, &temp, 1);
			fta_append(&da, &temp, 1);
			i++;
		}
		pw_sortdata_quick(&da);
		pw_rank(&a, &da);
		ft_push_swap_4_verbose(a, b);
	}
}
