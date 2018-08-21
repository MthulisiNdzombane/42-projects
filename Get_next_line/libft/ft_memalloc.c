/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndzomb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 12:06:21 by mndzomb           #+#    #+#             */
/*   Updated: 2018/05/31 15:54:05 by mndzomb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (size));
	if (!buffer)
		return (NULL);
	ft_bzero(buffer, size);
	return ((void *)buffer);
}
