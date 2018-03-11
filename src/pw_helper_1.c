/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pw_helper_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 12:24:33 by rnugroho          #+#    #+#             */
/*   Updated: 2018/03/12 00:22:11 by rnugroho         ###   ########.fr       */
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
	pw_get_avg(t_array *d)
{
	int		i;
	float	total;

	if (d->size == 0)
		return (0);
	i = d->size - 1;
	total = 0;
	while (i >= 0)
	{
		total += ARRAY_DATA(d, i);
		i--;
	}
	return ((int)(total / (int)d->size + 0.5));
}

int
	pw_check_dups(t_array *d, int num)
{
	size_t	i;

	if (d->size == 0)
		return (0);
	i = 0;
	while (i < d->size)
	{
		if (ARRAY_DATA(d, i) == num)
			return (1);
		i++;
	}
	return (0);
}

int
	pw_get_arg(t_array *a, int i, int ac, char **av)
{
	int			num;

	*a = NEW_ARRAY(int);
	fta_resize(a, ac - i);
	if (ac - i == 1)
	{
		ac = ft_wordcounter(av[i], ' ');
		av = ft_strsplit(av[i], ' ');
		i = 0;
	}
	while (i < ac)
	{
		num = ft_atoi(av[i]);
		if ((num == 0 && !ft_isdigit(av[i][0])
			&& av[i][1] != '0') || pw_check_dups(a, num))
		{
			ft_dprintf(2, "Error\n");
			return (-1);
		}
		fta_insert(a, &num, 1, 0);
		i++;
	}
	return (1);
}
