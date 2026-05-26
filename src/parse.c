#include "cub3d.h"

int	parse(t_data *data)
{
	if (validate_params(data) != SUCCESS)
		return (FAIL);
	if (validate_map(data) != SUCCESS)
		return (FAIL);
	return (SUCCESS);
}
