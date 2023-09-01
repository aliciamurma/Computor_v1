/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 20:23:23 by amurcia-          #+#    #+#             */
/*   Updated: 2023/09/01 20:28:30 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../computor.h"

int	ft_get_degree(char **argv)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (argv[1][i])
	{
		if (argv[1][i] == 'X' && argv[1][i + 2])
		{
			if (x < atoi(&argv[1][i + 2]))
				x = atoi(&argv[1][i + 2]);
		}
		i++;
	}
	return (x);
}

int	ft_get_exponential(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] && str[i++] && str[i] == '^')
			return (str[i++]);
		i++;
	}
	return (0);
}