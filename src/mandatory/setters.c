/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 20:23:17 by amurcia-          #+#    #+#             */
/*   Updated: 2023/09/09 18:52:55 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/mandatory/computor.h"

static void	ft_set_neg(char **fragments, int i, t_letters *let, int nbr)
{
	if (i > 2 && ft_strncmp(fragments[i -3], "-", 1) == 0)
		let->degree[nbr] += atof(fragments[i - 2]);
	else
		let->degree[nbr] -= atof(fragments[i - 2]);
}

static void	ft_set_pos(char **fragments, int i, t_letters *let, int nbr)
{
	if (i > 2 && ft_strncmp(fragments[i -3], "-", 1) == 0)
		let->degree[nbr] -= atof(fragments[i - 2]);
	else
		let->degree[nbr] += atof(fragments[i - 2]);
}

static void	ft_set_negative(t_letters *let, char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (strlen(str[i]) > 2 && str[i][0] == 'X' && str[i][1] == '^' && isdigit(str[i][2]))
			ft_set_neg(str, i, let, str[i][2] - '0');
		i++;
	}
	ft_free(str);
}

static void	ft_set_positive(t_letters *let, char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (strlen(str[i]) > 2 && str[i][0] == 'X' && str[i][1] == '^' && isdigit(str[i][2]))
			ft_set_pos(str, i, let, str[i][2] - '0');
		i++;
	}
	ft_free(str);
}

void	ft_set_letters(t_letters *let, char *input)
{
	char	**equal;
	int		i;
	int		rep;

	i = 0;
	rep = 0;
	equal = ft_split(input, '=');
	ft_set_positive(let, ft_split(equal[0], ' '));
	ft_set_negative(let, ft_split(equal[1], ' '));
	ft_free(equal);
}

void	ft_set_initial_letters(t_letters *let, char *input)
{
	int	i;
	int	nbr;
	int	size;

	i = 0;
	nbr = 0;
	size = 0;
	while(input[i])
	{
		if (input[i] == 'X' && input[i + 2] && input[i + 2] - '0' > size)
			size = input[i + 2] - '0';
		i++;
	}
	let->len = size;
	let->degree = malloc(sizeof(double) * size + 1);
	if (!let->degree)
	{
		printf("Error of memory :( \n)");
		exit(-1);
	}
	let->degree[size] = '\0';
	i = 0;
	while (let->degree[i])
	{
		let->degree[i] = 0.0;
		i++;
	}
	printf("The size is: %d\n", size);
}
