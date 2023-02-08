#include "../../includes/cub3d.h"

void	init_rdata(t_gdata *gdata)
{
	int i;

	i = 0;
	gdata->rdata->n_rays = gdata->width;
	gdata->rdata->angle_inc = to_radians(FOV / gdata->rdata->n_rays);
	gdata->rdata->angle_init = to_radians(gdata->pdata->angle - HALF_FOV);
	gdata->rdata->angle_ray = gdata->rdata->angle_init;
	gdata->rdata->ray = malloc(gdata->rdata->n_rays * sizeof(t_ray));
	if (!gdata->rdata->ray)
		return ;
	while (i < gdata->rdata->n_rays)
	{
		gdata->rdata->ray[i].angle_inc = gdata->rdata->angle_ray;
		gdata->rdata->angle_ray += gdata->rdata->angle_inc;
		i++;
	}
}