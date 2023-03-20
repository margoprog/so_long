/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheraul <maheraul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:24:51 by maheraul          #+#    #+#             */
/*   Updated: 2023/02/02 19:25:00 by maheraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "../mlx/minilibx-linux/mlx.h"
# include "../mlx/minilibx-linux/mlx_int.h"
# include <stdlib.h>

# define WALL '1'
# define SOL '0'
# define COLLECT 'C'
# define CACTUS 'R'
# define EXIT 'E'
# define PLAYER 'P'

# define W 119
# define A 97
# define S 115
# define D 100

# define UP 65362
# define LEFT 65361
# define DOWN 65364
# define RIGHT 65363
# define SPACE 32
# define ECHAP 65307
# define ENTER 65293

typedef struct t_mlx
{
	void	*win_win;
	void	*mlx;
	void	*mlx2;
	void	*win;
	void	*img[25];
	void	*nb[10];
}			t_mlx;

typedef struct t_data
{
	int		h;
	int		l;
	int		e_x;
	int		e_y;
	int		p_x;
	int		p_y;
	int		k_x;
	int		k_y;
	int		c;
	int		win;
	char	**map;
	int		profil;
	int		mv;
	int		n1;
	int		n2;
	int		n3;
	int		n4;
	int		farmer_img;
	int		farmer_win;
	int		isgameon;
	int		lose;
	t_mlx	*mlx;
}			t_data;

typedef struct t_op
{
	void	*mlx;
	void	*win;
	void	*intro;
	t_data	*data;
}			t_op;

int			main(int argc, char **argv);
int			ft_error(int i);
int			ft_parse_map2(int fd, char *argv, t_data *data, char *line);
char		*ft_realloc(char *s1, char const *s2);
char		**ft_bourrin2(t_data *data, char *beurk);
int			ft_parse_map3(int fd, char *argv, t_data *data, int y);
int			ft_parse_map4(int fd, t_data *data, char *argv, char *line);

int			ft_no_ber(char *fichier);
int			main(int argc, char **argv);
int			ft_only_1(char *line);
int			ft_parse_map(int fd, char *argv, t_data *data);
void		ft_spread_x(char **map, int y, int x);
void		ft_spread2(char **map, int y, int x);
int			ft_exit_access(char **map);
int			cc_tichar(char *str, char c);
int			ft_spread(char **map, t_data *data);
int			ft_no_ber(char *fichier);
int			ft_only_1(char *line);
int			ft_cpe10(char *line);
int			ft_epc(char *beurk, int c, t_data *data);
char		**ft_all_c_access(char **map);
void		ft_memdel(void **ptr);
void		ft_mlx(t_data *data, t_mlx *mlx);
void		putimage(t_data *data, t_mlx *mlx);
void		ft_printtab(char **tab);
void		putlogo(t_data *data, t_mlx *mlx);
int			space_eat(t_data *data, char c, char f, int space);
int			condition(t_data *data, int y, int x);
int			ft_close(t_data *data);
int			key_opening(int keycode, t_op *op);
void		ft_win(t_data *data);
int			key_hook(int keycode, t_data *data);
void		ft_start(t_data *data, t_mlx *mlx);
void		ft_mlx(t_data *data, t_mlx *mlx);
int			ft_closewin(t_data *data);
void		putfarmer(t_data *data, t_mlx *mlx, int y, int x);
int			ft_farmer_move(int random, t_data *data, int keycode);
int			ft_random(t_data *data);
int			ft_farmer_up(t_data *data, int keycode);
int			ft_farmer_down(t_data *data, int keycode);
int			ft_farmer_left(t_data *data, int keycode);
int			ft_farmer_right(t_data *data, int keycode);
int			ft_parse_map2(int fd, char *argv, t_data *data, char *line);
int			ft_lose(int keycode, t_data *data);
char		**ft_bourrin2(t_data *data, char *beurk);
char		**ft_bourrin(int fd, char *argv, t_data *data);
int			farmer_libre(t_data *data);
void		data_farmer(char **map, t_data *data);
int			ft_exit_access(char **map);
void		ft_orientation(t_data *data, t_mlx *mlx, int y, int x);
void		ft_gime_flower(t_data *data, t_mlx *mlx, int y, int x);
void		ft_love(t_data *data, t_mlx *mlx, int y, int x);
void		ft_foret_de_if(t_data *data, t_mlx *mlx, int y, int x);
void		putimage(t_data *data, t_mlx *mlx);
void		putlogo2(t_mlx *mlx, int x, int y);
void		putlogo3(t_data *data, t_mlx *mlx, int x, int y);
void		putlogo(t_data *data, t_mlx *mlx);
int			ft_intro(t_data *data);
int			ft_closewin(t_data *data);
void		closegame(t_data *data, int value, char *str);
int			escape(int keycode, t_data *data);
int			ft_close(t_data *data);
void		ft_putn(int n, t_data *data);
void		ft_printtab(char **tab);
int			space_eat(t_data *data, char c, char f, int space);

#endif