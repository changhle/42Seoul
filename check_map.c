char	*check_map(char **map)
{
	map = (char **)malloc(sizeof(char *) * 6);
	while (param->hight < 5)
	{
		if (param->hight == 0 || param->hight == 4)
		{
			map[param->hight] = get_next_line(fd);
			if (param->width == 0)
				param->width = ft_strlen(map[param->hight]) - 1;
			else if (param->width != ft_strlen(map[param->hight] - 1))
				error;
			while (i < param->width)
			{
				if (map[param->width][i] != 1)
					error;
			}
		}
		else if (param->hight > 0 && param->hight < 4)
		{
			map[param->hight] = get_next_line(fd);
			if (param->width != ft_strlen(map[param->hight] - 1))
				error;
			if (map[0] == 0 || map[param->hight] == 0)
				error;
		}
	}
	if (ft_strlen(get_next_line(fd)) > 0)
		error;
}