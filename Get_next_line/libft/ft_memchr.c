/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndzomb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 14:36:53 by mndzomb           #+#    #+#             */
/*   Updated: 2018/05/31 13:29:46 by mndzomb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			a;
	unsigned char	*src;
	unsigned char	chr;

	a = 0;
	src = (unsigned char*)s;
	chr = (unsigned char)c;
	while (a < n)
	{
		if (src[a] == chr)
		{
			return (&src[a]);
		}
		a++;
	}
	return (NULL);
}
