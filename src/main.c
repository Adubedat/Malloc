#include "malloc.h"


int main() {
	char	*memory;
	char	*memory1;
	char	*memory2;
	char	*memory3;
	char	*memory4;
	char	*memory5;
	char	*memory6;
	char	*memory7;
	char	*memory8;
	char	*tmp;
	int		i = 0;
	int		j = 0;

	if ((memory = (char*)malloc(50)) == NULL)
		printf("malloc failed\n");
	if ((memory1 = (char*)malloc(50)) == NULL)
		printf("malloc failed\n");
	if ((memory2 = (char*)malloc(50)) == NULL)
		printf("malloc failed\n");
	if ((memory3 = (char*)malloc(500)) == NULL)
		printf("malloc failed\n");
	if ((memory4 = (char*)malloc(500)) == NULL)
		printf("malloc failed\n");
	if ((memory5 = (char*)malloc(500)) == NULL)
		printf("malloc failed\n");
	if ((memory6 = (char*)malloc(5000)) == NULL)
		printf("malloc failed\n");
	if ((memory7 = (char*)malloc(5000)) == NULL)
		printf("malloc failed\n");
	if ((memory8 = (char*)malloc(5000)) == NULL)
		printf("malloc failed\n");
	ft_memset(memory, 0x41, 50);
	ft_memset(memory1, 0x42, 50);
	ft_memset(memory2, 0x43, 50);
	ft_memset(memory3, 0x44, 500);
	ft_memset(memory4, 0x45, 500);
	ft_memset(memory5, 0x46, 500);
	ft_memset(memory6, 0x44, 5000);
	ft_memset(memory7, 0x45, 5000);
	ft_memset(memory8, 0x46, 5000);
	show_alloc_mem();
/*	while (i < 103)
	{
		j = 0;
		if ((memory1 = (char*)malloc(64)) == NULL)
			printf("malloc failed\n");
		while (j < 64)
		{
			memory1[j] = 'X';
			j++;
		}
		i++;
	}*/
//	free(memory2);
//	free(memory1);
//	memory = malloc(64);
//	memory = ft_strcpy(memory, "ttttttttttttttttestestestestestestestestestestet");
//	free(memory);
//	ft_hexdump(memory-16, 512);
//	printf("\n\n\n---\n\n\n");
//	ft_hexdump(memory3-16, 2048);
//	memory4 = realloc(memory4, 5000);
//	memory5 = realloc(memory5, 5000);
//	printf("\n\n\n---\n\n\n");
//	ft_hexdump(memory-16, 512);
//	printf("\n\n\n---\n\n\n");
//	ft_hexdump(memory3-16, 2048);
//	memory2 = malloc(5000);
//	memory = realloc(memory, 900);
//	printf("\n\n\n---\n\n\n");
//	ft_hexdump(memory-16, 512);
//	memory3 = malloc(4097);
//	printf("\n\n\n---\n\n\n");
//	ft_hexdump(memory3-16, 512);
	return (0);
}
