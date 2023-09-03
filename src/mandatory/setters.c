/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 20:23:17 by amurcia-          #+#    #+#             */
/*   Updated: 2023/09/03 13:24:05 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/mandatory/computor.h"

static void	ft_set_a(char **fragments, int i, t_letters *let)
{
	if (fragments[i - 3] && ft_strncmp(fragments[i -3], "-", 1) == 0)
		let->a -= atof(fragments[i - 2]);
	else
		let->a += atof(fragments[i - 2]);
}

static void	ft_set_b(char **fragments, int i, t_letters *let)
{
	if (fragments[i - 3] && ft_strncmp(fragments[i -3], "-", 1) == 0)
		let->b -= atof(fragments[i - 2]);
	else
		let->b += atof(fragments[i - 2]);
}

static void	ft_set_c(char **fragments, int i, t_letters *let)
{
	if (fragments[i - 3] && ft_strncmp(fragments[i -3], "-", 1) == 0)
		let->c -= atof(fragments[i - 2]);
	else
		let->c += atof(fragments[i - 2]);
}

static void	ft_set_a_(char **fragments, int i, t_letters *let)
{
	if (fragments[i - 3] && ft_strncmp(fragments[i -3], "-", 1) == 0)
		let->a += atof(fragments[i - 2]);
	else
		let->a -= atof(fragments[i - 2]);
}

static void	ft_set_b_(char **fragments, int i, t_letters *let)
{
	if (fragments[i - 3] && ft_strncmp(fragments[i -3], "-", 1) == 0)
		let->b += atof(fragments[i - 2]);
	else
		let->b -= atof(fragments[i - 2]);
}

static void	ft_set_c_(char **fragments, int i, t_letters *let)
{
	if (fragments[i - 3] && ft_strncmp(fragments[i -3], "-", 1) == 0)
		let->c += atof(fragments[i - 2]);
	else
		let->c -= atof(fragments[i - 2]);
}

void	ft_set_negative(t_letters *let, char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_strncmp(str[i], "X^2", 3) == 0)
			ft_set_a_(str, i, let);
		else if (ft_strncmp(str[i], "X^1", 3) == 0)
			ft_set_b_(str, i, let);
		else if (ft_strncmp(str[i], "X^0", 3) == 0)
			ft_set_c_(str, i, let);
		i++;
	}
	ft_free(str);
}

void	ft_set_positive(t_letters *let, char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_strncmp(str[i], "X^2", 3) == 0)
			ft_set_a(str, i, let);
		else if (ft_strncmp(str[i], "X^1", 3) == 0)
			ft_set_b(str, i, let);
		else if (ft_strncmp(str[i], "X^0", 3) == 0)
			ft_set_c(str, i, let);
		i++;
	}
	ft_free(str);
}

void	ft_set_letters(t_letters *let, char **argv)
{
	char	**equal;
	int		i;
	int		rep;

	i = 0;
	rep = 0;
	equal = ft_split(argv[1], '=');
	ft_set_positive(let, ft_split(equal[0], ' '));
	ft_set_negative(let, ft_split(equal[1], ' '));
	ft_free(equal);
		printf("a: %lf\n", let->a);
	printf("b: %lf\n", let->b);
	printf("c: %lf\n", let->c);
}

void	ft_seet_initial_letters(t_letters *let)
{
	let->a = 0;
	let->b = 0;
	let->c = 0;
}
