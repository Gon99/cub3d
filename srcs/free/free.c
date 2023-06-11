#include "../../includes/cub3d.h"

void free_tex(t_tdata *tdata)
{
	int i;

	i = 0;
	while (i < 4)
	{
		free(tdata->tex_arr[i]);
		i++;
	}
	free(tdata->tex_arr);
}

void	free_map(t_gdata *gdata)
{
	int i;
	
	i = 0;
	printf("1\n");
	while (gdata->file[i])
	{
		free(gdata->file[i]);
		i++;
	}
	free(gdata->map);
	free(gdata->file);
}
