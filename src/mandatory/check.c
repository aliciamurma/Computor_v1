/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:23:19 by amurcia-          #+#    #+#             */
/*   Updated: 2023/09/09 16:23:35 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/mandatory/computor.h"

static void ft_error(char *str)
{
    printf("Error in sintaxis: %s\n", str);
    exit(-1);
}

static void ft_alone_dots(char **argv)
{
    int i;

    i = 0;
    while (argv[1][i])
    {
        if (argv[1][i] == '.')
        {
            if (i == 0)
                ft_error("What dot you mean?");
            if (i > 0 && !isdigit(argv[1][i -1]))
                ft_error("What dot you mean?");
            if (argv[1][i + 1] && !isdigit(argv[1][i + 1]))
                ft_error("What dot you mean?");
        }
        i++;
    }
}

static void ft_one_dot(char **argv)
{
    int i;

    i = 0;
    while (argv[1][i])
    {
        if (isdigit(argv[1][i]))
        {
            while  (argv[1][i] && argv[1][i] != '.')
                i++;
            i++;
            while  (argv[1][i] && isdigit(argv[1][i]))
                i++;
            if (argv[1][i] == '.')
                ft_error("What is that number????");
        }
        i++;
    }
}

static void ft_between_digit(char **argv)
{
    int i;

    i = 0;
    while (argv[1][i])
    {
        if (isdigit(argv[1][i]) && i > 0 && (!isdigit(argv[1][i - 1]) && argv[1][i - 1] != ' ' && argv[1][i - 1] != '.' && argv[1][i - 1] != '^'))
            ft_error("What is before the numbers?");
        if (isdigit(argv[1][i]) && argv[1][i +1] && (!isdigit(argv[1][i + 1]) && argv[1][i + 1] != ' ' && argv[1][i + 1] != '.' && argv[1][i + 1] != '^'))
            ft_error("What is before the numbers?");
        i++;
    }
}

static void ft_check_equal(char **argv)
{
    int i;
    int equal;

    i = 0;
    equal = 0;
    while (argv[1][i])
    {
        if (argv[1][i] == '=')
            equal++;
        i++;
    }
    if (equal != 1)
        ft_error("Please provide only one =");
}

static void ft_check_spaces(char **argv)
{
    int i;

    i = 0;
    while (argv[1][i])
    {
        if (!isdigit(argv[1][i]) && argv[1][i] != '+' && argv[1][i] != '-' && argv[1][i] != 'X' && argv[1][i] != '*' && argv[1][i] != '^' && argv[1][i] != '.' && argv[1][i] != '=' && argv[1][i] != ' ')
            ft_error("Invalid character");
        if (argv[1][i] == '-' || argv[1][i] == '+' || argv[1][i] == '*')
        {
            if (i != 0 && argv[1][i - 1] != ' ')
                ft_error("It seems that you need to add spaces before the sign");
            if (argv[1][i + 1] && argv[1][i + 1] != ' ')
                ft_error("It seems that you need to add spaces after the sign");
        }
        if (argv[1][i] == 'X' && i != 0 && argv[1][i -1] != ' ')
            ft_error("It seems that you need to add spaces near the X");
        i++;
    }
}

void    ft_check_errors(char **argv)
{
    ft_check_spaces(argv);
    ft_between_digit(argv);
    ft_one_dot(argv);
    ft_alone_dots(argv);
    ft_check_equal(argv);
}
