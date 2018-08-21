/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndzomb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 11:13:13 by mndzomb           #+#    #+#             */
/*   Updated: 2018/06/04 17:31:19 by mndzomb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	a;
	size_t	b;

	if (needle[0] == '\0')
		return ((char *)haystack);
	a = 0;
	while (haystack[a] != '\0' && a < len)
	{
		b = 0;
		while (needle[b] != '\0')
		{
			if (a + b >= len || haystack[a + b] != needle[b])
				break ;
			b++;
		}
		if (needle[b] == '\0')
			return ((char *)(haystack + a));
		a++;
	}
	return (0);
}
