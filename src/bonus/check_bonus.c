/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 20:49:45 by amurcia-          #+#    #+#             */
/*   Updated: 2023/09/10 14:53:31 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/bonus/computor_bonus.h"

static void ft_error(char *str)
{
    printf("Error in sintaxis: %s\n", str);
    exit(-1);
}

static void ft_alone_dots(char *input)
{
    int i;

    i = 0;
    while (input[i])
    {
        if (input[i] == '.')
        {
            if (i == 0)
                ft_error("What dot you mean?");
            if (i > 0 && !isdigit(input[i -1]))
                ft_error("What dot you mean?");
            if (input[i + 1] && !isdigit(input[i + 1]))
                ft_error("What dot you mean?");
        }
        i++;
    }
}

static void ft_one_dot(char *input)
{
    int i;

    i = 0;
    while (input[i])
    {
        if (isdigit(input[i]))
        {
            while  (input[i] && input[i] != '.')
                i++;
            i++;
            while  (input[i] && isdigit(input[i]))
                i++;
            if (input[i] == '.')
                ft_error("What is that number????");
        }
        i++;
    }
}

void ft_between_digit(char *input)
{
    int i;

    i = 0;
    while (input[i])
    {
        if (isdigit(input[i]) && i > 0 && (!isdigit(input[i - 1]) && input[i - 1] != ' ' && input[i - 1] != '.' && input[i - 1] != '^'))
            ft_error("What is before the numbers?");
        if (isdigit(input[i]) && input[i +1] && (!isdigit(input[i + 1]) && input[i + 1] != ' ' && input[i + 1] != '.' && input[i + 1] != '^'))
            ft_error("What is before the numbers?");
        i++;
    }
}

static void ft_check_equal(char *input)
{
    int i;
    int equal;

    i = 0;
    equal = 0;
    while (input[i])
    {
        if (input[i] == '=')
            equal++;
        i++;
    }
    if (equal != 1)
        ft_error("Please provide only one =");
}

void ft_check_spaces(char *input)
{
    int i;

    i = 0;
    while (input[i])
    {
        if (!isdigit(input[i]) && input[i] != '+' && input[i] != '-' && input[i] != 'X' && input[i] != '*' && input[i] != '^' && input[i] != '.' && input[i] != '=' && input[i] != ' ')
            ft_error("Invalid character");
        if (input[i] == '-' || input[i] == '+' || input[i] == '*')
        {
            if (i != 0 && input[i - 1] != ' ')
                ft_error("It seems that you need to add spaces before the sign");
            if (input[i + 1] && input[i + 1] != ' ')
                ft_error("It seems that you need to add spaces after the sign");
        }
        if (input[i] == 'X' && i != 0 && input[i -1] != ' ')
            ft_error("It seems that you need to add spaces near the X");
        i++;
    }
}

void    ft_check_errors(char *input, char *flag)
{
    if (ft_strncmp(flag, "Y", 2) != 0 && ft_strncmp(flag, "N", 2) != 0)
        ft_error("You have to write \"Y\" or \"N\", please.\n");
    if (ft_strncmp(flag, "Y", 1) == 0)
    {
        ft_check_spaces(input);
        ft_between_digit(input);
    }
    ft_one_dot(input);
    ft_alone_dots(input);
    ft_check_equal(input);
}

