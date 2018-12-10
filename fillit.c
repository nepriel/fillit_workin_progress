/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huszalew <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 14:01:13 by huszalew          #+#    #+#             */
/*   Updated: 2018/12/10 15:20:43 by huszalew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_list	*list;
	t_grid	*grid;

	if (argc != 2)
	{
		write(1, "usage: ./fillit <file>\n", 23);
		return (0);
	}
	if (!(list = ft_read_tetris(open(argv[1], O_RDONLY))))
	{
		write(1, "error\n", 6);
		return (0);
	}
	//grid = solve(list);
	ft_print_grid(grid);
	ft_free_grid(grid);
	ft_free_lst(list);
	return (0);
}
