/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_zeros_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 22:57:04 by amurcia-          #+#    #+#             */
/*   Updated: 2023/09/10 00:03:33 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/bonus/computor_bonus.h"

/**
 * @brief Declarar una cadena lo suficientemente grande. Formatear a una cadena con 5 decimales. Eliminar 0 finales
 * 
 * @param nbr 
 * @return char* 
 */
char	*ft_take_zeros(double nbr)
{
    char *str;
	int len;

	str = malloc(sizeof(char) * 50);
    if (!str)
    {
        printf("Error in memory\n");
        exit (-1);
    }
    snprintf(str, sizeof(str), "%.5lf", nbr);
    len = strlen(str);
    while (str[len - 1] == '0')
	{
        str[len - 1] = '\0';
        len--;
    }
	if (str[len -1] == '.')
		str[len - 1] = '\0';
    return (str);
}
