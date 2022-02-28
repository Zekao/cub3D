/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 21:13:28 by nabentay          #+#    #+#             */
/*   Updated: 2022/02/28 17:38:40 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <libft.h>
# include <get_next_line.h>
# include <bsd/string.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

typedef struct	s_ray
{
	double	posx; //position x du joueur
	double	posy; //position y du joueur
	double	dirx; //vecteur de direction (commence à -1 pour N, 1 pour S, 0 sinon)
	double	diry; //vecteur de direction (commence à -1 pour W, 1 pour E, 0 sinon)
	double	planx; //vecteur du plan (commence à 0.66 pour E, -0.66 pour W, 0 sinon)
	double	plany; //vecteur du plan (commence à 0.66 pour N, -0.66 pour S, 0 sinon)
	double	raydirx; //calcul de direction x du rayon
	double	raydiry; //calcul de direction y du rayon
	double	camerax; //point x sur la plan camera : Gauche ecran = -1, milieu = 0, droite = 1
	int		mapx; // coordonée x du carré dans lequel est pos
	int		mapy; // coordonnée y du carré dans lequel est pos
	double	sidedistx; //distance que le rayon parcours jusqu'au premier point d'intersection vertical (=un coté x)
	double	sidedisty; //distance que le rayon parcours jusqu'au premier point d'intersection horizontal (= un coté y)
	double	deltadistx; //distance que rayon parcours entre chaque point d'intersection vertical
	double	deltadisty; //distance que le rayon parcours entre chaque point d'intersection horizontal
	int		stepx; // -1 si doit sauter un carre dans direction x negative, 1 dans la direction x positive
	int		stepy; // -1 si doit sauter un carre dans la direction y negative, 1 dans la direction y positive
	int		hit; // 1 si un mur a ete touche, 0 sinon
	int		side; // 0 si c'est un cote x qui est touche (vertical), 1 si un cote y (horizontal)
	double	perpwalldist; // distance du joueur au mur
	int		lineheight; //hauteur de la ligne a dessiner
	int		drawstart; //position de debut ou il faut dessiner
	int		drawend; //position de fin ou il faut dessiner
	int		x; //permet de parcourir tous les rayons
}					t_ray;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	char	**map;
	int		win_x;
	int		win_y;
	int		move;
	int		collectible;
}				t_vars;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_data;

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

int	ft_check_zero(char **map, int y, int x);
int	ft_check_first_last_line(char **map, int y, int x);
int	ft_check_col(char **map, int i, int j);
int	ft_check_player(char **map, int i, int j);
int	ft_check_content(char **map, int i, int j);
int ft_check_textures(char **map);

char	**recover_map(char *file);
int		ft_get_size(char *file);
int		ft_charcmp(char a, char b);
int		ft_strlen2(char *str);
void	ft_parse_cub(char *str);

char    **ft_create_new(char **map, int i);
char    **adjust_map(char **map);
int		ft_check_line(char *line);
int		ft_strstrlen(char **str);


#endif
