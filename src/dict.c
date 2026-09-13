/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganase <simon.ganase@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 02:51:25 by sganase           #+#    #+#             */
/*   Updated: 2026/09/13 04:43:03 by sganase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/roseta.h"

char	*trim(char *str)
{
	char	*out;
	int		i[5];

	i[0] = 0;
	while (str[i[0]] == ' ')
		i[0]++;
	i[1] = ft_strlen(str);
	while (i[1] > i[0] && str[i[1] - 1] == ' ')
		i[1]--;
	out = malloc(sizeof(char) * (i[1] - i[0] + 1));
	i[2] = 0;
	while (i[0] < i[1])
	{
		out[i[2]] = str[i[0]];
		i[2]++;
		i[0]++;
	}
	out[i[2]] = '\0';
	return (out);
}

void	freetokens(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

int	linetokens(char *line, char **key, char **val)
{
	char	**parts;
	int		n;

	parts = ft_split(line, ":");
	n = 0;
	while (parts[n])
		n++;
	if (n != 2)
	{
		freetokens(parts);
		if (n == 0)
			return (0);
		return (-1);
	}
	*key = trim(parts[0]);
	*val = trim(parts[1]);
	freetokens(parts);
	if ((*key)[0] < '0' || (*key)[0] > '9')
		return (-1);
	return (1);
}

char	**linestokeys(char **lines)
{
	char	**strs;
	int		i[5];

	i[0] = 0;
	while (lines[i[0]])
		i[0]++;
	strs = malloc(sizeof(char *) * (i[0] * 2 + 1));
	i[1] = 0;
	i[2] = 0;
	while (lines[i[1]])
	{
		i[3] = linetokens(lines[i[1]], &strs[i[2]], &strs[i[2] + 1]);
		if (i[3] == 1)
			i[2] += 2;
		else if (i[3] == -1)
		{
			strs[i[2]] = NULL;
			freetokens(strs);
			return (NULL);
		}
		i[1]++;
	}
	strs[i[2]] = NULL;
	return (strs);
}
