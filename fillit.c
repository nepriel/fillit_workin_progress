/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huszalew <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 14:01:13 by huszalew          #+#    #+#             */
/*   Updated: 2018/12/10 21:58:41 by huszalew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_list	*list;
	t_grid	*grid;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit <file>\n");
		return (1);
	}
	if (!(list = ft_read_tetris(open(argv[1], O_RDONLY))))
	{
		ft_putstr("error\n");
		return (1);
	}
	grid = ft_solve(list);
	ft_print_grid(grid);
	ft_free_grid(grid);
	ft_free_lst(list);
	return (0);
}
