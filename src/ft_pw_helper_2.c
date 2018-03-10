/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pw_helper_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 12:24:33 by rnugroho          #+#    #+#             */
/*   Updated: 2018/03/10 20:55:21 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int
	pw_get_size(t_array *d, int limit)
{
	int		i;

	if (d->size == 0)
		return (0);
	i = 0;
	while (ARRAY_DATA(d, (int)d->size - 1 - i) <= limit)
		i++;
	return (i);
}

int
	pw_get_avg_limit(t_array *d, int limit)
{
	int		i;
	float	total;

	if (d->size == 0)
		return (0);
	i = 0;
	total = 0;
	while (ARRAY_DATA(d, (int)d->size - 1 - i) <= limit &&
		ARRAY_DATA(d, (int)d->size - 1 - i) != 1)
	{
		total += ARRAY_DATA(d, (int)d->size - 1 - i);
		i++;
	}
	return ((int)(total / i + 0.5));
}

int
	pw_get_arg(t_array *a, int i, int ac, char **av)
{
	int			num;

	*a = NEW_ARRAY(int);
	fta_resize(a, ac - i);
	while (i < ac)
	{
		num = ft_atoi(av[i]);
		if (num == 0 && !ft_isdigit(av[i][0])
			&& av[i][1] != '0')
			return (-1);
		fta_append(a, &num, 1);
		i++;
	}
	return (1);
}
