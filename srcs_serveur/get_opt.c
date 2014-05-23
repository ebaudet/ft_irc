/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/22 19:41:44 by ebaudet           #+#    #+#             */
/*   Updated: 2014/05/23 17:26:26 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "serveur.h"

void	get_opt(t_env *e, int ac, char **av)
{
	if (ac != 2)
	{
		fprintf(stderr, USAGE, av[0]);
		exit(1);
	}
	e->port = atoi(av[1]);
}
