/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 20:23:17 by amurcia-          #+#    #+#             */
/*   Updated: 2023/09/01 20:28:27 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../computor.h"

static void	ft_set_a(char **fragments, int i, t_letters *let)
{
	let->a = atof(fragments[i - 2]);
	if (fragments[i - 3] && ft_strncmp(fragments[i -3], "-", 1) == 0)
		let->a = -let->a;
}

static void	ft_set_b(char **fragments, int i, t_letters *let)
{
	let->b = atof(fragments[i - 2]);
	if (fragments[i - 3] && ft_strncmp(fragments[i -3], "-", 1) == 0)
		let->b = -let->b;
}

static void	ft_set_c(char **fragments, int i, t_letters *let)
{
	let->c = atof(fragments[i - 2]);
	if (fragments[i - 3] && ft_strncmp(fragments[i -3], "-", 1) == 0)
		let->c = -let->c;
}

static void	ft_set_rest(char **fragments, int i, t_letters *let)
{
	let->rest = atof(fragments[i + 1]);
	if (fragments[i - 3] && ft_strncmp(fragments[i -3], "-", 1) == 0)
		let->rest = -let->rest;
}


void	ft_set_letters(t_letters *let, char **argv, int degree)
{
	char	**fragments;
	int		i;
	int		rep;

	i = 0;
	rep = 0;
	fragments = ft_split(argv[1], ' ');
	while (fragments[i])
	{
		if (ft_strncmp(fragments[i], "X^2", 3) == 0)
			ft_set_a(fragments, i, let);
		else if (ft_strncmp(fragments[i], "X^1", 3) == 0)
			ft_set_b(fragments, i, let);
		else if (ft_strncmp(fragments[i], "X^0", 3) == 0 && rep == 0)
		{
			rep = 1;
			ft_set_c(fragments, i, let);
		}
		else if (ft_strncmp(fragments[i], "=", 1) == 0 && fragments[i + 1])
			ft_set_rest(fragments, i, let);
		i++;
	}
	if (degree == 2)
		let->c += - let->rest;
	else
		let->c = - let->c + let->rest;
}