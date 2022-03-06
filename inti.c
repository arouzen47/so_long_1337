#include <mlx.h>
#include <stdio.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct graphix
{
	void	*mlx;
	void	*win;
	t_data	img;
}	gix;

int	move_hook(int	keycode, gix *visual)
{
	static int i = 0;
	static int j = 0;
	int		step = 36;

	if (keycode == 13 && i <= 720 && j <= 720 && i >= 0 && j > 0)
		j -= step;
	if (keycode == 1 && i < 720 && j < 720 && i >= 0 && j >= 0)
		j += step;
	if (keycode == 2 && i < 720 - 2 * step && j <= 720 && i >= 0 && j >= 0)
		i += step;
	if (keycode == 0 && i <= 720 - 2 * step && j < 720 && i > 0 && j >= 0)
		i -= step;
	mlx_clear_window((*visual).mlx, (*visual).win);
	mlx_put_image_to_window((*visual).mlx,(*visual).win, (*visual).img.img, i, j);
	return (0);
}
void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main()
{
	//void	*mlx;
	//void	*win;
	// int		i = 0;
	// int		j = 0;
	int		img_width;
	int		img_height;
	gix visual;
	
	visual.mlx = mlx_init();
	visual.win = mlx_new_window(visual.mlx, 720,720,"so_long");
	if (!( visual.img.img =  mlx_xpm_file_to_image(visual.mlx, "./tile.xpm", &img_width, &img_height)))
	{
		return (0);
		printf("Wizzzzz\n");
	}
	//img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// while (i < 720)
	// {
	// 	while(j < 720)
	// 		ft_mlx_pixel_put(&img, i, j++, 0x00FFFFFF);
	// 	i++;
	// 	j = 0;
	// }
	// while ( i < 12 * px)
	// {
	// 	mlx_put_image_to_window(visual.mlx, visual.win, visual.img->img, i, j);
	// 	i += 37;
	// 	j += 37;
	// }
	mlx_hook(visual.win, 2, 0, move_hook, &visual);
	//mlx_put_image_to_window(mlx, win, img.img, 38, 0);                                    
	mlx_loop(visual.mlx);
	return (0);
}