/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:17:53 by ncolin            #+#    #+#             */
/*   Updated: 2019/10/24 18:24:15 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Adds the element new at the beginning of the list
*/

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (!new || !alst)
		return ;
	if (*alst)
		new->next = *alst;
	*alst = new;
}
