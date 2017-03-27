#include "libft.h"
#include "ft_printf.h"
#include <limits.h>



int main()
{
	int		n;
	int		m;
	int		i;
	int		j;
	unsigned char	k;
	int		i1;
	int		i2;
	char	*str;
	char	c;

	i = 0;
	j = 0;
	char *nul = NULL;
printf("%s\n--intmax avec %%hlhx en hex--%s\n", KBLU, KNRM);
	n = 2147483647;
	i = ft_printf("Mon printf  : %hlhx\n", n);
	j = printf("Vrai printf : %hlhx\n", n);
	printf("Moi %d Le vrai : %d\n", i, j);

	printf("%s\n--unsigned char 128 en hex--%s\n", KBLU, KNRM);
	k = 128;
	i = ft_printf("Mon printf  : %hhx\n", k);
	j = printf("Vrai printf : %hhx\n", k);
	printf("Moi %d Le vrai : %d\n", i, j);

printf("\n--%%--\n");
	i = ft_printf("Mon printf  : %%\n");
	j = printf("Vrai printf : %%\n");
	printf("Moi %d Le vrai : %d\n", i, j);

	printf("\n-- int with + and precision --\n");
	n = 13;
	i = ft_printf("Mon printf  : %+.5d\n", n);
	j = printf("Vrai printf : %+.5d\n", n);
	printf("Moi %d Le vrai : %d\n", i, j);






	i = ft_printf("%zu, %zu", 0, ULLONG_MAX);
	
	
	printf("\n -- -- -- --\n");
	
	
	j = printf("%zu, %zu", 0, ULLONG_MAX);
	
	
	printf("\n\n");
	
	
	printf("\n\nft_printf:	%d\nprintf:		%d\n", i, j);
	return (0);
}
