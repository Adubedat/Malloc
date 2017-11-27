#include "malloc.h"


int main() {
	char	*memory;
	char	*memory1;
	char	*memory2;
	char	*memory3;
	char	*tmp;
	int		i = 0;
	int		j = 0;

	if ((memory = (char*)my_malloc(64)) == NULL)
		printf("malloc failed\n");
	if ((memory1 = (char*)my_malloc(64)) == NULL)
		printf("malloc failed\n");
	if ((memory2 = (char*)my_malloc(64)) == NULL)
		printf("malloc failed\n");
	if ((memory3 = (char*)my_malloc(64)) == NULL)
		printf("malloc failed\n");
	memory = ft_strcpy(memory, "ttttttttttttttttestestestestestestestestestestet");
	while (i < 103)
	{
		j = 0;
		if ((memory1 = (char*)my_malloc(64)) == NULL)
			printf("malloc failed\n");
		while (j < 64)
		{
			memory1[j] = 'X';
			j++;
		}
		i++;
	}
	ft_hexdump(memory, 8132);
	my_free(memory1);
//	memory = (char*)my_malloc(33);
//	memory = ft_strcpy(memory, "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
	return (0);
}
