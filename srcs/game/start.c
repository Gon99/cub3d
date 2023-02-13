/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:16:19 by goliano-          #+#    #+#             */
/*   Updated: 2023/02/09 18:18:09 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	my_mlx_pixel_put(t_mdata *mdata, int x, int y, int color)
{
	char	*dst;

	//Align bytes, line_length differs from the window with
	dst = mdata->win_addr + (y * mdata->ll_win + x * (mdata->bpp_win / 8));
	*(unsigned int *)dst = color;
}

static int	player_colision(int y, int x, t_gdata *gdata)
{
	int	col;

	col = 0;
	if (y < 0 || y > gdata->height)
		return (1);
	if (x < 0 || x > gdata->width)
		return (1);
	if (gdata->map[y][x] == '1')
		col = 1;
	return (col);
}

static void	player_move(t_gdata *gdata, int key)
{
	float	new_px;
	float	new_py;
	int		type;

	type = key_type(key);
	new_px = gdata->pdata->x;
	new_py = gdata->pdata->y;
	if (type == 1 || type == 3)
	{
		new_px = gdata->pdata->x + (gdata->pdata->move * cos(gdata->pdata->angle) * gdata->pdata->vel);
		new_py = gdata->pdata->y + (gdata->pdata->move * sin(gdata->pdata->angle) * gdata->pdata->vel);
	}
	else if (type == 4 || type == 2)
	{
		//CHECK WHY
		new_px = gdata->pdata->x + (gdata->pdata->move * cos(gdata->pdata->angle + (M_PI / 2)) * gdata->pdata->vel);
		new_py = gdata->pdata->y + (gdata->pdata->move * sin(gdata->pdata->angle + (M_PI / 2)) * gdata->pdata->vel);
	}
	if (!player_colision(new_py, new_px, gdata))
	{
		gdata->pdata->x = new_px;
		gdata->pdata->y = new_py;
	}
	gdata->pdata->angle += gdata->pdata->spin * gdata->pdata->vel_spin;
	gdata->pdata->angle = normalize_angle(gdata->pdata->angle);//TODO-> check angle
}

void	update_player(t_gdata *gdata, int key)
{
	player_move(gdata, key);
	//INICIALIZAR EL HAZ DE RAYOS
	int i = 0;
	while (i < gdata->rdata->n_rays)
	{
		gdata->rdata->ray[i].x = gdata->pdata->x;
		gdata->rdata->ray[i].y = gdata->pdata->y;
		set_angle(gdata->pdata->angle, i, gdata);
		i++;
	}
	//RAY DIRECTION 0 -> -- M_PI <- -- 3 * M_PI / 2 (ARR) -- M_PI / 2 (AB)
	int	down = 0;
	int	left = 0;
	if (gdata->pdata->angle < M_PI)
		down = 1;
	if (gdata->pdata->angle < 3 * M_PI / 2 && gdata->pdata->angle > M_PI / 2)
		left = 1;
	//HORIZONTAL HIT
	float	x_intercept = 0;
	float	y_intercept = gdata->pdata->y;
	int	hor_hit = 0;
	//SI APUNTA HACIA ABAJO, INCREMENTAMOS UN TILE
	if (down)
		y_intercept += TILE_SIZE;
	float	adyacent = (y_intercept - gdata->pdata->y) / tan(gdata->pdata->angle);
	x_intercept = gdata->pdata->x + adyacent;
	//CALCULAMOS LA DISTANCIA DE CADA PASO
	float y_step = 1;
	float x_step = y_step / tan(gdata->pdata->angle);
	//SI VAMOS HACIA ARRIBA INVERTIMOS STEP Y
	if (!down)
		y_step = -y_step;
	//COMPROBAMOS QUE EL PASO X ES COHERENTE
	if ((left && x_step > 0) || (!left && x_step < 0))
		x_step = -x_step;
	float	next_x_hor = x_intercept;
	float	next_y_hor = y_intercept;
	//SI APUNTA HACIA ARRIBA RESTO UN PIXEL PARA FORZAR LA COLISIÓN CON LA CASILLA
	if (!down)
		next_y_hor--;
	//DONDE EL RAYO HACE COLISION
	int wall_hit_x = 0;
	int wall_hit_y = 0;

	int wall_hit_x_hor = 0;
	int wall_hit_y_hor = 0;
	//BUCLE PARA BUSCAR PUNTO DE COLISIÓN
	while (!hor_hit)
	{
		//OBTENEMOS LA CASILLA (REDONDEANDO POR ABAJO)
		if (player_colision(next_y_hor, next_x_hor, gdata))
		{
			hor_hit = 1;
			wall_hit_x_hor = next_x_hor;
			wall_hit_y_hor = next_y_hor;
		}
		else
		{
			next_x_hor += x_step;
			next_y_hor += y_step;
		}
	}
	//COLISIÓN VERTICAL
	int ver_hit = 0;

	//BUSCAMOS LA PRIMERA INTERSECCIÓN
	x_intercept = gdata->pdata->x;
	if (!left)
		x_intercept += TILE_SIZE;
	//SE LE SUMA EL CATETO OPUESTO
	float op = (x_intercept - gdata->pdata->x) * tan(gdata->pdata->angle);
	y_intercept = gdata->pdata->y + op;

	//CALCULAMOS LA DISTANCIA DE CADA PASO
	x_step = TILE_SIZE;

	//SI VA A LA IZQUIERDA, INVERTIMOS
	if (left)
		x_step *= -1;
	y_step = tan(gdata->pdata->angle) * TILE_SIZE;
	//CONTROLAMOS EL INCREMENTO DE Y, NO SEA QUE ESTE INVERTIDO
	if ((y_step > 0 && !down) || (y_step < 0 && down))
		y_step *= -1;

	float next_x_vert = x_intercept;
	float next_y_vert = y_intercept;
	if (left)
		next_y_vert--;
	int wall_hit_x_vert = 0;
	int wall_hit_y_vert = 0;
	//BUCLE CON SALTOS PARA DETECTAR COLISIÓN
	while (!ver_hit && (next_x_vert >= 0 && next_y_vert >= 0 && next_x_vert < gdata->width && next_y_vert < gdata->height))
	{
		//OBTENEMOS LA CASILLA REDONDEANDO POR ABAJO
		if (player_colision(next_y_vert, next_x_vert, gdata))
		{
			ver_hit = 1;
			wall_hit_x_vert = next_x_vert;
			wall_hit_y_vert = next_y_vert;
		}
		else
		{
			next_x_vert += x_step;
			next_y_vert += y_step;
		}
	}
	wall_hit_x = wall_hit_x_vert;
	wall_hit_y = wall_hit_y_vert;
	int hor_dist = 99999999;
	int ver_dist = 99999999;
	if (hor_hit)
		hor_dist = get_distance(gdata->pdata->x, gdata->pdata->y, wall_hit_x_hor, wall_hit_y_hor);
	if (ver_hit)
		ver_dist = get_distance(gdata->pdata->x, gdata->pdata->y, wall_hit_x_vert, wall_hit_y_vert);
	gdata->rdata->h_dist = ver_dist * gdata->h_prop;
	//COMPARAMOS LAS DISTANCIAS
	if (hor_dist < ver_dist)
	{
		wall_hit_x = wall_hit_x_hor;
		wall_hit_y = wall_hit_y_hor;
		gdata->rdata->h_dist = hor_dist * gdata->w_prop;
	}
	draw_all(gdata, wall_hit_x, wall_hit_y);
}
