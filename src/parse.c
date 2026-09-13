/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganase <simon.ganase@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 02:51:25 by sganase           #+#    #+#             */
/*   Updated: 2026/09/13 04:43:03 by sganase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/roseta.h"

char	**readdict(char *dict)
{
	char	**strs;
	char	*sep;
	char	*c;
	int		sz;

	sep = malloc(sizeof(char) * 4);
	sep = " :\n";
	c = (char *)malloc(sizeof(char) * 691);
	c[read(open(dict, O_RDONLY), c, 691)] = '\0';
	strs = ft_split(c, sep);
	return (strs);
}

int	getarg(int argc, char *argv[], int **num, char **dict)
{
	if (argc < 2 || argc > 3)
	{
		return (-1);
	}
	if (argc == 2)
		*num = ft_atonum(argv[1]);
	else if (argc == 3)
	{
		*num = ft_atonum(argv[2]);
		*dict = malloc(sizeof(char) * (ft_strlen(argv[1]) + 1));
		*dict = argv[1];
		return (0);
	}
	*dict = malloc(sizeof(char) * (ft_strlen("numbers.dict")));
	*dict = "numbers.dict";
	return (0);
}

int	parse(int argc, char *argv[], char ***strs, int **num)
{
	char	*dict;

	if (getarg(argc, argv, num, &dict) == -1)
		return (-1);
	*strs = readdict(dict);
	return (0);
}
