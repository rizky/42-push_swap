/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pw_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 13:58:58 by rnugroho          #+#    #+#             */
/*   Updated: 2018/05/13 15:54:26 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int
	pw_print_color(t_array *v, int i, int d, int iscolor)
{
	if (!iscolor)
		return (EOC);
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

static void
	pw_print_delay(void)
{
	system("sleep 0.05");
	ft_printf("%0.0v");
}

void
	pw_print_stack(t_array *a, t_array *b, t_array *opt)
{
	int			i;
	int			max;

	if (ARRAY_DATA(opt, OPT_A))
		pw_print_delay();
	max = (pw_get_max(a) > pw_get_max(b) ? pw_get_max(a) : pw_get_max(b));
	i = a->size + b->size + 1;
	while (i >= 0)
	{
		if (i < (int)a->size)
			ft_printf("%*w%3d %*Q%*Q%w\t",
			pw_print_color(a, i, 1, ARRAY_DATA(opt, OPT_C)),
			ARRAY_DATA(a, i), ABS(ARRAY_DATA(a, i)), '-',
			max - ABS(ARRAY_DATA(a, i)), ' ');
		else
			ft_printf("%*Q\t", max + 4, ' ');
		if (i < (int)b->size)
			ft_printfln("%*w%3d %*Q%*Q%w",
			pw_print_color(b, i, -1, ARRAY_DATA(opt, OPT_C)),
			ARRAY_DATA(b, i), ABS(ARRAY_DATA(b, i)), '-',
			max - ABS(ARRAY_DATA(b, i)), ' ');
		else
			ft_printfln("%*Q\t", max + 4, ' ');
		i--;
	}
}
