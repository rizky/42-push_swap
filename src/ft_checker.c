/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 14:30:36 by rnugroho          #+#    #+#             */
/*   Updated: 2018/03/11 04:57:18 by rnugroho         ###   ########.fr       */
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
		&ch_swap, &ch_push, &ch_rotate, &ch_rev_rotate
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

void
	pw_check_line(t_array *a, t_array *b)
{
	int		i;
	char	*line;

	i = 0;
	while (get_next_line(0, &line))
	{
		pw_checker(line, a, b);
		if (g_isverbose)
		{
			pw_print_stack(a, b);
			ft_printfln("Exec %s:", line);
		}
		free(line);
		i++;
	}
	if (g_istotal)
		ft_printfln("Total steps: %i", i);
}

int
	main(int ac, char **av)
{
	int			i;
	t_array		a;
	t_array		b;

	b = NEW_ARRAY(int);
	if (ac > 1)
	{
		i = pw_getoptions(av);
		if (pw_get_arg(&a, i, ac, av) == -1)
			return (0);
		pw_check_line(&a, &b);
		if (b.size == 0 && pw_is_sorted(&a))
			ft_printfln("OK");
		else
			ft_printfln("KO");
		fta_clear(&a);
		fta_clear(&b);
	}
	return (0);
}
