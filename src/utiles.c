/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganase <simon.ganase@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 02:34:43 by sganase           #+#    #+#             */
/*   Updated: 2026/09/13 05:59:07 by sganase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/roseta.h"

int	ft_atoi(char *str)
{
	int	n;
	int	i;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
		{
			n += str[i] - 48;
			if (str[i + 1])
				n *= 10;
		}
		i++;
	}
	return (n);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	*ft_atonum(char *str)
{
	int	*num;
	int	i;
	int	i2;

	i2 = 0;
	i = 0;
	num = malloc(sizeof(int) * (ft_strlen(str) + 200));
	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
		{
			num[i2] = str[i] - 48;
			i2++;
		}
		i++;
	}
	num[i2] = -1;
	return (num);
}
