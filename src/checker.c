/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 14:30:36 by rnugroho          #+#    #+#             */
/*   Updated: 2018/02/26 21:20:11 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void
	pf_print_stack(t_array *a, t_array *b)
{
	int i;

	if (a->size > b->size)
		i = a->size - 1;
	else
		i = b->size - 1;
	while (i >= 0)
	{
		if (i < (int)a->size)
			printf("%2d  ", ((int*)ARRAY_START(a))[i]);
		else
			printf("    ");
		if (i < (int)b->size)
			printf("%2d \n", ((int*)ARRAY_START(b))[i]);
		else
			printf("\n");
		i--;
	}
	printf("--- ---\n");
	printf("%2s  %2s\n", "a", "b");
	printf("--------------------------------------------------\n");
}

void
	pf_swap(t_array *d)
{
	int temp;

	if (d->size < 2)
		return ;
	temp = ((int*)ARRAY_START(d))[d->size-2];
	((int*)ARRAY_START(d))[d->size-2] = ((int*)ARRAY_START(d))[d->size-1];
	((int*)ARRAY_START(d))[d->size-1] = temp;
}

void
	pf_push(t_array *source, t_array *dest)
{
	int temp;

	if (source->size == 0)
		return ;
	temp = ((int*)ARRAY_START(source))[source->size-1];
	fta_popback(source, 1);
	fta_append(dest, &temp, 1);
}

void
	pf_rotate(t_array *d)
{
	int temp;

	if (d->size == 0)
		return ;
	temp = ((int*)ARRAY_START(d))[0];
	fta_popindex(d, 0, 1);
	fta_append(d, &temp, 1);
}

void
	pf_rev_rotate(t_array *d)
{
	int temp;

	if (d->size == 0)
		return ;
	temp = ((int*)ARRAY_START(d))[d->size-1];
	fta_popback(d, 1);
	fta_insert(d, &temp, 1, 0);
}

int
	pf_is_sorted(t_array *d)
{
	int	i;

	if (d->size == 0)
		return (1);
	i = d->size - 1;
	while (i > 0)
	{
		if (((int*)ARRAY_START(d))[i - 1] < ((int*)ARRAY_START(d))[i])
			return (0);
		i--;
	}
	return (1);
}

int
	main(int ac, char **av)
{
	int		i;
	char	*line;
	t_array		a;
	t_array		b;
	int		temp;
	int		is_verbose;

	a = NEW_ARRAY(int);
	b = NEW_ARRAY(int);
	i = 1;
	is_verbose = 0;
	if (ft_strcmp(av[1], "-v") == 0)
	{
		is_verbose = 1;
		i++;
	}
	if (ac > 1)
	{	
		while (i < ac)
		{
			temp = atoi(av[i]);
			fta_append(&a, &temp, 1);
			i++;
		}
		while (get_next_line(0, &line))
		{
			if (is_verbose)
				printf("Exec %s:\n", line);
			if (line[0] == 's')
			{
				if (line[1] == 'a')
					pf_swap(&a);
				else
					pf_swap(&b);
			}
			else if (line[0] == 'p')
			{
				if (line[1] == 'a')
					pf_push(&b, &a);
				else
					pf_push(&a, &b);
			}
			else if (line[0] == 'r' && ft_strlen(line) == 2)
			{
				if (line[1] == 'a')
					pf_rotate(&a);
				else if (line[1] == 'b')
					pf_rotate(&b);
				else
					{
						pf_rotate(&a);
						pf_rotate(&b);
					}
			}
			else if (line[0] == 'r' && ft_strlen(line) == 3)
			{
				if (line[2] == 'a')
					pf_rev_rotate(&a);
				else if (line[2] == 'b')
					pf_rev_rotate(&b);
				else
					{
						pf_rev_rotate(&a);
						pf_rev_rotate(&b);
					}

			}
			if (is_verbose)
				pf_print_stack(&a, &b);
		}
		if (b.size == 0 && pf_is_sorted(&a))
			printf("OK\n");
		else
			printf("KO\n");
	}	
}