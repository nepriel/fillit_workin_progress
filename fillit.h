/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huszalew <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 11:15:19 by huszalew          #+#    #+#             */
/*   Updated: 2018/12/10 23:28:26 by huszalew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <sys/types.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_grid
{
	int			size;
	char		**str;
}				t_grid;

typedef struct	s_tetris
{
	char		**pos;
	int			width;
	int			height;
	char		value;
}				t_tetris;

t_list			*ft_read_tetris(int fd);
void			ft_print_grid(t_grid *grid);
void			ft_free_grid(t_grid *grid);
t_grid			*ft_new_grid(int size);
int				ft_place(t_tetris *tetri, t_grid *grid, int x, int y);
void			ft_set_piece(t_tetris *tetri, t_grid *grid, t_point *point,
								char c);
t_grid			*ft_solve(t_list *list);
t_point			*ft_new_point(int x, int y);
t_tetris		*ft_new_tetris(char **pos, int width, int height, char value);
void			ft_free_tetris(t_tetris *tetri);
t_list			*ft_free_lst(t_list *list);

#endif
