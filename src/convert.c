/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganase <simon.ganase@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 04:49:59 by sganase           #+#    #+#             */
/*   Updated: 2026/09/13 06:18:05 by sganase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/roseta.h"

void	stringtokeys(char **strs, struct s_ns ***keys, int *count)
{
	int	i;
	int	n;

	n = 0;
	while (strs[n])
		n++;
	*keys = malloc(sizeof(struct s_ns *) * (n / 2));
	i = 0;
	*count = 0;
	while (strs[i] && strs[i + 1])
	{
		(*keys)[*count] = malloc(sizeof(struct s_ns));
		if (ft_strlen(strs[i]) > 3)
			(*keys)[*count]->num = -(ft_strlen(strs[i]));
		else
			(*keys)[*count]->num = ft_atoi(strs[i]);
		(*keys)[*count]->str = strs[i + 1];
		(*count)++;
		i += 2;
	}
}

char	*findword(struct s_ns **keys, int count, int n)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (keys[i]->num == n)
			return (keys[i]->str);
		i++;
	}
	return (NULL);
}

int	readgroup(int *num, int pos, int size)
{
	int	val;
	int	i;

	val = 0;
	i = 0;
	while (i < size)
	{
		val = val * 10 + num[pos + i];
		i++;
	}
	return (val);
}

void	printnum(struct s_ns **keys, int count, int *num, int len)
{
	int	pos;
	int	val;

	pos = len % 3;
	if (pos == 0)
		pos = 3;
	val = readgroup(num, 0, pos);
	if (val)
		printgroup(keys, count, val, len - pos);
	while (num[pos] != -1)
	{
		val = readgroup(num, pos, 3);
		if (val)
			printgroup(keys, count, val, len - pos - 3);
		pos += 3;
	}
	ft_putstr("\n");
}

int	convert(char **strs, int *num)
{
	struct s_ns	**keys;
	int			count;
	int			len;

	stringtokeys(strs, &keys, &count);
	if (checkresolvable(keys, count, num))
	{
		freekeys(keys, count);
		return (-1);
	}
	len = 0;
	while (num[len] != -1)
		len++;
	if (len == 1 && num[0] == 0)
		ft_putword(findword(keys, count, 0), "\n");
	else
		printnum(keys, count, num, len);
	freekeys(keys, count);
	return (0);
}
