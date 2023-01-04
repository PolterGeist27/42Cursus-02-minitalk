/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:29:07 by diogmart          #+#    #+#             */
/*   Updated: 2023/01/04 11:19:31 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// Function that handles the received signal,
// if the signal sent is SIGUSR1 then it changes the
// current bit to 1 and moves to the next bit;

void	handler(int sig, siginfo_t *info, void *ucontext)
{
	static char	chr;
	static char	i;

	(void)ucontext;
	if (sig == SIGUSR1)
		chr = chr | (1 << i);
	i++;
	if (i == 8)
	{
		write(1, &chr, 1);
		if (chr == '\0')
			kill(info->si_pid, SIGUSR2);
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
	action.sa_flags = SA_RESTART | SA_SIGINFO;
	action.sa_sigaction = &handler;
	sigemptyset(&action.sa_mask);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		pause();
	return (0);
}
