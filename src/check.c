/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganase <simon.ganase@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 02:51:25 by sganase           #+#    #+#             */
/*   Updated: 2026/09/13 04:43:03 by sganase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/roseta.h"

int	checkgroup(struct s_ns **keys, int count, int val, int rem)
{
	int	r;

	if (val / 100 && !findword(keys, count, val / 100))
		return (-1);
	r = val % 100;
	if (r >= 10 && r < 20)
	{
		if (!findword(keys, count, r))
			return (-1);
	}
	else
	{
		if (r / 10 && !findword(keys, count, (r / 10) * 10))
			return (-1);
		if (r % 10 && !findword(keys, count, r % 10))
			return (-1);
	}
	if (rem > 0 && !findword(keys, count, -(rem + 1)))
		return (-1);
	return (0);
}

int	checkresolvable(struct s_ns **keys, int count, int *num)
{
	int	len;
	int	pos;
	int	val;

	len = 0;
	while (num[len] != -1)
		len++;
	if (len == 1 && num[0] == 0)
		return (-(findword(keys, count, 0) == NULL));
	pos = len % 3;
	if (pos == 0)
		pos = 3;
	val = readgroup(num, 0, pos);
	if (val && checkgroup(keys, count, val, len - pos))
		return (-1);
	while (num[pos] != -1)
	{
		val = readgroup(num, pos, 3);
		if (val && checkgroup(keys, count, val, len - pos - 3))
			return (-1);
		pos += 3;
	}
	return (0);
}

void	printgroup(struct s_ns **keys, int count, int val, int rem)
{
	int	r;

	if (val / 100)
		ft_putword(findword(keys, count, val / 100), " hundred ");
	r = val % 100;
	if (r >= 10 && r < 20)
		ft_putword(findword(keys, count, r), " ");
	else
	{
		if (r / 10)
			ft_putword(findword(keys, count, (r / 10) * 10), " ");
		if (r % 10)
			ft_putword(findword(keys, count, r % 10), " ");
	}
	if (rem > 0)
		ft_putword(findword(keys, count, -(rem + 1)), " ");
}

void	freekeys(struct s_ns **keys, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(keys[i]);
		i++;
	}
	free(keys);
}
