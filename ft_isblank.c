#include "include/libft.h"

int		ft_isblank(char c)
{
	if (c == '\t' || c == '\n' || c == ' ')
		return (1);
	return (0);
}
