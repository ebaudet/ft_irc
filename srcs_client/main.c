/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/22 19:44:48 by ebaudet           #+#    #+#             */
/*   Updated: 2014/05/22 20:48:03 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "client.h"

int main(int ac, char **av)
{
	if(ac < 2)
	{
		printf("Usage : %s [address] [pseudo]\n", av[0]);
		return (EXIT_FAILURE);
	}
	app(av[1], av[2]);
	return (EXIT_SUCCESS);
}
