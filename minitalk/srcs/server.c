/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 09:33:45 by diogo             #+#    #+#             */
/*   Updated: 2023/01/03 14:36:45 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
TODO:
	- Check if PID is valid or not
	- Receive the message from the client
	- Quickly print the message received
	- Handle multiple clients without restarting
	- ...
Bonus:
	- Send a signal back to the client when a message is received
	- Support unicode characters
*/

// Use only SIGUSR1 and SIGUSR2

void	handler();

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
	ft_printf("Server Process ID: %d\n", pid);
}
