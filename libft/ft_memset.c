/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huszalew <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 09:30:28 by huszalew          #+#    #+#             */
/*   Updated: 2018/11/11 10:40:05 by huszalew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	unsigned char	*dst;

	i = 0;
	dst = (unsigned char *)b;
	while (i < len)
		dst[i++] = (unsigned char)c;
	b = (void *)dst;
	return (b);
}
