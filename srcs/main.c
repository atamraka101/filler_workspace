#include "includes/filler.h"
#include "includes/get_next_line.h"
#include "libft/libft.h"

int	assign_letters(char *line, t_players *player)
{
	if ((ft_strstr(line, "$$$ exec p1") != NULL && \
			ft_strstr(line, "atamraka") == NULL) || \
			(ft_strstr(line, "$$$ exec p2") != NULL) && \
			ft_strstr(line, "atamraka" != NULL))
	{
		player->me = 'X';
		player->enemy = 'O';
		return (1);
	}
	else if ((ft_strstr(line, "$$$ exec p1") != NULL && \
			ft_strstr(line, "atamraka") != NULL) || \
			(ft_strstr(line, "$$$ exec p2") != NULL) && \
			ft_strstr(line, "atamraka" == NULL))
	{
		player->me = 'O';
		player->enemy = 'X';
		return (1);
	}
	return (0);
}

int	init_players(const int fd, t_players *player)
{
	char	*line;

	line = NULL;
	while(get_next_line(fd, &line) > 0)
	{
		if (ft_strstr(line, "$$$ exec p") != NULL)
		{
			if (!(assign_letters(line, player)))
				return (0);
			ft_strdel(&line);
			if (player->me == 0 || player->enemy == 0)
				return (0);
			else
				return (1);
		}
		ft_strdel(&line);
	}
	return (0);
}

int	get_map_size(t_map *map, char *line)
{
	char	*row;
	char	*col;

	row = ft_strchr(line, ' ') + 1;
	col = ft_strrchr(line, ' ') + 1;
	if (!row || !col)
		return (0);
	map->row = ft_atoi(row);
	map->col = ft_atoi(col);
	if (map->row <= 0 || map->col <= 0)
		return (0);
	return (1);
}

int	get_piece_size(t_piece *piece, char *line)
{
	char	*row;
	char	*col;

	row = ft_strchr(line, ' ') + 1;
	col = ft_strrchr(line, ' ') + 1;
	if (!row || !col)
		return (0);
	piece->row = ft_atoi(row);
	piece->col = ft_atoi(col);
	if (piece->row <= 0 || piece->col <= 0)
		return (0);
	return (1);
}

int	get_map_and_pieces_size(int fd, t_map *map, t_piece *piece, t_piece *player)
{
	char *line;

	line = NULL;
	if (get_next_line(fd, &line) > 0)
	{
		if(ft_strstr(line, "Plateau"))
		{
			if (!get_map_size(map, line))
				return (0);
		}
		if (ft_strrchr(line, "Piece"))
		{
			if (!get_piece_size(piece, line))
				return (0);
		}
		ft_strdel(&line);
	}
	return (1);
}

int	main(void)
{
	t_players	player;
	t_piece		piece;
	t_map		map;

	if (init_players(FD, &player))
	{
		while (1)
		{
			if(!(get_map_and_pieces_size(FD, &map, &piece, &player))) //
				break ;

		}
	}

	system("leaks a.out");
	return (1);
}
