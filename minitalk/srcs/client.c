/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 09:35:14 by diogmart          #+#    #+#             */
/*   Updated: 2023/01/03 17:06:05 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_message(int pid, char *message)
{
	char	c;
	int		i;
	int		j;

	i = 0;
	while (message[i] != '\0')
	{
		j = 0;
		c = message[i];
		while (j < 8)
		{
			if ((c & 1 ) == 1)
				kill(pid, SIGUSR1);
			else if ((c & 1) == 0)
				kill(pid, SIGUSR2);
			usleep(200);
			c = c >> 1;
			j++;
		}
		i++;
	}
}

int	validate_input(int argc, char **argv)
{
	int i;
	
	if (argc != 3)
	{
		ft_printf("Wrong input! Try \"./client [PID] [Message]\" instead");
		return (0);
	}
	i = 0;
	while (argv[1][i] != '\0')
	{
		if (!ft_isdigit(argv[1][i]))
		{
			ft_printf("Wrong input! The Process ID can only contain numbers!");
			return (0);
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (validate_input(argc, argv) != 1)
		return (0);
	pid = ft_atoi(argv[1]);
	send_message(pid, argv[2]);
	send_message(pid, "\n");
	return (0);
}
