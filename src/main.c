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

int	main(int argc, char *argv[])
{
	char	**strs;
	int		*num;
	int		i;

	i = 0;
	if (parse(argc, argv, &strs, &num))
	{
		printf("Error");
		return (1);
	}
	while (strs[i])
	{
		printf("string %d : %s\n", i, strs[i]);
		i++;
	}
	i = 0;
	while (num[i] != -1)
	{
		printf("%d", num[i]);
		i++;
	}
	printf("main\n");
	convert(strs, num);
	return (0);
}
