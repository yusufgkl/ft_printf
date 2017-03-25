#include "ft_printf.h"
#include "libft.h"
#include <limits.h>

int main()
{
	int i;
	int j;
	int x = 42;
	char *nul = "\0";
	i = 0;
	j = 0;
	i = ft_printf("%.d, %.0d", 0, 0);
	printf("\n -- -- -- --\n");
	j = printf("%.d, %.0d", 0, 0);
	printf("\n\n");
	printf("\n\nft_printf:	%d\nprintf:		%d\n", i, j);
	return (0);
}
