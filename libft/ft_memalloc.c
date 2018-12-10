/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huszalew <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 15:41:55 by huszalew          #+#    #+#             */
/*   Updated: 2018/12/10 22:23:31 by huszalew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*storage_area;

	storage_area = malloc(size);
	if (storage_area == NULL)
		return (NULL);
	ft_bzero(storage_area, size);
	return (storage_area);
}
