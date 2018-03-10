/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pw_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 13:58:58 by rnugroho          #+#    #+#             */
/*   Updated: 2018/03/10 04:42:52 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int
	pw_print_color(t_array *v, int i, int d)
{
	if (ARRAY_DATA(v, i) == pw_get_max(v))
		return (RED);
	if (ARRAY_DATA(v, i) == ARRAY_DATA(v, i + 1) + d ||
		ARRAY_DATA(v, i) == ARRAY_DATA(v, i - 1) - d ||
		ARRAY_DATA(v, i) == ARRAY_DATA(v, i + 1) ||
		ARRAY_DATA(v, i) == ARRAY_DATA(v, i - 1))
		return (GREEN);
	else
		return (EOC);
}

void
	pw_print_stack(t_array *a, t_array *b)
{
	int			i;
	int			max;
	static int	counter = 0;

	usleep(30000);
	system("clear");
	ft_printfln("Counter: %d", ++counter);
	max = (pw_get_max(a) > pw_get_max(b) ? pw_get_max(a) : pw_get_max(b));
	i = a->size + b->size + 1;
	while (i >= 0)
	{
		if (i < (int)a->size)
			ft_printf("%*w%3d %*Q%*Q%w\t", pw_print_color(a, i, 1),
			ARRAY_DATA(a, i), ARRAY_DATA(a, i), '-',
			max - ARRAY_DATA(a, i), ' ');
		else
			ft_printf("%*Q\t", max + 4, ' ');
		if (i < (int)b->size)
			ft_printfln("%*w%3d %*Q%*Q%w", pw_print_color(b, i, -1),
			ARRAY_DATA(b, i), ARRAY_DATA(b, i), '-',
			max - ARRAY_DATA(b, i), ' ');
		else
			ft_printf("\n");
		i--;
	}
}

void
	pw_get_arg(t_array *a, int i, int ac, char **av)
{
	int			num;

	*a = NEW_ARRAY(int);
	fta_resize(a, ac - i);
	while (i < ac)
	{
		num = ft_atoi(av[i]);
		fta_append(a, &num, 1);
		i++;
	}
}
