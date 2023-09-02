/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 19:08:13 by amurcia-          #+#    #+#             */
/*   Updated: 2023/09/02 22:33:28 by amurcia-         ###   ########.fr       */
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

/**
 * @brief Convert a double into a fraction by maximo comun divisor
 * 
 * @param root 
 */
void	ft_fraction(double root)
{
	int	num;
	int	denom;
	int	mcd;

	num = (int)(root + 1000000);
	denom = 1000000;
	mcd = ft_mcd(num, denom);
	num /= mcd;
	denom /= mcd;
	printf("The fraction is: %d/%d\n", num, denom);
}


void	ft_second_degree(t_letters let)
{
	double	discriminant;
	double	root1;
	double	root2;

	printf("To solve a second degree function, we will follow the equation: -b +- sqrt(-4*b*c)/(2*a) : -%.1lf +- sqrt(-4 * %.1lf * %.1lf)/(2 * %lf)\n", let.b, let.b, let.c, let.a);
	discriminant = let.b * let.b -4 * let.a * let.c;
	if (discriminant > 0)
	{
		root1 = (-let.b + sqrt(discriminant)) / (2 * let.a);
		root2 = (-let.b - sqrt(discriminant)) / (2 * let.a);
		printf("Discriminant is strictly positive, the two solutions are:\n%.1lf \n%.1lf\n", root1, root2);
		ft_fraction(root1);
		ft_fraction(root2);
	}
	else if (discriminant == 0)
	{
		root1 = - let.b / (2 * let.a);
		printf("The solution is:\n%.1lf\n", root1);
		ft_fraction(root1);
	}
	else
	{
		root1 = - let.b/ (2 * let.a);
		root2 = sqrt(- discriminant) / (2 * let.a);
		printf("The solution is:\nReal: %lf\nImaginary: %lf\n", root1, root2);
		ft_fraction(root1);
		ft_fraction(root2);
	}
}

void	ft_first_degree(t_letters let)
{
	double	result;

	result = let.c / let.b;
	printf("The solution is: %.2lf\n", result);
	
	printf("The fraction is: %d/%d\n", (int)let.c, (int)let.b);
}

void	ft_classify(t_letters let, int degree)
{
	// if (degree == 3)
	// 	ft_third_degree(let);
	if (degree == 2)
		ft_second_degree(let);
	if (degree == 1)
		ft_first_degree(let);
}

/**
 * @brief If we have a double that only has 0 after the dot, return 1
 * 
 * @return true 
 * @return false 
 */
bool	ft_dot_zero(double nbr)
{
	int int_part = (int)nbr;

    if (nbr == (double)int_part)
		return (1);
	return (0);
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
	{
		if (ft_dot_zero(let.c))
			printf("%d * X^0 ", (int)let.c);
		else
			printf("%.1lf * X^0 ", let.c);
	}
	if (let.b != 0)
	{
		if (let.b > 0  && let.c > 0)
			printf("+ ");
		if (ft_dot_zero(let.c))
			printf("%d * X^1 ", (int)let.b);
		else
			printf(" %.1lf * X^1 ", let.b);
	}
	if (let.a != 0)
	{
		if (let.a > 0)
			printf("+");
		if (ft_dot_zero(let.c))
			printf("%d * X^2 ", (int)let.a);
		else
			printf(" %.1lf * X^2 ", let.a);
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
	if (degree > 3)
	{
		printf("Polynomial degree: %d\n\nThe polynomial degree is strictly greater than 2, I can't solve.\n", degree);
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
	ft_check_errors(argv);
	ft_seet_initial_letters(&letter);
	ft_set_letters(&letter, argv);
	ft_reduced_form(letter);
	degree = ft_get_degree(argv);
	ft_correct_degree(degree, &letter);	
	printf("Polynomial degree: %d\n\n", degree);
	ft_classify(letter, degree);
}
