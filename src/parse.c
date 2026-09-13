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
	char	**lines;
	char	*c;
	int		fd;
	int		n;

	fd = open(dict, O_RDONLY);
	if (fd == -1)
		return (NULL);
	c = malloc(65536);
	n = read(fd, c, 65535);
	if (n < 0)
		n = 0;
	c[n] = '\0';
	close(fd);
	lines = ft_split(c, "\n");
	free(c);
	strs = linestokeys(lines);
	freetokens(lines);
	return (strs);
}

int	getarg(int argc, char *argv[], int **num, char **dict)
{
	if (argc < 2 || argc > 3)
	{
		return (-1);
	}
	if (argc == 2)
	{
		*num = ft_atonum(argv[1]);
		if ((*num)[0] == -1)
			return (-1);
	}
	else if (argc == 3)
	{
		*num = ft_atonum(argv[2]);
		if ((*num)[0] == -1)
			return (-1);
		*dict = argv[1];
		return (0);
	}
	*dict = "numbers.dict";
	return (0);
}

int	parse(int argc, char *argv[], char ***strs, int **num)
{
	char	*dict;

	if (getarg(argc, argv, num, &dict) == -1)
		return (-1);
	*strs = readdict(dict);
	if (*strs == NULL)
		return (-2);
	return (0);
}
