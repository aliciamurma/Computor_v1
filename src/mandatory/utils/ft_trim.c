/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:23:39 by amurcia-          #+#    #+#             */
/*   Updated: 2023/09/09 19:19:52 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/mandatory/computor.h"

static char *ft_ltrim(char *s)
{
    while(isspace(*s))
        s++;
    return s;
}

static char *ft_rtrim(char *s)
{
    char    *back;
    
    back = s + strlen(s);
    while(isspace(*--back));
    *(back+1) = '\0';
    return s;
}

char    *ft_trim(char *s)
{
    char    *str;

    str = ft_ltrim(s);
    return ft_rtrim(str); 
}