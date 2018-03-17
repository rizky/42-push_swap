/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pw_helper_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 12:24:33 by rnugroho          #+#    #+#             */
/*   Updated: 2018/03/17 17:02:03 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	pw_is_duplicate(t_array *d, int num)
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
	pw_isint(char *str)
{
	long int	value;
	int			sign;

	value = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
			|| *str == '\r' || *str == '\v')
		str++;
	if (*str == '-')
		sign = -1;
	else
		sign = 1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		value = value * 10 + (*str - '0');
		str++;
	}
	if ((value * sign) <= 2147483647 && (value * sign) >= -2147483648)
		return (1);
	else
		return (0);
}

int
	pw_get_arg(t_array *a, int i, int ac, char **av)
{
	int		num;
	int		is_single;

	is_single = 0;
	if (ac - i == 1)
	{
		ac = ft_wordcounter(av[i], ' ');
		av = ft_strsplit(av[i], ' ');
		i = 0;
		is_single = 1;
	}
	while (i < ac)
	{
		num = ft_atoi(av[i]);
		if ((num == 0 && !ft_isdigit(av[i][0]) && av[i][1] != '0') ||
			pw_is_duplicate(a, num) || !pw_isint(av[i++]))
		{
			ft_dprintf(2, "Error\n");
			(is_single ? ft_strtab_free(av) : 0);
			return (-1);
		}
		fta_insert(a, &num, 1, 0);
	}
	(is_single ? ft_strtab_free(av) : 0);
	return (1);
}
