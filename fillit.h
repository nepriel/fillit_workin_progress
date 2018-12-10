/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huszalew <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 11:15:19 by huszalew          #+#    #+#             */
/*   Updated: 2018/12/10 15:20:19 by huszalew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <unistd.h>
# include <sys/types.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct	s_point
{
	size_t		x;
	size_t		y;
}				t_point;

typedef struct	s_grid
{
	size_t		size;
	char		**str;
}				t_grid;

typedef struct	s_tetris
{
	char		**pos;
	char		value;
	size_t		height;
	size_t		width;
}				t_tetris;

t_list			*ft_read_tetris(int fd);
t_tetris		*ft_new_tetris(char **pos, char value, int width, int height);
t_point			*ft_new_point(int x, int y);
t_list			*ft_free_lst(t_list *list);
void		ft_free_grid(t_grid *grid);
void			ft_print_grid(t_grid *grid);

#endif
