/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 20:23:17 by amurcia-          #+#    #+#             */
/*   Updated: 2023/09/10 13:50:28 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/mandatory/computor.h"
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

static void	ft_set_neg(char **fragments, int i, t_letters *let, int nbr)
{
	if ((i > 1 && ft_isdouble(fragments[i - 2]) && ft_strncmp(fragments[i - 1], "*", 1) != 0) || (i > 1 && !ft_isdouble(fragments[i - 2])) || (i > 0 && ft_strncmp(fragments[i - 1], "-", 1) == 0))
		let->degree[nbr] = let->degree[nbr] - 1;
	else if ((i > 1 && !ft_isdouble(fragments[i - 2])) || i == 0)
		let->degree[nbr] = let->degree[nbr] - 1;
	else if (i > 2 && ft_strncmp(fragments[i -3], "-", 1) == 0)
		let->degree[nbr] += atof(fragments[i - 2]);
	else
		let->degree[nbr] -= atof(fragments[i - 2]);
}

static void	ft_set_pos(char **fragments, int i, t_letters *let, int nbr)
{
	if ((i > 1 && ft_isdouble(fragments[i - 2]) && ft_strncmp(fragments[i - 1], "*", 1) != 0) || (i > 1 && !ft_isdouble(fragments[i - 2])) || (i > 0 && ft_strncmp(fragments[i - 1], "-", 1) == 0))
		let->degree[nbr] = let->degree[nbr] + 1;
	else if ((i > 1 && !ft_isdouble(fragments[i - 2])) || i == 0)
		let->degree[nbr] = let->degree[nbr] + 1;
	else if (i > 2 && ft_strncmp(fragments[i -3], "-", 1) == 0)
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
		if (str[i][0] == 'X' && str[i][1] == '^' && isdigit(str[i][2]))
			ft_set_neg(str, i, let, str[i][2] - '0');
		else if (str[i][0] == 'X')
		{
			if (i > 1 && ft_isdouble(str[i - 2]))
				let->degree[1] -= atof(str[i - 2]);
			else 
				let->degree[1] -= 1;
		}
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
		if (str[i][0] == 'X' && str[i][1] == '^' && isdigit(str[i][2]))
			ft_set_pos(str, i, let, str[i][2] - '0');
		else if (str[i][0] == 'X')
		{
			if (i > 1 && ft_isdouble(str[i - 2]))
				let->degree[1] += atof(str[i - 2]);
			else 
				let->degree[1] += 1;
		}
		i++;
	}
	ft_free(str);
}

void	ft_set_only_nbr(char *input, t_letters *let)
{
	char	**frag;
	int		i;
	int		equal;
	i = 0;
	equal = 0;
	frag = ft_split(input, ' ');
	while(frag[i])
	{
		if (ft_strncmp(frag[i], "=", 1) == 0 )
			equal++;
		if ((ft_isdouble(frag[i]) && !frag[i + 1])
			|| (ft_isdouble(frag[i]) && frag[i + 2] && frag[i + 1][0] != '*'))
		{
			if (i > 0 && ft_strncmp(frag[i -1], "-", 1) == 0 && equal == 0)
				let->degree[0] = let->degree[0] - atof(frag[i]);
			else if (i > 0 && ft_strncmp(frag[i -1], "-", 1) == 0 && equal == 1)
				let->degree[0] = let->degree[0] + atof(frag[i]);
			else if (i > 0 && ft_strncmp(frag[i -1], "-", 1) != 0 && equal == 0)
				let->degree[0] = let->degree[0] + atof(frag[i]);
			else if (i > 0 && ft_strncmp(frag[i -1], "-", 1) != 0 && equal == 1)
				let->degree[0] = let->degree[0] - atof(frag[i]);
			else
			{
				if (atof(frag[i]) != 0.0)
					let->degree[0] = let->degree[0] + atof(frag[i]);
			}
		}
		i++;
	}
	ft_free(frag);
}

void	ft_set_letters(t_letters *let, char *input)
{
	char	**equal;
	int		i;
	int		rep;

	i = 0;
	rep = 0;
	equal = ft_split(input, '=');
	ft_set_only_nbr(input, let);
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
	let->len = size + 1;
	let->degree = malloc(sizeof(double) * size + 2);
	if (!let->degree)
	{
		printf("Error of memory :( \n)");
		exit(-1);
	}
	let->degree[size + 1] = '\0';
	i = 0;
	while (let->degree[i])
	{
		let->degree[i] = 0.0;
		i++;
	}
}
