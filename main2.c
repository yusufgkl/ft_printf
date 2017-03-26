#include "libft.h"
#include "ft_printf.h"
#include <limits.h>

int main()
{
	int i;
	int j;
	i = 0;
	j = 0;
	
	i = ft_printf("%zu, %zu", 0, ULLONG_MAX);
	
	
	printf("\n -- -- -- --\n");
	
	
	j = printf("%zu, %zu", 0, ULLONG_MAX);
	
	
	printf("\n\n");
	
	
	printf("\n\nft_printf:	%d\nprintf:		%d\n", i, j);
	return (0);
}
