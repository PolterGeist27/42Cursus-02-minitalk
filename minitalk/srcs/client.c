/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 09:35:14 by diogmart          #+#    #+#             */
/*   Updated: 2023/01/03 14:36:36 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
TODO:
	- Check if the first arg is a string of numbers
	- Check if the second arg is a string
	- Send the second arg to the server
	- ...
Bonus:
	- Receive and handle the signal from the server
*/

// Use only SIGUSR1 and SIGUSR2

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("Wrong input! Try \"./client [PID] [Message]\" instead");
		return (0);
	}
	pid = ft_atoi(argv[1]);
}
