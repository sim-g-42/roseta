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
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
struct s_ns {
  int num;
  char *str;
};

char **ft_split(char *str, char *sep);
int ft_atoi(char *str);
int ft_strlen(char *str);
int *ft_atonum(char *str);
int parse(int argc, char *argv[], char ***strs, int **num);
void convert(char **strs, int *num);
void stringtokeys(char **strs, struct s_ns **keys, int *count);

#endif
