/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 19:06:21 by amurcia-          #+#    #+#             */
/*   Updated: 2023/09/02 19:53:12 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/mandatory/computor.h"

void	ft_second_degree(t_letters let)
{
	double	discriminant;
	double	root1;
	double	root2;

	discriminant = let.b * let.b -4 * let.a * let.c;
	if (discriminant > 0)
	{
		root1 = (-let.b + sqrt(discriminant)) / (2 * let.a);
		root2 = (-let.b - sqrt(discriminant)) / (2 * let.a);
		printf("Discriminant is strictly positive, the two solutions are:\n%lf \n%lf\n", root1, root2);
	}
	else if (discriminant == 0)
	{
		root1 = - let.b / (2 * let.a);
		printf("The solution is:\n%lf\n", root1);
	}
	else
	{
		root1 = - let.b/ (2 * let.a);
		root2 = sqrt(- discriminant) / (2 * let.a);
		printf("The solution is:\nReal: %lf\nImaginary: %lf\n", root1, root2);
	}
}

void	ft_first_degree(t_letters let)
{
	double	result;

	result = - let.c / let.b;
	printf("The solution is:\n%lf\n", result);
}

void	ft_classify(t_letters let, int degree)
{
	if (degree == 2)
		ft_second_degree(let);
	if (degree == 1)
		ft_first_degree(let);
}

void	ft_reduced_form(t_letters let)
{
	printf("Reduced form: ");
	if (let.c != 0)
		printf("%lf * X^0 ", let.c);
	if (let.b != 0)
	{
		if (let.b > 0)
			printf("+");
		printf(" %lf * X^1 ", let.b);
	}
	if (let.a != 0)
	{
		if (let.a > 0)
			printf("+");
		printf(" %lf * X^2", let.a);
	}
	printf(" = 0\n");
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
	printf("Polynomial degree: %d\n", degree);
	ft_classify(letter, degree);
}