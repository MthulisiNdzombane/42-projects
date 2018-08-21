/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndzomb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 14:35:43 by mndzomb           #+#    #+#             */
/*   Updated: 2018/06/04 17:59:13 by mndzomb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*string;
	size_t	index;

	string = (char *)s;
	index = 0;
	while (index < n)
	{
		string[index] = '\0';
		index++;
	}
}
