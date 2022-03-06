#include <mlx.h>

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	int	i = 0;
	int j = 0;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 256, 256, "Hello world!");
	mlx_loop(mlx);
	mlx_pixel_put(&mlx, &mlx_win, 1, 1, 0x00FF0000);
	while (i < 256)
	{
		while(j < 256)
		{
			mlx_pixel_put(&mlx, &mlx_win , i, j++, 0x00FFFFFF);
		}
		i++;
		j = 0;
	}
}