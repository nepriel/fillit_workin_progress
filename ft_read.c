/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huszalew <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 14:01:18 by huszalew          #+#    #+#             */
/*   Updated: 2018/12/10 21:40:21 by huszalew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_min_max(char *str, t_point *min, t_point *max)
{
	int			i;

	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if (i / 5 < min->y)
				min->y = i / 5;
			if (i / 5 > max->y)
				max->y = i / 5;
			if (i % 5 < min->x)
				min->x = i % 5;
			if (i % 5 > max->x)
				max->x = i % 5;
		}
		i++;
	}
}

t_tetris	*ft_get_piece(char *str, char value)
{
	t_point		*min;
	t_point		*max;
	char		**pos;
	int			i;
	t_tetris	*tetri;

	min = ft_new_point(3, 3);
	max = ft_new_point(0, 0);
	ft_min_max(str, min, max);
	pos = ft_memalloc(sizeof(char *) * (max->y - min->y + 1));
	i = 0;
	while (i < max->y - min->y + 1)
	{
		pos[i] = ft_strnew(max->x - min->x + 1);
		ft_strncpy(pos[i], str + (min->x) + (i + min->y) * 5, max->x - min->x + 1);
		i++;
	}
	tetri = ft_new_tetris(pos, max->x - min->x + 1, max->y - min->y + 1, value);
	ft_memdel((void **)&min);
	ft_memdel((void **)&max);
	return (tetri);
}

int			ft_count_connections(char *str)
{
	int			count;
	int			i;

	count = 0;
	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if ((i + 1) < 20 && str[i + 1] == '#')
				count++;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				count++;
			if ((i + 5) < 20 && str[i + 5] == '#')
				count++;
			if ((i - 5) >= 0 && str[i - 5] == '#')
				count++;
		}
		i++;
	}
	return (count == 6 || count == 8);
}

int			ft_check_counts(char *str, int count)
{
	int			i;
	int			blocs;

	i = 0;
	blocs = 0;
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (!(str[i] == '#' || str[i] == '.'))
				return (1);
			if (str[i] == '#' && ++blocs > 4)
				return (2);
		}
		else if (str[i] != '\n')
			return (3);
		i++;
	}
	if (count == 21 && str[20] != '\n')
		return (4);
	if (!ft_count_connections(str))
		return (5);
	return (0);
}

t_list		*ft_read_tetris(int fd)
{
	char		*buff;
	int			count;
	t_list		*list;
	t_tetris	*tetris;
	char		cur;

	buff = ft_strnew(21);
	list = NULL;
	cur = 'A';
	while ((count = read(fd, buff, 21)) >= 20)
	{
		if (ft_check_counts(buff, count) != 0
				|| (tetris = ft_get_piece(buff, cur++)) == NULL)
		{
			ft_memdel((void **)&buff);
			return (ft_free_lst(list));
		}
		ft_lstadd(&list, ft_lstnew(tetris, sizeof(t_tetris)));
		ft_memdel((void **)&tetris);
	}
	ft_memdel((void **)&buff);
	if (count != 0)
		return (ft_free_lst(list));
	ft_lstrev(&list);
	return (list);
}
