/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huszalew <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 21:47:58 by huszalew          #+#    #+#             */
/*   Updated: 2018/12/10 21:56:09 by huszalew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_solve_grid(t_grid *grid, t_list *list)
{
	int			x;
	int			y;
	t_tetris	*tetri;

	if (list == NULL)
		return (1);
	y = 0;
	tetri = (t_tetris *)(list->content);
	while (y < grid->size - tetri->height + 1)
	{
		x = 0;
		while (x < grid->size - tetri->width + 1)
		{
			if (ft_place(tetri, grid, x, y))
			{
				if (ft_solve_grid(grid, list->next))
					return (1);
				else
					ft_set_piece(tetri, grid, ft_new_point(x, y), '.');
			}
			x++;
		}
		y++;
	}
	return (0);
}

int		high_sqrt(int n)
{
	int size;

	size = 2;
	while (size * size < n)
		size++;
	return (size);
}

t_grid		*ft_solve(t_list *list)
{
	t_grid	*grid;
	int		size;

	size = high_sqrt(ft_lstcount(list) * 4);
	grid = ft_new_grid(size);
	while (!ft_solve_grid(grid, list))
	{
		size++;
		ft_free_grid(grid);
		grid = ft_new_grid(size);
	}
	return (grid);
}
