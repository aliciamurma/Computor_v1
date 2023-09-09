/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 19:37:25 by amurcia-          #+#    #+#             */
/*   Updated: 2023/09/09 19:37:27 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/mandatory/computor.h"

int	ft_strlen( char *str)
{
	int	cont;

	cont = 0;
	while (str[cont])
		cont++;
	return (cont);
}
