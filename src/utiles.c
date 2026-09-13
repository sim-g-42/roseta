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
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		n = n * 10 + (str[i] - '0');
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

void	ft_putstr(char *str)
{
	if (!str)
		return ;
	write(1, str, ft_strlen(str));
}

void	ft_putword(char *word, char *after)
{
	ft_putstr(word);
	ft_putstr(after);
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
		if (str[i] < '0' || str[i] > '9')
		{
			num[0] = -1;
			return (num);
		}
		num[i2] = str[i] - '0';
		i2++;
		i++;
	}
	num[i2] = -1;
	return (num);
}
