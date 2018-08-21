/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndzomb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 09:55:31 by mndzomb           #+#    #+#             */
/*   Updated: 2018/05/31 13:42:47 by mndzomb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*dst;
	unsigned char	*src;
	size_t			a;

	dst = (unsigned char *)s1;
	src = (unsigned char *)s2;
	a = 0;
	while (a < n)
	{
		if (dst[a] != src[a])
			return (dst[a] - src[a]);
		a++;
	}
	return (0);
}
