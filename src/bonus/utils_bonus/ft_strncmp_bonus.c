/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 11:51:56 by amurcia-          #+#    #+#             */
/*   Updated: 2023/09/02 19:54:34 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/bonus/computor_bonus.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	cont;

	cont = 0;
	while ((cont < n && s1[cont] != '\0')
		|| (cont < n && s2[cont] != '\0'))
	{
		if (s1[cont] != s2[cont])
			return ((unsigned char)s1[cont] - (unsigned char)s2[cont]);
		cont++;
	}
	if (n == 0)
		return (0);
	return (0);
}
