/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 13:22:54 by amurcia-          #+#    #+#             */
/*   Updated: 2023/09/02 19:54:38 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/bonus/computor_bonus.h"

char	*ft_substr(char *s, int start, int len)
{
	char	*d;
	int		cont;
	int		len_s;

	cont = 0;
	len_s = ft_strlen((char *)s);
	if (len >= len_s - start && start < len_s)
		len = len_s - start;
	else if (start >= len_s)
		len = 0;
	else if (len > len_s)
		len = len_s;
	d = malloc(sizeof(char) * (len + 1));
	if (!d)
		return (NULL);
	while (cont < len)
	{
		d[cont] = s[start];
		cont++;
		start++;
	}
	d[cont] = '\0';
	return (d);
}
