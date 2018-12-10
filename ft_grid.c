/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huszalew <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 14:32:49 by huszalew          #+#    #+#             */
/*   Updated: 2018/12/10 21:12:23 by huszalew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_free_grid(t_grid *grid)
{
	int		i;

	i = 0;
	while (i < grid->size)
	{
		ft_memdel((void **)&(grid->str[i]));
		i++;
	}
	ft_memdel((void **)&(grid->str));
	ft_memdel((void **)&grid);
}

void		ft_print_grid(t_grid *grid)
{
	int		i;

	i = 0;
	while (i < grid->size)
	{
		ft_putstr(grid->str[i]);
		ft_putchar('\n');
		i++;
	}
}

t_grid		*ft_new_grid(int size)
{
	t_grid	*grid;
	int		i;
	int		j;

	grid = (t_grid *)ft_memalloc(sizeof(t_grid));
	grid->size = size;
	grid->str = (char **)ft_memalloc(sizeof(char *) * size);
	i = 0;
	while (i < size)
	{
		grid->str[i] = ft_strnew(size);
		j = 0;
		while (j < size)
		{
			grid->str[i][j] = '.';
			j++;
		}
		i++;
	}
	return (grid);
}

void		ft_set_piece(t_tetris *tetri, t_grid *grid, t_point *point, char c)
{
	int		i;
	int		j;

	i = 0;
	while (i < tetri->width)
	{
		j = 0;
		while (j < tetri->height)
		{
			if (tetri->pos[j][i] == '#')
				grid->str[point->y + j][point->x + i] = c;
			j++;
		}
		i++;
	}
	ft_memdel((void **)&point);
}

int			ft_place(t_tetris *tetri, t_grid *grid, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	while (i < tetri->width)
	{
		j = 0;
		while (j < tetri->height)
		{
			if (tetri->pos[j][i] == '#' && grid->str[y + j][x + i] != '.')
				return (0);
			j++;
		}
		i++;
	}
	ft_set_piece(tetri, grid, ft_new_point(x, y), tetri->value);
	return (1);
}
