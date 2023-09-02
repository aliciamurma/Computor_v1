/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 19:06:21 by amurcia-          #+#    #+#             */
/*   Updated: 2023/09/02 23:05:36 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/mandatory/computor.h"

void	ft_second_degree(t_letters let)
{
	double	discriminant;
	double	root1;
	double	root2;

	printf("To solve a second degree function, we will follow the equation: -b +- sqrt(-4*b*c)/(2*a) : -%s +- sqrt(-4 * %s * %s)/(2 * %s)\n\n", ft_take_zeros(let.b), ft_take_zeros(let.b), ft_take_zeros(let.c), ft_take_zeros(let.a));
	discriminant = let.b * let.b -4 * let.a * let.c;
	if (discriminant > 0)
	{
		root1 = (-let.b + sqrt(discriminant)) / (2 * let.a);
		root2 = (-let.b - sqrt(discriminant)) / (2 * let.a);
		printf("Discriminant is strictly positive, the two solutions are:\n%s \n%s\n", ft_take_zeros(root1), ft_take_zeros(root2));
	}
	else if (discriminant == 0)
	{
		root1 = - let.b / (2 * let.a);
		printf("The solution is:\n%s\n", ft_take_zeros(root1));
	}
	else
	{
		root1 = - let.b/ (2 * let.a);
		root2 = sqrt(- discriminant) / (2 * let.a);
		printf("The solution is:\nReal: %s\nImaginary: %s\n", ft_take_zeros(root1), ft_take_zeros(root2));
	}
}

void	ft_first_degree(t_letters let)
{
	double	result;

	result = - let.c / let.b;
	printf("The solution is: %s\n", ft_take_zeros(result));
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
	printf("Reduced form: ");
	if (let.c != 0)
		printf("%s * X^0 ", ft_take_zeros(let.c));
	if (let.b != 0)
	{
		if (let.b > 0  && let.c > 0)
			printf("+ ");
		printf(" %s * X^1 ", ft_take_zeros(let.b));
	}
	if (let.a != 0)
	{
		if (let.a > 0)
			printf("+");
		printf(" %s * X^2 ", ft_take_zeros(let.a));
	}
	printf("= 0\n\n");
}

void	ft_correct_degree(int degree, t_letters *let)
{
	if (degree == 0 && let->c == 0)
	{
		printf("All the real numbers are a solution\n");
		exit(1);
	}
	if (degree == 0 && let->c != 0)
	{
		printf("No posible solution\n");
		exit(1);
	}
	if (degree > 2)
	{
		printf("Polynomial degree: %d\nThe polynomial degree is strictly greater than 2, I can't solve.\n", degree);
		exit(-1);
	}
}

int	main(int argc, char **argv)
{
	t_letters	letter;
	int			degree;

	if (argc != 2)
	{
		printf("Error in number of arguments\n");
		return(-1);
	}
	ft_seet_initial_letters(&letter);
	ft_set_letters(&letter, argv);
	ft_reduced_form(letter);
	degree = ft_get_degree(argv);
	ft_correct_degree(degree, &letter);	
	degree = ft_get_true_degree(letter);
	printf("Polynomial degree: %d\n\n", degree);
	ft_classify(letter, degree);
}
