/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndzomb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 14:38:32 by mndzomb           #+#    #+#             */
/*   Updated: 2018/06/04 17:10:21 by mndzomb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*string;
	size_t	len;

	string = (char *)s;
	len = ft_strlen(string);
	while (*(string + len) != c && len > 0)
		len--;
	if (*(string + len) == c)
	{
		return (string + len);
	}
	return (NULL);
}
