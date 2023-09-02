/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 20:23:17 by amurcia-          #+#    #+#             */
/*   Updated: 2023/09/02 23:23:44 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/bonus/computor_bonus.h"

bool	ft_set_one_a(char **fragments, int i, t_letters *let)
{
	if (i < 3)
	{
		if (i == 0 && ft_strncmp(fragments[0], "-", 1) == 0)
			let->a -= 1;
		else
			let->a += 1;
		return (true);
	}
	return (false);
}

bool	ft_set_one_b(char **fragments, int i, t_letters *let)
{
	if (i < 3)
	{
		if (i == 0 && ft_strncmp(fragments[0], "-", 1) == 0)
			let->b -= 1;
		else
			let->b += 1;
		return (true);
	}
	return (false);
}

bool	ft_set_one_c(char **fragments, int i, t_letters *let)
{
	if (i < 3)
	{
		if (i == 0 && ft_strncmp(fragments[0], "-", 1) == 0)
			let->c -= 1;
		else
			let->c += 1;
		return (true);
	}
	return (false);
}

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
	{
		let->c -= atof(fragments[i - 2]);
	}
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
		else if (ft_strncmp(str[i], "X", 1) == 0)
			ft_set_b(str, i, let);
		i++;
	}
	ft_free(str);
}

bool	ft_isdouble(char *str)
{
	int	i;

	i =  0;
	while (str[i])
	{
		if (!isdigit(str[i]) && str[i] != '.')
			return (0);
		i++;
	}
	return (1);
}

void	ft_set_alone(char **argv, t_letters *let)
{
	char	**frag;
	int		i;

	i = 0;
	frag = ft_split(argv[1], ' ');
	while(frag[i])
	{
		if (ft_isdouble(frag[i]) && frag[i][0] != 'X')
		{
			if (i > 0 && ft_strncmp(frag[i -1], "-", 1) == 0)
				let->c = let->c + atof(frag[i]);
			else
				let->c = let->c - atof(frag[i]);
		}
		i++;
	}
}

void	ft_set_letters(t_letters *let, char **argv)
{
	char	**equal;
	int		i;
	int		rep;

	i = 0;
	rep = 0;
	equal = ft_split(argv[1], '=');
	ft_set_alone(argv, let);
	ft_set_positive(let, ft_split(equal[0], ' '));
	ft_set_negative(let, ft_split(equal[1], ' '));
	ft_free(equal);
}

void	ft_seet_initial_letters(t_letters *let)
{
	let->a = 0;
	let->b = 0;
	let->c = 0;
}
