#include "../../includes/cub3d.h"

static void	draw_first_part_map(t_gdata *gdata)
{
	int	x;
	int	y;
	int	middle;

	x = -1;
	middle = MAP_HEIGHT / 2;
	while (++x < MAP_WIDTH)
	{
		y = 0;
		while (++y < middle)
			my_mlx_pixel_put(gdata->mdata, x, y, parse_color(gdata->f));
		while (++y < MAP_HEIGHT)
			my_mlx_pixel_put(gdata->mdata, x, y, parse_color(gdata->c));
	}
}

static void	draw_dir_line(float x_line, float y_line, t_gdata *gdata)
{
	float	aux_px;
	float	aux_py;

	aux_px = gdata->pdata->x;
	aux_py = gdata->pdata->y;
	float c1 = x_line - aux_px;
	float c2 = y_line - aux_py;
	int hip = sqrt(pow(c1, 2) + pow(c2, 2));
//	printf("--------\n");
//	printf("X_LINE: %f\n", x_line);
//	printf("Y_LINE: %f\n", x_line);
//	printf("PX: %f\n", aux_px);
//	printf("PY: %f\n", aux_py);
//	printf("HIP: %d\n", hip);
//	printf("ANGLE: %f\n", pdata->angle);
//	printf("----------\n");
//	printf("Y: %f\n", y_line);
//	printf("HIP: %d\n", hip);
	int c = 0;
	while (c < hip)
	{
		my_mlx_pixel_put(gdata->mdata, aux_px, aux_py, parse_color("0, 0, 0"));
		if (aux_px < x_line)
			aux_px++;
		if (aux_py < y_line)
			aux_py++;
		if (aux_px > x_line)
			aux_px--;
		if (aux_py > y_line)
			aux_py--;
		c++;
	}
}

/*static void	draw_col_line(int x_dest, int y_dest, t_gdata *gdata)
{
	float	aux_px;
	float	aux_py;

	printf("----------COL:\n");
	printf("X_DEST: %d\n", x_dest);
	printf("Y_DEST: %d\n", y_dest);
	aux_px = gdata->pdata->x;
	aux_py = gdata->pdata->y;
	printf("AUX_PX: %f\n", aux_px);
	printf("AUX_PY: %f\n", aux_py);
	printf("---------------\n");
}*/

void	draw_all(t_gdata *gdata, int x_dest, int y_dest)
{
	float	x_line;
	float	y_line;

	printf("XDEST: %d\n", x_dest);
	printf("YDEST: %d\n", y_dest);
	x_line = gdata->pdata->x + cos(gdata->pdata->angle) * 20;
	y_line = gdata->pdata->y + sin(gdata->pdata->angle) * 20;

	gdata->mdata->win_img = mlx_new_image(gdata->mdata->ptr, MAP_WIDTH, MAP_HEIGHT);
	gdata->mdata->win_addr = mlx_get_data_addr(gdata->mdata->win_img, &gdata->mdata->bpp_win, &gdata->mdata->ll_win, &gdata->mdata->end_win);
	draw_first_part_map(gdata);
//	draw_col_line(x_dest, y_dest, gdata);
	draw_dir_line(x_line, y_line, gdata);
	my_mlx_pixel_put(gdata->mdata, gdata->pdata->x, gdata->pdata->y, parse_color("0, 0, 0"));
	mlx_put_image_to_window(gdata->mdata->ptr, gdata->mdata->win, gdata->mdata->win_img, 0, 0);
//	printf("----------------\n");
}
