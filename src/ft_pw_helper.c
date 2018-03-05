/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pw_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 12:24:33 by rnugroho          #+#    #+#             */
/*   Updated: 2018/03/05 03:38:53 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	pw_get_avg(t_array *d, int size)
{
	int		i;
	float	total;

	if (d->size == 0)
		return (0);
	i = d->size - 1;
	total = 0;
	while (i >= (int)d->size - size)
	{
		total += ARRAY_DATA(d, i);
		i--;
	}
	return ((int)(total / size + 0.5));
}

int
	pw_is_sorted(t_array *v)
{
	int	i;

	if (v->size == 0)
		return (1);
	i = v->size - 1;
	while (i > 0)
	{
		if (ARRAY_DATA(v, i - 1) < ARRAY_DATA(v, i))
			return (0);
		i--;
	}
	return (1);
}
