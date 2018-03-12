/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pw_helper_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 12:24:33 by rnugroho          #+#    #+#             */
/*   Updated: 2018/03/12 19:53:16 by rnugroho         ###   ########.fr       */
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
	pw_get_size(t_array *d, int limit)
{
	int		i;

	if (d->size == 0)
		return (0);
	i = 0;
	while (ARRAY_DATA(d, (int)d->size - 1 - i) <= limit &&
		ARRAY_DATA(d, (int)d->size - 1 - i) != 1)
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

void
	pw_merge(t_array *a, t_array *b)
{
	while (b->size > 0)
		pw_push(a, b, "pa");
}

/*
** opt[0] = -v for verbose
** opt[1] = -c for color
** opt[2] = -a for animation
** opt[3] = -t fot total
*/

int
	pw_getoptions(char **av, int **opt)
{
	int i;

	i = 1;
	(*opt)[0] = 0;
	(*opt)[1] = 0;
	(*opt)[2] = 0;
	(*opt)[3] = 0;
	while (av[i] && av[i][0] == '-')
	{
		if (ft_strcmp(av[i], "-v") == 0)
			(*opt)[0] = 1;
		if (ft_strcmp(av[i], "-c") == 0)
			(*opt)[1] = 1;
		if (ft_strcmp(av[i], "-a") == 0)
			(*opt)[2] = 1;
		if (ft_strcmp(av[i], "-t") == 0)
			(*opt)[3] = 1;
		if (!(*opt)[0] && !(*opt)[1] && !(*opt)[2] && !(*opt)[3])
			break ;
		i++;
	}
	return (i);
}
