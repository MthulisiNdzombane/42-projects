/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndzomb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 14:36:13 by mndzomb           #+#    #+#             */
/*   Updated: 2018/06/04 17:45:17 by mndzomb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			a;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	a = 0;
	while (a < n)
	{
		d[a] = s[a];
		if (s[a] == (unsigned char)c)
			return (&(d[a + 1]));
		a++;
	}
	return (NULL);
}
