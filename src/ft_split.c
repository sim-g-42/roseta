/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganase <simon.ganase@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 00:37:28 by sganase           #+#    #+#             */
/*   Updated: 2026/09/13 02:36:19 by sganase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/roseta.h"

int	sepcount(char *str, char *sep)
{
	int	i;
	int	i2;
	int	i3;
	int	i4;

	i = 0;
	i4 = 0;
	i2 = 0;
	while (str[i2])
	{
		i3 = 0;
		while (sep[i3])
		{
			if (str[i2] == sep[i3] && str[i2 - 1] != sep[0])
			{
				str[i2] = sep[0];
				i++;
			}
			i3++;
		}
		i2++;
	}
	return (i);
}

int	counttosep(char *str, char *sep)
{
	int	i2;
	int	i3;

	i2 = 0;
	while (str[i2])
	{
		i3 = 0;
		while (sep[i3])
		{
			if (str[i2] == sep[i3])
				return (i2);
			i3++;
		}
		i2++;
	}
	return (i2);
}

void	ft_split2(char *str, char *sep, char **strs, int i[5])
{
	i[1] = counttosep(str, sep);
	if (!i[1])
	{
		str++;
		return (ft_split2(str, sep, strs, i));
	}
	strs[i[0]] = malloc(sizeof(char) * (i[1] + 1));
	i[2] = 0;
	while (i[2] < i[1])
	{
		strs[i[0]][i[2]] = str[0];
		i[2]++;
		str++;
	}
	i[0]++;
	if (i[0] >= i[3])
		return ;
	ft_split2(str, sep, strs, i);
}

char	**ft_split(char *str, char *sep)
{
	char	**strs;
	int		i[5];

	i[0] = 0;
	i[3] = sepcount(str, sep);
	strs = malloc(sizeof(strs) * (i[3] + 2));
	strs[i[3] + 2] = NULL;
	ft_split2(str, sep, strs, i);
	return (strs);
}
