/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huszalew <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 10:40:22 by huszalew          #+#    #+#             */
/*   Updated: 2018/11/11 10:46:02 by huszalew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*dst;

	i = 0;
	dst = (unsigned char *)s;
	while (i < n)
	{
		if (dst[i] == (unsigned char)c)
			return ((void *)dst + i);
		i++;
	}
	return (NULL);
}
