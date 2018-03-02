/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 14:30:36 by rnugroho          #+#    #+#             */
/*   Updated: 2018/03/02 15:06:20 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void
	pw_merge(t_array *a, t_array *b)
{
	while (b->size > 0)
	{
		pw_push(b, a);
	}
}

void
	pw_split(t_array *a, t_array *b)
{
	int avg;

	avg = pw_get_avg(a);
	while (pw_get_min(a) < avg)
	{
		if (ARRAY_DATA(a, a->size - 2) < ARRAY_DATA(a, a->size - 1))
			pw_swap(a);
		if (avg >= ARRAY_DATA(a, a->size - 1))
			pw_push(a, b);
		else
			pw_rev_rotate(a);
	}
}

void
	pw_rank(t_array *v, t_array *dv)
{
	int	temp;
	int	i;
	int j;

	i = 0;
	while (i < (int)dv->size - 1)
	{
		j = i + 1;
		while (j < (int)dv->size)
		{
			if (ARRAY_DATA(dv, i) < ARRAY_DATA(dv, j))
				{
					temp  = ARRAY_DATA(dv, j);
					ARRAY_DATA(dv, j) = ARRAY_DATA(dv, i);
					ARRAY_DATA(dv, i) = temp;
				}
			j++;
		}
		i++;
	}
	i = 0;
	while (i < (int)dv->size)
	{
		j = 0;
		while (ARRAY_DATA(dv, i) != ARRAY_DATA(v, j))
			j++;
		ARRAY_DATA(v, j) = i;
		i++;
	}
}

void
	pw_sort(t_array *v)
{
	int	i;

	if (v->size == 0)
		return ;
	i = v->size - 1;
	while (i > 0)
	{
		if (ARRAY_DATA(v, v->size - 2) == pw_get_min(v) &&
			ARRAY_DATA(v, v->size - 1) == pw_get_max(v))
			pw_rev_rotate(v);
		if (ARRAY_DATA(v, i - 1) < ARRAY_DATA(v, i))
		{
			while (i < (int)v->size - 1)
			{
				pw_rev_rotate(v);
				i++;
			}
			if (ARRAY_DATA(v, v->size - 2) == pw_get_min(v) &&
			ARRAY_DATA(v, v->size - 1) == pw_get_max(v))
				pw_rev_rotate(v);
			else
				pw_swap(v);
		}
		i--;
	}
}

void
	pw_sort_desc(t_array *v)
{
	int	i;

	if (v->size == 0)
		return ;
	i = v->size - 1;
	while (i > 0)
	{
		if (ARRAY_DATA(v, v->size - 1) == pw_get_min(v) &&
			ARRAY_DATA(v, v->size - 2) == pw_get_max(v))
			pw_rev_rotate(v);
		if (ARRAY_DATA(v, i - 1) > ARRAY_DATA(v, i))
		{
			while (i < (int)v->size - 1)
			{
				pw_rev_rotate(v);
				i++;
			}
			if (ARRAY_DATA(v, v->size - 1) == pw_get_min(v) &&
			ARRAY_DATA(v, v->size - 2) == pw_get_max(v))
				pw_rev_rotate(v);
			else
				pw_swap(v);
		}
		i--;
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
	int			is_verbose;

	a = NEW_ARRAY(int);
	da = NEW_ARRAY(int);
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
			fta_append(&da, &temp, 1);
			i++;
		}
		pw_rank(&a, &da);
		pw_print_stack(&a, &b);
		pw_split(&a, &b);
		pw_print_stack(&a, &b);
		pw_sort(&a);
		pw_print_stack(&a, &b);
		pw_sort_desc(&b);
		pw_print_stack(&a, &b);
		pw_merge(&a, &b);
		pw_print_stack(&a, &b);
	}
}
