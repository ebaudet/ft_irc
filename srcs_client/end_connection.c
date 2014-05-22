/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_connection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/22 20:22:45 by ebaudet           #+#    #+#             */
/*   Updated: 2014/05/22 20:58:35 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "client.h"


void	end_connection(int sock)
{
	close(sock);
}
