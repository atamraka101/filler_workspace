/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:19:27 by atamraka          #+#    #+#             */
/*   Updated: 2022/10/02 13:47:20 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#define FD 0

typedef struct		s_players
{
	char			me;
	char			enemy;
}					t_players;

typedef struct		s_piece
{
	int row;
	int col;
}					t_piece;

typedef struct		s_map
{
	int				row;
	int				col;

}					t_map;





#include "libft/libft.h"


#endif
