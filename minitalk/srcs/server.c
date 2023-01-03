/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 09:33:45 by diogo             #+#    #+#             */
/*   Updated: 2023/01/03 10:32:00 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

/*
TODO:
	- Receive the message from the client
	- Quickly print the message received
	- Handle multiple clients
	- ...
Bonus:
	- Send a signal back to the client when a message is received
	- Support unicode characters
*/

int	main(int argc, char **argv)
{
	int	pid;

	pid = getpid();
	(void)argv;
	if (argc != 1)
	{
		ft_printf("Wrong input! Try \"./server\" instead");
		return (0);
	}
}
