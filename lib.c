/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:55:16 by ksenaida          #+#    #+#             */
/*   Updated: 2019/11/12 11:43:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ttt.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dd;
	unsigned char	*ss;
	size_t			i;

	i = 0;
	dd = (unsigned char*)dst;
	ss = (unsigned char*)src;
	if (!dst && !src)
		return (0);
	while (i < n)
	{
		dd[i] = ss[i];
		i++;
	}
	return (dd);
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strnew(size_t size)
{
	char	*res;
	size_t	i;

	i = 0;
	if (size + 1 < size)
		return (0);
	res = (char*)malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	while (i < size)
	{
		res[i] = '\0';
		i++;
	}
	res[i] = '\0';
	return (res);
}
