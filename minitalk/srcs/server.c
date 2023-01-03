/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 09:33:45 by diogo             #+#    #+#             */
/*   Updated: 2023/01/03 17:05:00 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
TODO:
	- Check if PID is valid or not
Bonus:
	- Send a signal back to the client when a message is received
	- Support unicode characters
*/

// Function that handles the received signal,
// if the signal sent is SIGUSR1 then it changes the
// current bit to 1 and moves to the next bit;

void	handler(int sig)
{
	static char chr;
	static char i;

	if (sig == SIGUSR1)
		chr = (chr | 1 << i);
	i++;
	if (i == 8)
	{
		write(1, &chr, 1);
		chr = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	action;

	(void)argv;
	pid = getpid();
	if (argc != 1)
	{
		ft_printf("Wrong input! Try \"./server\" instead");
		return (0);
	}
	ft_printf("Server Process ID: %d\n", pid);
	action.sa_flags = SA_RESTART;
	action.sa_handler = &handler;
	sigemptyset(&action.sa_mask);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		pause();
	return (0);
}
