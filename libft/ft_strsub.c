/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndzomb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 12:26:13 by mndzomb           #+#    #+#             */
/*   Updated: 2018/06/04 15:16:18 by mndzomb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*newstr;
	size_t		i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(newstr = ft_strnew(len)))
		return (NULL);
	while (i < len)
	{
		newstr[i] = s[start];
		start++;
		i++;
	}
	return (newstr);
}
