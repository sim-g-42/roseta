/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganase <simon.ganase@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 02:25:15 by sganase           #+#    #+#             */
/*   Updated: 2026/09/13 05:57:14 by sganase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/roseta.h"

void	freeall(char **strs, int *num)
{
	int	i;

	i = 0;
	while (strs && strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	free(num);
}

int	main(int argc, char *argv[])
{
	char	**strs;
	int		*num;
	int		st;

	strs = NULL;
	num = NULL;
	st = parse(argc, argv, &strs, &num);
	if (st != 0)
	{
		if (st == -2)
			ft_putstr("Dict Error\n");
		else
			ft_putstr("Error\n");
		freeall(strs, num);
		return (1);
	}
	if (convert(strs, num))
		ft_putstr("Dict Error\n");
	freeall(strs, num);
	return (0);
}
