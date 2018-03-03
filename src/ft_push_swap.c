/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 14:30:36 by rnugroho          #+#    #+#             */
/*   Updated: 2018/03/03 04:32:33 by rnugroho         ###   ########.fr       */
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

void
	pw_split(t_array *a, t_array *b)
{
	int avg;
	int	i;

	avg = pw_get_avg(a);
	i = a->size - 1;
	while (i >= 0)
	{
		if (avg >= ARRAY_DATA(a, a->size - 1))
		{
			pw_push(a, b);
			ft_printfln("pb");
		}
		else
		{
			pw_rev_rotate(a);
			ft_printfln("rra");
		}
		i--;
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
			if (ARRAY_DATA(dv, i) > ARRAY_DATA(dv, j))
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
	while (i < (int)v->size)
	{
		j = 0;
		while (j < (int)dv->size)
		{
			if (ARRAY_DATA(v, i) == ARRAY_DATA(dv, j) &&
				ARRAY_DATA(dv, j) != 999999)
			{
				ARRAY_DATA(dv, j) = 999999;
				break ;
			}
			j++;
		}
		ARRAY_DATA(v, i) = j;
		i++;
	}
}

void
	pw_bubblesort(t_array *v)
{
	int	i;

	if (v->size == 0)
		return ;
	i = v->size - 1;
	while (i > 0)
	{
		if (ARRAY_DATA(v, 1) == pw_get_max(v) &&
			ARRAY_DATA(v, 0) == pw_get_min(v))
			{
				ft_printfln("ra");
				pw_rotate(v);
			}
		if (ARRAY_DATA(v, i - 1) < ARRAY_DATA(v, i))
		{
			if (i > (int)v->size / 2)
			{
				while (i < (int)v->size - 1)
				{
					ft_printfln("rra");
					pw_rev_rotate(v);
					i++;
				}
			}
			else
			{
				while (i > 0)
				{
					ft_printfln("ra");
					pw_rotate(v);
					i--;
				}
			}
			ft_printfln("sa");
			pw_swap(v);
			while (ARRAY_DATA(v, 0) > ARRAY_DATA(v, v->size - 1))
			{
				if (ARRAY_DATA(v, v->size - 1) == pw_get_min(v) &&
					ARRAY_DATA(v, 0) == pw_get_max(v))
					break ;
				ft_printfln("ra");
				pw_rotate(v);
				ft_printfln("sa");
				pw_swap(v);
			}
			i = v->size - 1;
		}
		else
			i--;
	}
}

void
	pw_bubblesort_desc(t_array *v)
{
	int	i;

	if (v->size == 0)
		return ;
	i = v->size - 1;
	while (i > 0)
	{
		if (ARRAY_DATA(v, 1) == pw_get_min(v) &&
			ARRAY_DATA(v, 0) == pw_get_max(v))
			{
				ft_printfln("rb");
				pw_rotate(v);
			}
		if (ARRAY_DATA(v, i - 1) > ARRAY_DATA(v, i))
		{
			if (i > (int)v->size / 2)
			{
				while (i < (int)v->size - 1)
				{
					ft_printfln("rrb");
					pw_rev_rotate(v);
					i++;
				}
			}
			else
			{
				while (i > 0)
				{
					ft_printfln("rb");
					pw_rotate(v);
					i--;
				}
			}
			ft_printfln("sb");
			pw_swap(v);
			while (ARRAY_DATA(v, 0) < ARRAY_DATA(v, v->size - 1))
			{
				if (ARRAY_DATA(v, v->size - 1) == pw_get_max(v) &&
					ARRAY_DATA(v, 0) == pw_get_min(v))
					break ;
				ft_printfln("rb");
				pw_rotate(v);
				ft_printfln("sb");
				pw_swap(v);
			}
			i = v->size - 1;
		}
		else
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
		// pw_print_stack(&a, &b);
		pw_rank(&a, &da);
		// pw_print_stack(&a, &b);
		// pw_split(&a, &b);
		// pw_print_stack(&a, &b);
		pw_bubblesort(&a);
		// pw_print_stack(&a, &b);
		// pw_bubblesort_desc(&b);
		// pw_print_stack(&a, &b);
		// pw_merge(&a, &b);
		// pw_print_stack(&a, &b);
	}
}
