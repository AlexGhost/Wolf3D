/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_mlx.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 17:48:16 by acourtin          #+#    #+#             */
/*   Updated: 2018/01/14 17:50:29 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_MLX_H
# define WOLF_MLX_H

# define WIN_WIDTH 1400
# define WIN_HEIGHT 800

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	int				*imgstr;
}					t_mlx;

typedef struct		s_img
{
	int				bpp;
	int				s_l;
	int				endian;
}					t_img;

#endif
