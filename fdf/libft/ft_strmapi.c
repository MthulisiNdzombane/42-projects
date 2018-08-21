/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndzomb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 12:19:55 by mndzomb           #+#    #+#             */
/*   Updated: 2018/06/04 15:12:16 by mndzomb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned in, char))
{
	unsigned int	a;
	char			*string;

	a = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	string = (char *)malloc(sizeof(char) * (ft_strlen(s)) + 1);
	if (string == NULL)
		return (NULL);
	while (s[a] != '\0')
	{
		string[a] = f(a, s[a]);
		a++;
	}
	string[a] = '\0';
	return (string);
}
