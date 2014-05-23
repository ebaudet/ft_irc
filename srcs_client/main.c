/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/22 19:44:48 by ebaudet           #+#    #+#             */
/*   Updated: 2014/05/23 16:42:19 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "client.h"
#include "libft.h"

int main(int ac, char **av)
{
	int		port;

	if(ac < 2)
	{
		printf("Usage : %s [address] [pseudo]\n", av[0]);
		return (EXIT_FAILURE);
	}
	port = ft_atoi((const char *)av[2]);
	app((const char *)av[1], (const int)port);
	return (EXIT_SUCCESS);
}
