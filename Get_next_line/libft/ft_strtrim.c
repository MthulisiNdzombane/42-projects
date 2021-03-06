/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndzomb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 12:28:28 by mndzomb           #+#    #+#             */
/*   Updated: 2018/06/04 19:01:35 by mndzomb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*newstr;
	size_t			len;
	unsigned int	start;

	start = 0;
	if (!s)
		return (NULL);
	while (s[start] &&
				(s[start] == ' ' || s[start] == '\t' || s[start] == '\n'))
		start++;
	if (s[start] == '\0')
		return (ft_strdup(s + start));
	len = ft_strlen(s) - 1;
	while (s[len] && (s[len] == ' ' || s[len] == '\t' || s[len] == '\n'))
		len--;
	if (!(newstr = ft_strnew(len)))
		return (NULL);
	newstr = ft_strsub(s, start, len - start + 1);
	return (newstr);
}
