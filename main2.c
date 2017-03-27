#include "libft.h"
#include "ft_printf.h"
#include <limits.h>

int main()
{
	int i;
	int j;
	i = 0;
	j = 0;
	char *nul = NULL;
	i = ft_printf("{%05.s}", 0);
	
	
	printf("\n -- -- -- --\n");
	
	
	j = printf("{%05.s}", 0);
	
	
	printf("\n\n");
	
	
	printf("\n\nft_printf:	%d\nprintf:		%d\n", i, j);
	return (0);
}
