/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 17:22:48 by nathan            #+#    #+#             */
/*   Updated: 2020/06/28 17:38:32 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** checks for white-space  characters.   In  the  "C"  and  "POSIX"
** locales,  these  are:  space,  form-feed ('\f'), newline ('\n'),
** carriage return ('\r'), horizontal tab ('\t'), and vertical  tab
** ('\v').
*/

int ft_isspace(int c)
{
	return (c == '\t' || c == '\n' ||
	    c == '\v' || c == '\f' || c == '\r' || c == ' ' ? 1 : 0);
}