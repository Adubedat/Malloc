#include "malloc.h"


int main() {
	char	*memory;
	char	*tmp;
	int		i = 0;

	memory = (char*)my_malloc(64);
	memory = ft_strcpy(memory, "ttttttttttttttttestestestestestestestestestestet");
	tmp = memory;
	while (i < 150)
	{
		memory = (char*)my_malloc(64);
		memory = ft_strcpy(memory, "ttttttttttttttttestestestestestestestestestestettt");
		i++;
	}
	ft_hexdump(tmp, 8136);
	return (0);
}
