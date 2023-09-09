/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 17:17:30 by amurcia-          #+#    #+#             */
/*   Updated: 2023/09/09 19:21:29 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTOR_H
# define COMPUTOR_H

#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h> 

typedef struct	s_letters
{
	double	*degree;
	int		len;
}	t_letters;

void    ft_check_errors(char *input);
void	ft_set_initial_letters(t_letters *let, char *input);
void	ft_set_letters(t_letters *let, char *input);
int		ft_get_exponential(char *str);
int		ft_get_degree(t_letters let);

/*	UTILS	*/
char	*ft_take_zeros(double nbr);
char	**ft_split(char *s, char c);
int		ft_strncmp( char *s1,  char *s2, int n);
char	*ft_substr(char *s, int start, int len);
int		ft_strlen( char *str);
void	ft_free(char **str);
char 	*ft_trim(char *s);

#endif
