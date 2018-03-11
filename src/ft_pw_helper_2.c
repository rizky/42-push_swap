/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pw_helper_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 12:24:33 by rnugroho          #+#    #+#             */
/*   Updated: 2018/03/11 15:38:57 by rnugroho         ###   ########.fr       */
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

int
	pw_getoptions(char **av)
{
	int i;

	i = 1;
	g_isverbose = 0;
	g_iscolor = 0;
	while (av[i] && av[i][0] == '-')
	{
		if (ft_strcmp(av[i], "-t") == 0)
			g_istotal = 1;
		if (ft_strcmp(av[i], "-v") == 0)
			g_isverbose = 1;
		if (ft_strcmp(av[i], "-c") == 0)
			g_iscolor = 1;
		if (ft_strcmp(av[i], "-a") == 0)
		{
			g_isanimated = 1;
			i++;
			if (av[i] != '\0')
				g_delay = ft_atoi(av[i]);
		}
		if (!g_istotal && !g_isverbose && !g_iscolor && !g_isanimated)
			break ;
		i++;
	}
	return (i);
}