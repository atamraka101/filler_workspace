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
		player->me = 'O';
		player->enemy = 'X';
		return (1);
	}
	else if ((ft_strstr(line, "$$$ exec p1") != NULL && \
			ft_strstr(line, "atamraka") != NULL) || \
			(ft_strstr(line, "$$$ exec p2") != NULL) && \
			ft_strstr(line, "atamraka" == NULL))
	{
		player->me = 'X';
		player->enemy = 'O';
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


int	main(void)
{
	t_players	player;
	t_piece		piece;
	t_map		map;

	if (init_players(FD, &player))
	{
		while (1)
		{

		}
	}







	system("leaks a.out");
	return (1);
}
