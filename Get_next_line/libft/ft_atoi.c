/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndzomb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 14:39:45 by mndzomb           #+#    #+#             */
/*   Updated: 2018/05/29 18:48:31 by mndzomb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int result;
	int sign;
	int a;
	int lng;

	result = 0;
	sign = 1;
	lng = 0;
	a = 0;
	while (str[a] == '\t' || (str[a] == '\f') || (str[a] == '\v') ||
	(str[a] == '\n') || (str[a] == ' ') || (str[a] == '\r'))
		a++;
	if (str[a] == '-')
		sign = -1;
	if (str[a] == '-' || str[a] == '+')
		a++;
	while (str[a] && ft_isdigit(str[a]))
	{
		result = result * 10 + str[a] - '0';
		a++;
		lng++;
	}
	if (lng > 19)
		return ((sign == -1) ? 0 : -1);
	return (sign * result);
}
