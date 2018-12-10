/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huszalew <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 12:54:02 by huszalew          #+#    #+#             */
/*   Updated: 2018/11/19 13:59:18 by huszalew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*to_erase;
	t_list	*next_link;

	to_erase = *alst;
	while (to_erase)
	{
		next_link = to_erase->next;
		del(to_erase->content, to_erase->content_size);
		free(to_erase);
		to_erase = next_link;
	}
	*alst = NULL;
}
