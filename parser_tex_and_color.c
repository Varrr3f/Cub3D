/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tex_and_color.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocapers <ocapers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:13:45 by ocapers           #+#    #+#             */
/*   Updated: 2022/09/16 19:41:59 by ocapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	skip_spaces(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	return (i);
}

void	pars_help_3(t_data *data, char *line, int i, int *count)
{
	if (line[i] == '1')
	{
		count[7] += 1;
		free(line);
		return ;
	}
	else if (line[i] == '\n')
		free(line);
	else if (line[i] == 'F' || line[i] == 'C')
		pars_color_help(data, line, i, count);
	else
		count[6]++;
}

int	pars_help_2(t_data *data, char *line, int counter, int i)
{
	if (line[i] == 'N' && line[i + 1] == 'O')
	{
		pars_wall(data, line + 6, &data->walls[0]);
		free(line);
		counter += 1;
	}
	else if (line[i] == 'S' && line[i + 1] == 'O')
	{
		pars_wall(data, line + 6, &data->walls[1]);
		free(line);
		counter += 1;
	}
	else if (line[i] == 'W' && line[i + 1] == 'E')
	{
		pars_wall(data, line + 6, &data->walls[2]);
		free(line);
		counter += 1;
	}
	else if (line[i] == 'E' && line[i + 1] == 'A')
	{
		pars_wall(data, line + 6, &data->walls[3]);
		free(line);
	}
	return (1);
}

void	pars_help(t_data *data, int *count, int counter, char *line)
{
	if (line[skip_spaces(line)] == 'N' && line[skip_spaces(line) + 1] == 'O')
	{
		count[0] += pars_help_2(data, line, counter, skip_spaces(line));
		return ;
	}
	if (line[skip_spaces(line)] == 'S' && line[skip_spaces(line) + 1] == 'O')
	{
		count[1] += pars_help_2(data, line, counter, skip_spaces(line));
		return ;
	}
	if (line[skip_spaces(line)] == 'W' && line[skip_spaces(line) + 1] == 'E')
	{
		count[2] += pars_help_2(data, line, counter, skip_spaces(line));
		return ;
	}
	if (line[skip_spaces(line)] == 'E' && line[skip_spaces(line) + 1] == 'A')
	{
		count[3] += pars_help_2(data, line, counter, skip_spaces(line));
		return ;
	}
	else
	{
		pars_help_3(data, line, skip_spaces(line), count);
		return ;
	}
}

void	parser_for_text(t_data *data, char *name)
{
	int		counter;
	int		count[7];
	char	*line;
	int		fd;

	fd = open(name, O_RDONLY);
	counter = 0;
	bzero_for_array(count, 8);
	if (fd == -1)
		error_message("Error!\nWow i can't open this conf :'c\n");
	line = get_next_line(fd);
	while (count[7] == 0)
	{
		pars_help(data, count, counter, line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	error_for_text(count);
}
