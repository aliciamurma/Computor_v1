/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 20:23:23 by amurcia-          #+#    #+#             */
/*   Updated: 2023/09/10 13:20:19 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/bonus/computor_bonus.h"

int	ft_get_degree(t_letters let)
{
	int	i;

	printf("in pos 2: %lf\n", let.degree[2]);
	i = let.len;
	while (i > -1)
	{
		if (let.degree[i] != 0 && let.degree[i] != 0.0)
			return (i);
		i--;
	}
	return (0);
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
