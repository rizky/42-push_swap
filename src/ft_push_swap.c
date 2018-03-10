/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 18:49:14 by rnugroho          #+#    #+#             */
/*   Updated: 2018/03/10 20:35:05 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int
	main(int ac, char **av)
{
	int			i;
	t_array		a;
	t_array		b;
	int			isverbose;
	int			iscolor;

	if (ac > 1)
	{
		i = pw_getoptions(av, &isverbose, &iscolor);
		pw_get_arg(&a, i, ac, av);
		pw_get_arg(&b, i, ac, av);
		if (a.size <= 5)
			ft_push_swap_simple(&a, &b, isverbose, iscolor);
		else
			ft_push_swap_backtrack(&a, &b, isverbose, iscolor);
	}
}
