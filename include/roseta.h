/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roseta.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganase <simon.ganase@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 02:32:04 by sganase           #+#    #+#             */
/*   Updated: 2026/09/13 05:32:49 by sganase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROSETA_H
#define ROSETA_H

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

struct s_ns
{
	int		num;
	char	*str;
};

char	**ft_split(char *str, char *sep);
char	*copytoken(char *str, int len);
int		ft_atoi(char *str);
int		ft_strlen(char *str);
int		*ft_atonum(char *str);
void	ft_putstr(char *str);
void	ft_putword(char *word, char *after);
void	freeall(char **strs, int *num);
int		parse(int argc, char *argv[], char ***strs, int **num);
int		convert(char **strs, int *num);
void	stringtokeys(char **strs, struct s_ns ***keys, int *count);
char	*findword(struct s_ns **keys, int count, int n);
int		readgroup(int *num, int pos, int size);
void	printnum(struct s_ns **keys, int count, int *num, int len);
void	printgroup(struct s_ns **keys, int count, int val, int rem);
int		checkgroup(struct s_ns **keys, int count, int val, int rem);
int		checkresolvable(struct s_ns **keys, int count, int *num);
void	freekeys(struct s_ns **keys, int count);
char	*trim(char *str);
void	freetokens(char **tokens);
int		linetokens(char *line, char **key, char **val);
char	**linestokeys(char **lines);

#endif
