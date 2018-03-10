/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 14:30:36 by rnugroho          #+#    #+#             */
/*   Updated: 2018/03/10 23:55:40 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	pw_checker(char *line, t_array *a, t_array *b)
{
	int			i;
	int			index;
	const char	*c = "spr";
	const void	*op[] = {
		&pw_swap, &pw_push, &pw_rotate, &pw_rev_rotate
	};

	i = 0;
	index = 1;
	while (c[i] != '\0' && line[0] != c[i])
		i++;
	if (ft_strlen(line) == 3)
	{
		i = 3;
		index++;
	}
	if (line[index] == 'a' || line[index] == 'r')
		(((void (*)())op[i])(a, b));
	if (line[index] == 'b' || line[index] == 'r')
		(((void (*)())op[i])(b, a));
}

int
	main(int ac, char **av)
{
	int			i;
	char		*line;
	t_array		a;
	t_array		b;

	a = NEW_ARRAY(int);
	b = NEW_ARRAY(int);
	if (ac > 1)
	{
		i = pw_getoptions(av);
		if (pw_get_arg(&a, i, ac, av) == -1)
		{
			ft_dprintf(2, "Error\n");
			return (0);
		}
		i = 0;
		while (get_next_line(0, &line))
		{
			pw_checker(line, &a, &b);
			if (g_isverbose)
			{
				pw_print_stack(&a, &b);
				ft_printfln("Exec %s:", line);
			}
			free(line);
			i++;
		}
		if (b.size == 0 && pw_is_sorted(&a))
			ft_printfln("OK");
		else
			ft_printfln("KO");
		if (g_istotal)
			ft_printfln("Total steps: %i", i);
		fta_clear(&a);
		fta_clear(&b);
	}
	return (0);
}
