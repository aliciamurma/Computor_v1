/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 20:23:17 by amurcia-          #+#    #+#             */
/*   Updated: 2023/09/03 14:51:34 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/bonus/computor_bonus.h"

bool	ft_set_one_a(char **fragments, int i, t_letters *let)
{
	if (i < 3)
	{
		if (i == 0 && ft_strncmp(fragments[0], "-", 1) == 0)
			let->a = let->a - 1;
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
			let->b = let->b - 1;
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
			let->c = let->c - 1;
		else
			let->c += 1;
		return (true);
	}
	return (false);
}

static void	ft_set_a(char **fragments, int i, t_letters *let)
{
	if (fragments[i - 3] && ft_strncmp(fragments[i -3], "-", 1) == 0)
		let->a = let->a - atof(fragments[i - 2]);
	else
		let->a += atof(fragments[i - 2]);
}

static void	ft_set_b(char **fragments, int i, t_letters *let)
{
	if (fragments[i - 3] && ft_strncmp(fragments[i -3], "-", 1) == 0)
		let->b = let->b - atof(fragments[i - 2]);
	else
		let->b += atof(fragments[i - 2]);
}

static void	ft_set_c(char **fragments, int i, t_letters *let)
{
	if (fragments[i - 3] && ft_strncmp(fragments[i -3], "-", 1) == 0)
		let->c = let->c - atof(fragments[i - 2]);
	else
		let->c += atof(fragments[i - 2]);
}

static void	ft_set_d(char **fragments, int i, t_letters *let)
{
	if (fragments[i - 3] && ft_strncmp(fragments[i -3], "-", 1) == 0)
		let->d = let->d - atof(fragments[i - 2]);
	else
		let->d += atof(fragments[i - 2]);
}

static void	ft_set_a_(char **fragments, int i, t_letters *let)
{
	if (fragments[i - 3] && ft_strncmp(fragments[i -3], "-", 1) == 0)
		let->a += atof(fragments[i - 2]);
	else
		let->a = let->b - atof(fragments[i - 2]);
}

static void	ft_set_b_(char **fragments, int i, t_letters *let)
{
	if (fragments[i - 3] && ft_strncmp(fragments[i -3], "-", 1) == 0)
		let->b += atof(fragments[i - 2]);
	else
		let->b = let->b - atof(fragments[i - 2]);
}

static void	ft_set_c_(char **fragments, int i, t_letters *let)
{
	if (fragments[i - 3] && ft_strncmp(fragments[i -3], "-", 1) == 0)
		let->c += atof(fragments[i - 2]);
	else
	{
		let->c = let->c - atof(fragments[i - 2]);
	}
}

static void	ft_set_d_(char **fragments, int i, t_letters *let)
{
	if (fragments[i - 3] && ft_strncmp(fragments[i -3], "-", 1) == 0)
		let->d += atof(fragments[i - 2]);
	else
	{
		let->d = let->d - atof(fragments[i - 2]);
	}
}

void	ft_set_negative(t_letters *let, char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_strncmp(str[i], "X^3", 3) == 0)
			ft_set_d_(str, i, let);
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
		if (ft_strncmp(str[i], "X^3", 3) == 0)
			ft_set_d(str, i, let);
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
	int		equal;
(void) let;
	i = 0;
	equal = 0;
	frag = ft_split(argv[1], ' ');
	while(frag[i])
	{
		if (ft_strncmp(frag[i], "=", 1) == 0 )
			equal++;
		if ((ft_isdouble(frag[i]) && !frag[i + 1])
			|| (ft_isdouble(frag[i]) && frag[i + 2] && frag[i + 2][0] != 'X'))
		{
			if (i > 0 && ft_strncmp(frag[i -1], "-", 1) == 0 && equal == 0)
				let->c = let->c - atof(frag[i]);
			else if (i > 0 && ft_strncmp(frag[i -1], "-", 1) == 0 && equal == 1)
				let->c = let->c + atof(frag[i]);
			else if (i > 0 && ft_strncmp(frag[i -1], "-", 1) != 0 && equal == 0)
				let->c = let->c + atof(frag[i]);
			else if (i > 0 && ft_strncmp(frag[i -1], "-", 1) != 0 && equal == 1)
				let->c = let->c - atof(frag[i]);
			else
			{
				if (atof(frag[i]) != 0.0)
					let->c = let->c + atof(frag[i]);
			}
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
