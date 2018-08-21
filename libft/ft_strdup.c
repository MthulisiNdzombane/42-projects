/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndzomb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 14:10:29 by mndzomb           #+#    #+#             */
/*   Updated: 2018/05/31 14:10:33 by mndzomb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;
	size_t	a;

	a = 0;
	copy = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (copy)
	{
		while (s1[a] != '\0')
		{
			copy[a] = s1[a];
			a++;
		}
		copy[a] = '\0';
	}
	return (copy);
}
