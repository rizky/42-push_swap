/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 14:30:36 by rnugroho          #+#    #+#             */
/*   Updated: 2018/03/12 20:15:24 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int
	pw_is_line_valid(char *line)
{
	if (ft_strnequ(line, "sa", 3))
		return (1);
	else if (ft_strnequ(line, "sb", 3))
		return (1);
	else if (ft_strnequ(line, "pa", 3))
		return (1);
	else if (ft_strnequ(line, "pb", 3))
		return (1);
	else if (ft_strnequ(line, "ra", 3))
		return (1);
	else if (ft_strnequ(line, "rb", 3))
		return (1);
	else if (ft_strnequ(line, "rr", 3))
		return (1);
	else if (ft_strnequ(line, "rra", 4))
		return (1);
	else if (ft_strnequ(line, "rrb", 4))
		return (1);
	else if (ft_strnequ(line, "rrr", 4))
		return (1);
	else
		return (0);
}

void
	pw_checker(char *line, t_array *a, t_array *b)
{
	int			i;
	int			index;
	const char	*c = "spr";
	const void	*op[] = {&ch_swap, &ch_push, &ch_rotate, &ch_rev_rotate};

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

/*
** opt[0] = -v for verbose
** opt[1] = -c for color
** opt[2] = -a for animation
** opt[3] = -t fot total
*/

static int
	pw_check_line(t_array *a, t_array *b, int *opt)
{
	int		i;
	char	*line;

	i = 0;
	while (get_next_line(0, &line))
	{
		if (!pw_is_line_valid(line))
		{
			ft_dprintf(2, "Error\n");
			free(line);
			return (-1);
		}
		pw_checker(line, a, b);
		if (opt[0])
		{
			pw_print_stack(a, b, opt);
			ft_printfln("Exec %s:", line);
		}
		free(line);
		i++;
	}
	if (opt[3])
		ft_printfln("Total steps: %i", i);
	return (0);
}

int
	main(int ac, char **av)
{
	t_array		a;
	t_array		b;
	int			*opt;

	a = NEW_ARRAY(int);
	b = NEW_ARRAY(int);
	opt = (int*)malloc(sizeof(int) * 4);
	if (ac > 1)
	{
		if (pw_get_arg(&a, pw_getoptions(av, &opt), ac, av) != -1)
		{
			if (pw_check_line(&a, &b, opt) != -1)
			{
				if (b.size == 0 && pw_is_sorted(&a))
					ft_printfln("OK");
				else
					ft_printfln("KO");
			}
		}
		fta_clear(&a);
		fta_clear(&b);
		free(opt);
	}
	return (0);
}
