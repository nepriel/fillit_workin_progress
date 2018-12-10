/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetrimino.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huszalew <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 14:01:31 by huszalew          #+#    #+#             */
/*   Updated: 2018/12/10 14:26:22 by huszalew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_free_tetris(t_tetris *tetris)
{
	int		y;

	y = 0;
	while (y < tetris->height)
	{
		ft_memdel((void **)(&(tetris->pos[y])));
		y++;
	}
	ft_memdel((void **)(&(tetris->pos)));
	ft_memdel((void **)&tetris);
}

t_list		*ft_free_lst(t_list *list)
{
	t_tetris	*tetris;
	t_list		*next;

	while (list)
	{
		tetris = (t_tetris *)list->content;
		next = list->next;
		ft_free_tetris(tetris);
		ft_memdel((void **)&list);
		list = next;
	}
	return (NULL);
}

t_tetris	*ft_new_tetris(char **pos, char value, int width, int height)
{
	t_tetris	*tetris;

	tetris = ft_memalloc(sizeof(t_tetris));
	tetris->pos = pos;
	tetris->value = value;
	tetris->width = width;
	tetris->height = height;
	return (tetris);
}

t_point		*ft_new_point(int x, int y)
{
	t_point		*point;

	point = ft_memalloc(sizeof(t_point));
	point->x = x;
	point->y = y;
	return (point);
}
