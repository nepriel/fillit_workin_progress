/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huszalew <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 16:36:08 by huszalew          #+#    #+#             */
/*   Updated: 2018/11/18 15:50:27 by huszalew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	int		len;

	if (!s)
		return ;
	len = ft_strlen(s);
	while (len >= 0)
	{
		s[len] = '\0';
		len--;
	}
}
