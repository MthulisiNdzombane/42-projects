/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndzomb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 14:35:59 by mndzomb           #+#    #+#             */
/*   Updated: 2018/06/04 17:43:29 by mndzomb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*gs;
	char		*gd;
	size_t		a;

	a = 0;
	gd = (char *)dst;
	gs = (char *)src;
	while (a < n)
	{
		gd[a] = gs[a];
		a++;
	}
	return (dst);
}
