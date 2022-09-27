/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocapers <ocapers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:14:21 by ocapers           #+#    #+#             */
/*   Updated: 2022/09/16 19:40:31 by ocapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_message(char *message)
{
	ft_putstr_fd(message, 1);
	exit(EXIT_FAILURE);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
		arr = NULL;
	}
}

void	free_exit(t_data *data)
{
	(void)data;
	exit(EXIT_SUCCESS);
}

int	ft_close(t_data *data)
{
	(void)data;
	exit(EXIT_SUCCESS);
}
