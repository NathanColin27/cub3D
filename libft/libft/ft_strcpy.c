/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 18:05:50 by nathan            #+#    #+#             */
/*   Updated: 2020/06/28 18:13:22 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**     The  strcpy()  function  copies the string pointed to by src, including
**     the terminating null byte ('\0'), to the buffer  pointed  to  by  dest.
**     The  strings  may  not overlap, and the destination string dest must be
**     large enough to receive the copy.  Beware  of  buffer  overruns!   (See
**     BUGS.)
*/

char    *ft_strcpy (char *dest, const char *src)
{
  return (ft_memcpy (dest, src, ft_strlen(src) + 1));
}