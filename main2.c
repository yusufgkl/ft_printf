#include "ft_printf.h"
#include "libft.h"

int main()
{
	int i;
	int j;
	i = ft_printf("%s", "abcd");
	printf("\n");
	j = printf("%s", "abcd");
	printf("\n\n");
	printf("\n\nft: %d\nprintf: %d\n", i, j);
	return (0);
}
