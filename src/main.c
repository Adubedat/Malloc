#include "malloc.h"


int main() {
	char	*memory;
	char	*tmp;
	int		i = 0;
	int		j = 0;

	if ((memory = (char*)my_malloc(4097)) == NULL)
		printf("malloc failed\n");
	memory = ft_strcpy(memory, "ttttttttttttttttestestestestestestestestestestet");
	tmp = memory;
	while (i < 107)
	{
		j = 0;
		memory = (char*)my_malloc(4097);
		while (j < 4097)
		{
			memory[j] = 'X';
			j++;
		}
		i++;
		ft_hexdump(memory - 8, 8192);
	}
	memory = (char*)my_malloc(33);
	memory = ft_strcpy(memory, "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
	return (0);
}
