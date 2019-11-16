/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_tet.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 16:34:01 by ksenaida          #+#    #+#             */
/*   Updated: 2019/11/16 16:47:24 by ksenaida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		connect_check(char *str)
{
	int block;
	int i;

	block = 0;
	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if ((i + 1) < 20 && str[i + 1] == '#')
				block++;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				block++;
			if ((i + 5) < 20 && str[i + 5] == '#')
				block++;
			if ((i - 5) >= 0 && str[i - 5] == '#')
				block++;
		}
		i++;
	}
	return (block == 6 || block == 8);
}

int		checks(char *str, int count)
{
	int i;
	int blocs;

	blocs = 0;
	i = 0;
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (!(str[i] == '#' || str[i] == '.'))
			{
				//printf("first\n");
				return (1);
			}
			if (str[i] == '#' && ++blocs > 4)
				return (1);
		}
		else if (str[i] != '\n' && count == 20)
		{
			//printf("third\n");
			return (1);
		}
		i++;
	}
	if (str[20] != '\n' && count == 21)
	{
		//printf("str[20] != '\\n' && count == 21 error\n");
		return (1);
	}
	if (!connect_check(str))
	{
		//printf("connect_check\n");
		return (1);
	}
	return (0);
}
