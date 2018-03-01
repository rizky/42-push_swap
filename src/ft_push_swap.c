/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 14:30:36 by rnugroho          #+#    #+#             */
/*   Updated: 2018/03/01 18:54:51 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

#define ARRAY_DATA(D, I) ((int*)ARRAY_START(D))[I]

int
	pw_get_min(t_array *d)
{
	size_t	i;
	int		min;

	if (d->size == 0)
		return (0);
	i = 0;
	min = ARRAY_DATA(d, i);
	while (i < d->size)
	{
		if (min > ARRAY_DATA(d, i))
			min = ARRAY_DATA(d, i);
		i++;
	}
	return (min);
}

int
	pw_get_max(t_array *d)
{
	size_t	i;
	int		max;

	if (d->size == 0)
		return (0);
	i = 0;
	max = 0;
	while (i < d->size)
	{
		if (max < ARRAY_DATA(d, i))
			max = ARRAY_DATA(d, i);
		i++;
	}
	return (max);
}

int
	pw_get_median(t_array *d)
{
	size_t	i;
	int		max;
	int		min;

	if (d->size == 0)
		return (0);
	i = 0;
	max = 0;
	min = ARRAY_DATA(d, i);
	while (i < d->size)
	{
		if (max < ARRAY_DATA(d, i))
			max = ARRAY_DATA(d, i);
		if (min > ARRAY_DATA(d, i))
			min = ARRAY_DATA(d, i);
		i++;
	}
	return ((max - min) / 2 + min);
}

void
	pw_split(t_array *a, t_array *b)
{
	int i;
	int median;
	int fmedian;

	i = a->size;
	fmedian = pw_get_median(a);
	median = 0;
	while (a->size - 1 > b->size || pw_get_min(a) < pw_get_max(b))
	{
		median = pw_get_median(a);
		printf("%d >= %d\n", median, ARRAY_DATA(a, a->size - 1));
		if (median >= ARRAY_DATA(a, a->size - 1))
		{
			pw_push(a, b);
		}
		else
			pw_rev_rotate(a);
		pw_print_stack(a, b);
		i--;
	}
}

int
	main(int ac, char **av)
{
	int			i;
	t_array		a;
	t_array		b;
	int			temp;
	int			is_verbose;

	a = NEW_ARRAY(int);
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
			i++;
		}
		pw_print_stack(&a, &b);
		pw_split(&a, &b);
		pw_print_stack(&a, &b);
	}
}
