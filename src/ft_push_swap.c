/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 18:49:14 by rnugroho          #+#    #+#             */
/*   Updated: 2018/03/10 23:49:35 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int
	main(int ac, char **av)
{
	int			i;
	t_array		a;
	t_array		b;

	if (ac > 1)
	{
		i = pw_getoptions(av);
		if (pw_get_arg(&a, i, ac, av) == -1)
		{
			ft_dprintf(2, "Error\n");
			return (0);
		}
		pw_get_arg(&b, i, ac, av);
		pw_sortdata(&b, 0, b.size - 1);
		pw_rank(&a, &b);
		if (a.size <= 5)
			ft_push_swap_simple(&a, &b);
		else
			ft_push_swap_segment(&a, &b);
	}
}
