/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   third_degree_bonus.degree[0]                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 14:33:27 by amurcia-          #+#    #+#             */
/*   Updated: 2023/09/09 19:16:06 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/bonus/computor_bonus.h"

/**
 * @brief For a third degree we have 3 options: 3 different real roots, 3 equal real roots, 1 real root and 2 complex conjugated roots
 * 
 * @param let 
 */
void	ft_third_degree(t_letters let)
{
    double  discriminant;
    double  p, q, delta;
    double  r, s, t, u;
    double  rho, theta;

    discriminant = (18 * let.degree[2] * let.degree[1] * let.degree[0] * let.degree[3]) - (4 * pow(let.degree[1], 3) * let.degree[3]) + (pow(let.degree[1], 2) * pow(let.degree[0], 2)) - (4 * let.degree[2] * pow(let.degree[0], 3)) - (27 * pow(let.degree[2], 2) * pow(let.degree[3], 2));
    if (discriminant > 0)
    {
        p = (3 * let.degree[2] * let.degree[0] - pow(let.degree[1], 2)) / (3 * pow(let.degree[2], 2));
        q = (2 * pow(let.degree[1], 3) - 9 * let.degree[2] * let.degree[1] * let.degree[0] + 27 * pow(let.degree[2], 2) * let.degree[3]) / (27 * pow(let.degree[2], 3));
        delta = pow(q / 2, 2) + pow(p / 3, 3);
        if (delta >= 0)
        {
            delta = sqrt(delta);
            r = cbrt(-q / 2 + delta);
            s = cbrt(-q / 2 - delta);
            t = -let.degree[1] / (3 * let.degree[2]);
            printf("The solution is:\n");
            printf("x1 = %.4lf\n", r + s + t);
            printf("x2 = %.4lf\n", -(r + s) / 2 + t);
            printf("x3 = %.4lf\n", -(r + s) / 2 + t);
        }
        else
        {
            rho = sqrt(pow(-(q / 2), 2) - pow(p / 3, 3));
            theta = acos(-(q / (2 * sqrt(pow(-(p / 3), 3)))));
            r = 2 * cbrt(sqrt(pow(-(q / 2), 2) - pow(p / 3, 3))) * cos(theta / 3);
            s = 2 * cbrt(sqrt(pow(-(q / 2), 2) - pow(p / 3, 3))) * cos((theta + 2 * M_PI) / 3);
            t = 2 * cbrt(sqrt(pow(-(q / 2), 2) - pow(p / 3, 3))) * cos((theta + 4 * M_PI) / 3);
            printf("The solution is:\n");
            printf("x1 = %.4lf\n", r + s - (let.degree[1] / (3 * let.degree[2])));
            printf("x2 = %.4lf + %.4lfi\n", -(r + s) / 2 - (let.degree[1] / (3 * let.degree[2])), (r - s) * sqrt(3) / 2);
            printf("x3 = %.4lf - %.4lfi\n", -(r + s) / 2 - (let.degree[1] / (3 * let.degree[2])), (r - s) * sqrt(3) / 2);
        }
    }
    else if (discriminant == 0)
    {
        r = -let.degree[1] / (3 * let.degree[2]);
        s = -let.degree[1] / (3 * let.degree[2]);
        t = -let.degree[1] / (3 * let.degree[2]);
        printf("The solution is:\n");
        printf("x1 = %.4lf\n", r + s + t);
        printf("x2 = %.4lf + %.4lfi\n", -(r + s) / 2, sqrt(3) * (r - s) / 2);
        printf("x3 = %.4lf - %.4lfi\n", -(r + s) / 2, sqrt(3) * (r - s) / 2);
    }
    else
    {
        p = (3 * let.degree[2] * let.degree[0] - pow(let.degree[1], 2)) / (3 * pow(let.degree[2], 2));
        s = (2 * pow(let.degree[1], 3) - 9 * let.degree[2] * let.degree[1] * let.degree[0] + 27 * pow(let.degree[2], 2) * let.degree[3]) / (27 * pow(let.degree[2], 3));
        t = sqrt(-(p / 3));
        u = acos(-(s / (2 * t)));
        printf("The solution is:\n");
        printf("x1 = %.4lf\n", -2 * t * cos(u / 3) - (let.degree[1] / (3 * let.degree[2])));
        printf("x2 = %.4lf\n", 2 * t * cos((u + 2 * M_PI) / 3) - (let.degree[1] / (3 * let.degree[2])));
        printf("x3 = %.4lf\n", 2 * t * cos((u + 4 * M_PI) / 3) - (let.degree[1] / (3 * let.degree[2])));
    }
}
