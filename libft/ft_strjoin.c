/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndzomb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 12:27:22 by mndzomb           #+#    #+#             */
/*   Updated: 2018/06/04 15:27:33 by mndzomb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buffer;

	if (s1 && s2)
	{
		buffer = ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (!buffer)
			return (NULL);
		ft_strcpy(buffer, s1);
		ft_strcat(buffer, s2);
		return (buffer);
	}
	return (NULL);
}
