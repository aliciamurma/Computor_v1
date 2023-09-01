/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 19:06:21 by amurcia-          #+#    #+#             */
/*   Updated: 2023/09/01 20:26:58 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../computor.h"

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

	result = let.c / let.b;
	printf("The solution is:\n%lf\n", result);
}

void	ft_classify(t_letters let, int degree)
{
	if (degree == 2)
		ft_second_degree(let);
	if (degree == 1)
		ft_first_degree(let);
}


void	ft_correct_degree(int degree)
{
	if (degree > 2)
	{
		printf("Polynomial degree: %d\nThe polynomial degree is strictly greater than 2, I can't solve.\n", degree);
		exit(-1);
	}
}

int	main(int argc, char **argv)
{
	t_letters	letter;
	int	degree;

	if (argc != 2)
	{
		printf("Error in number of arguments\n");
		return(-1);
	}
	degree = ft_get_degree(argv);
	ft_correct_degree(degree);	
	ft_set_letters(&letter, argv, degree);
	printf("Polynomial degree: %d\n", degree);
	ft_classify(letter, degree);
}
