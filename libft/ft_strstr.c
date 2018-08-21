/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndzomb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 13:11:20 by mndzomb           #+#    #+#             */
/*   Updated: 2018/06/10 13:13:54 by mndzomb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	a;
	size_t	b;

	if (needle[0] == '\0')
		return ((char *)haystack);
	a = 0;
	while (haystack[a] != '\0')
	{
		b = 0;
		while (needle[b] != '\0')
		{
			if (haystack[a + b] != needle[b])
				break ;
			b++;
		}
		if (needle[b] == '\0')
			return ((char *)(haystack + a));
		a++;
	}
	return (0);
}
