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

void	stringtokeys(char **strs, struct s_ns **keys, int *count)
{
	int	i;

	i = 0;
	*count = 0;
	while (strs[i] && strs[i + 1])
	{
		keys[*count] = malloc(sizeof(struct s_ns));
		keys[*count]->num = ft_atoi(strs[i]);
		keys[*count]->str = strs[i + 1];
		(*count)++;
		i += 2;
	}
}

void	convert(char **strs, int *num)
{
	struct s_ns	*keys[100];
	int			count;
	int			i;

	stringtokeys(strs, keys, &count);
	i = 0;
	while (i < count)
	{
		printf("num %d : %d -> %s\n", i, keys[i]->num, keys[i]->str);
		i++;
	}
}
