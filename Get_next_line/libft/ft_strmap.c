/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndzomb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 12:19:27 by mndzomb           #+#    #+#             */
/*   Updated: 2018/05/31 12:56:47 by mndzomb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		a;
	char	*string;

	if (!f || !s)
		return (NULL);
	a = 0;
	string = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (string)
	{
		while (s[a])
		{
			string[a] = f((char)s[a]);
			a++;
		}
		string[a] = '\0';
	}
	return (string);
}
