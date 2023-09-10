/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 19:08:13 by amurcia-          #+#    #+#             */
/*   Updated: 2023/09/10 13:49:31 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/bonus/computor_bonus.h"

int	ft_mcd(int a, int b) 
{
	int tmp;

    while (b != 0)
	{
        tmp = b;
        b = a % b;
        a = tmp;
    }
    return (a);
}

void	ft_fraction(double num, double denom)
{
	int		mcd;
	char	*nbr1;
	char	*nbr2;

	if (num == (int)num && denom == (int)denom)
	{
		mcd = ft_mcd(num, denom);
		num /= mcd;
		denom /= mcd;
		nbr1 = ft_take_zeros(num);
		nbr2 = ft_take_zeros(denom);
		printf("The fraction is: %s/%s\n", nbr1, nbr2);
		free(nbr1);
		free(nbr2);
	}
}

void	ft_second_degree(t_letters let)
{
	double	discriminant;
	char	*root1;
	char	*root2;

	discriminant = let.degree[1] * let.degree[1] -4 * let.degree[2] * let.degree[0];
	root1 = ft_take_zeros(let.degree[1]);
	printf("To solve a second degree function, we will follow the equation: \n-b +- sqrt(-4*b*c)/(2*a)\n-%s +- sqrt(-4 * %s", root1, root1);
	free(root1);
	root1 = ft_take_zeros(let.degree[2]);
	root2 = ft_take_zeros(let.degree[0]);
	printf(" * %s)/(2 * %s)\n\n", root1, root2);
	free(root1);
	free(root2);
	if (discriminant > 0)
	{
		root1 = ft_take_zeros((-let.degree[1] + sqrt(discriminant)) / (2 * let.degree[2]));
		root2 = ft_take_zeros((-let.degree[1] - sqrt(discriminant)) / (2 * let.degree[2]));
		printf("Discriminant is strictly positive, the two solutions are:\n%s \n%s\n", root1, root2);
		ft_fraction(-let.degree[1] + sqrt(discriminant), 2 * let.degree[2]);
		ft_fraction(-let.degree[1] - sqrt(discriminant), 2 * let.degree[2]);
	}
	else if (discriminant == 0)
	{
		root1 = ft_take_zeros(- let.degree[1] / (2 * let.degree[2]));
		printf("The solution is: \n%s\n", root1);
		ft_fraction(-let.degree[1], 2 * let.degree[2]);
	}
	else
	{
		root1 = ft_take_zeros(- let.degree[1]/ (2 * let.degree[2]));
		root2 = ft_take_zeros(sqrt(- discriminant) / (2 * let.degree[2]));
		printf("Discriminant is strictly negative, the solution is:\nReal: %s\nImaginary: %s * i\n", root1, root2);
		ft_fraction(- let.degree[1], 2 * let.degree[2]);
		ft_fraction(sqrt(- discriminant), 2 * let.degree[2]);
	}
	if (root1)
		free(root1);
	if (root2)
		free(root2);
}

/**
 * @brief Fix a first degree equation
 * 
 * @param let 
 */
void	ft_first_degree(t_letters let)
{
	char	*result;

	result = ft_take_zeros(- let.degree[0]);
	printf("To solve a second degree function, we will follow the equation -b/c\n%s / ", result);
	free(result);
	result = ft_take_zeros(let.degree[1]);
	printf("%s\n", result);
	free(result);
	result = ft_take_zeros(- let.degree[0] / let.degree[1]);
	printf("The solution is: %s\n", result);
	free(result);
}

void	ft_classify(t_letters let, int degree)
{
	if (degree == 2)
		ft_second_degree(let);
	if (degree == 1)
		ft_first_degree(let);
}

/**
 * @brief Print the reducted form
 * 
 * @param let 
 */
void	ft_reduced_form(t_letters let)
{
	int		i;
	int		zero;
	char	*nbr;

	printf("Reduced form: ");
	i = 0;
	if (let.degree[i] < 0)
		printf("- ");
	while(i < let.len)
	{
		zero = 0;
		if (let.degree[i] != 0)
		{
			nbr = ft_take_zeros(fabs(let.degree[i]));
			printf("%s * X^%d ", nbr, i);
			free(nbr);
			zero = 1;
		}
		i++;
		if (let.degree[i] && zero == 1)
		{
			if (let.degree[i] > 0  && let.degree[i -1] != 0)
				printf("+ ");
			else
				printf("- ");
		}
	}
	if (let.len == 1 && let.degree[0] == 0)
		printf("0 ");
	printf("= 0\n\n");
}

void	ft_print_degree(int degree, t_letters *let)
{
	if (degree == 0 && let->degree[0] == 0)
	{
		printf("All the real numbers are a solution\n");
		exit(1);
	}
	if (degree == 0 && let->degree[0] != 0)
	{
		printf("No posible solution\n");
		exit(1);
	}
	if (degree > 2)
	{
		printf("Polynomial degree: %d\nThe polynomial degree is strictly greater than 2, I can't solve.\n", degree);
		exit(-1);
	}
	printf("Polynomial degree: %d\n\n", degree);
}

int	main(int argc, char **argv)
{
	t_letters	letter;
	int			degree;
	char		*input;

	if (argc != 2)
	{
		printf("Error in number of arguments\n");
		return(-1);
	}
	input = ft_trim(argv[1]);
	ft_check_errors(input);
	ft_set_initial_letters(&letter, input);
	ft_set_letters(&letter, input);
	ft_reduced_form(letter);
	degree = ft_get_degree(letter);
	ft_print_degree(degree, &letter);	
	ft_classify(letter, degree);
	free(letter.degree);
}
