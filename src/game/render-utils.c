/* static void	draw_texture_fullscreen(t_game *g)
{
	int	x;
	int	y;
	int	color;
	int	tex_x;
	int	tex_y;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			// scale screen -> texture
			tex_x = x * g->textures[0].w / WIN_W;
			tex_y = y * g->textures[0].h / WIN_H;
			color = get_tex_color(&g->textures[0], tex_x, tex_y);
			put_pixel(&g->img, x, y, color);
			x++;
		}
		y++;
	}
} */

/* static void	draw_texture_raw(t_game *g)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < g->textures[0].h && y < WIN_H)
	{
		x = 0;
		while (x < g->textures[0].w && x < WIN_W)
		{
			color = get_tex_color(&g->textures[0], x, y);
			put_pixel(&g->img, x, y, color);
			x++;
		}
		y++;
	}
} */

/* static void	draw_texture_centered(t_game *g)
{
	int	x;
	int	y;
	int	start_x;
	int	start_y;

	start_x = (WIN_W - g->textures[0].w) / 2;
	start_y = (WIN_H - g->textures[0].h) / 2;
	

	y = 0;
	while (y < g->textures[0].h)
	{
		x = 0;
		while (x < g->textures[0].w)
		{
			put_pixel(&g->img, start_x + x, start_y + y, get_tex_color(&g->textures[0], x, y));
			x++;
		}
		y++;
	}
} */


/* static void	draw_texture_column(t_game *g, int x, double dist, t_ray *r)
{
	t_img	*t;
	int		y;
	int		tex_x;
	int		tex_y;
	double	step;
	double	tex_pos;
	double	wall_x;

	t = get_wall_texture(g, r);
	
	if (r->side == 0)
		wall_x = g->player.pos_y + dist * r->ray_dy;
	else
		wall_x = g->player.pos_x + dist * r->ray_dx;
	
	wall_x -= floor(wall_x);
	
	tex_x = (int)(wall_x * t->w);

	// Voltear horizontalmente
	if (r->side == 0 && r->ray_dx < 0)
		tex_x = t->w - tex_x - 1;
	if (r->side == 1 && r->ray_dy > 0)
		tex_x = t->w - tex_x - 1;

	step = 1.0 * t->h / (r->draw_end - r->draw_start);

	tex_pos = (r->draw_start - WIN_H / 2 + (r->draw_end - r->draw_start) / 2) * step;

	y = r->draw_start;
	while (y <= r->draw_end)
	{
		tex_y = (int)tex_pos;
		tex_pos += step;

		put_pixel(&g->img, x, y, get_tex_color(t, tex_x, tex_y));
		y++;
	}
} */