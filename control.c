/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnait-el <rnait-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 08:12:43 by rnait-el          #+#    #+#             */
/*   Updated: 2023/03/09 08:14:03 by rnait-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	wall_control(t_game *game)
{
	size_t	x;
	int		y;

	y = 0;
	while (y < (game->size_y / SIZE))
	{
		x = 0;
		while (x < (game->size_x / SIZE))
		{
			if ((y == 0 || x == 0) && game->map[y][x] != '1')
				message(RED"Error\nmap must be surrounded by walls\n"ENDC, game);
			else if ((y == (game->size_y / SIZE - 1)
					|| x == (game->size_x / SIZE - 1))
				&& game->map[y][x] != '1')
				message(RED"Error\nmap must be surrounded by walls\n"ENDC, game);
			x++;
		}
		y++;
	}
}

void	map_control(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'E')
				game->exitcheck++;
			j++;
		}
		i++;
	}
	if (game->coincheck == 0)
		message(RED"There are no enemy\n"ENDC, game);
	if (game->exitcheck == 0)
		message("Error\nThere is no exit \n", game);
	if (game->playercheck != 1)
		message("Error\nYou can only have 1 character!\n", game);
}

void	game_control(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
					game->coincheck++;
			if (game->map[i][j] == 'P')
			{
				game->player.x = j * SIZE;
				game->player.y = i * SIZE;
				game->playercheck++;
			}
			j++;
		}
		i++;
	}
	map_control(game);
	wall_control(game);
}

int	move_check(t_game *game, int i, int j)
{
	if (game->map[i][j] == '1')
		return (1);
	else if (game->map[i][j] == 'C')
	{
		game->player.coin++;
		game->map[i][j] = '0';
	}
	else if (game->map[i][j] == 'E')
	{
		if (game->player.coin != game->coincheck)
		{
			printf(RED"search and destroy\n"ENDC);
			return (1);
		}
		message(GREEN"you win!\n"ENDC, game);
		return (0);
	}
	return (0);
}
