/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 19:06:21 by amurcia-          #+#    #+#             */
/*   Updated: 2023/09/09 21:05:13 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/mandatory/computor.h"

void	ft_second_degree(t_letters let)
{
	double	discriminant;
	double	root1;
	double	root2;

	discriminant = let.degree[1] * let.degree[1] -4 * let.degree[2] * let.degree[0];
	if (discriminant > 0)
	{
		root1 = (-let.degree[1] + sqrt(discriminant)) / (2 * let.degree[2]);
		root2 = (-let.degree[1] - sqrt(discriminant)) / (2 * let.degree[2]);
		printf("Discriminant is strictly positive, the two solutions are:\n%s \n%s\n", ft_take_zeros(root1), ft_take_zeros(root2));
	}
	else if (discriminant == 0)
	{
		root1 = - let.degree[1] / (2 * let.degree[2]);
		printf("The solution is: \n%s\n", ft_take_zeros(root1));
	}
	else
	{
		root1 = - let.degree[1]/ (2 * let.degree[2]);
		root2 = sqrt(- discriminant) / (2 * let.degree[2]);
		printf("Discriminant is strictly negative, the solution is:\nReal: %s\nImaginary: %s * i\n", ft_take_zeros(root1), ft_take_zeros(root2));
	}
}

/**
 * @brief Fix for first degree
 * 
 * @param let 
 */
void	ft_first_degree(t_letters let)
{
	double	result;

	result = - let.degree[0] / let.degree[1];
	printf("The solution is: %s\n", ft_take_zeros(result));
}

/**
 * @brief Classify in functions depending on the degree
 * 
 * @param let 
 * @param degree 
 */
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
	int	i;
	int	zero;
	printf("Reduced form: ");

	i = 0;
	if (let.degree[i] < 0)
		printf("- ");
	while(let.degree[i])
	{
		zero = 0;
		if (let.degree[i] != 0)
		{
			printf("%s * X^%d ", ft_take_zeros(fabs(let.degree[i])), i);
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
	if (let.len == 1)
		printf("0 ");
	printf("= 0\n\n");
}

/**
 * @brief Print the degree. Special cases for degree = 0
 * 
 * @param degree 
 * @param let 
 */
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
