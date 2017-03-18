#include "ft_printf.h"
#include "libft.h"

int main()
{
	void *p_pointer = (void*)12345;
	
	ft_printf("\x1B[32m======= TEST  PRINTF =======\n");
	ft_printf("= Conversions sSpdDioUxXcC = \x1B[0m\n\n");
	ft_printf("s: %s - Affichage d'une string oklm\n", "string");
	//ft_printf("S: %S\n", string);
	ft_printf("p: %p - Pointeur void * en hexa\n", p_pointer);
	ft_printf("d: %d - Decimale oklm\n", 123);
	ft_printf("D: %D - Convertit le long int en signed decimal\n", -123);
	ft_printf("i: %i - int to signed decimal\n", 123);
	ft_printf("o: %o - int to unsigned octal\n", -123);
	printf("po: %o - int to unsigned octal\n", -123);
	ft_printf("O: %O - Convertit le long int en unsigned octal\n", 123);
	ft_printf("u: %i - int to unsigned decimal\n", 123);
	ft_printf("U: %U - Convertit le long int en unsigned decimal \n", -123);
	ft_printf("x: %x - int to unsigned hexadecimal\n", 123);
	ft_printf("X: %X - int to unsigned hexadecimal\n", 123);
	ft_printf("C: %C - int to unsigned wchar_t\n", 123);
	ft_printf("c: %c - int to unsigned char\n", 123);
	ft_printf("%%: %% - Affichage de %%\n");
	ft_printf("\n\x1B[32m= Flags # 0 - + et space = \x1B[0m\n\n");
	ft_printf("#:%#o - Ajoute un 0 a gauche\n", 123);
	ft_printf("0:%04d - padding de 4 avec des 0\n", 3);
	ft_printf("-:%-d - ajoute un - si neg\n", -123);
	ft_printf("+: %+d - Place un signe sur une conversion signed\n", +123);
	ft_printf("space: |% d| - Ajoute un space a gauche d'une conversion signed\n", 123);
	ft_printf("\n\x1B[32m= Modif hh h l ll j z = \x1B[0m\n\n");
	ft_printf("\n\x1B[34m= d, i\x1B[0m\n\n");
	ft_printf("ft_printf	hd: %hd \n", 123456);
	printf("printf		hd: %hd\n", 123456);

	ft_printf("ft_printf	hhd: %hhd\n", 'p');
	printf("printf		hhd: %hhd\n", 'p');
	ft_printf("ft_printf	ld: %ld\n", 123456789);
	printf("printf		ld: %ld\n", 123456789);
	ft_printf("ft_printf	lld: %lld\n", 123456789);
	printf("printf		lld: %lld\n", 123456789);
	ft_printf("ft_printf	j: %jd\n", 123456789);
	printf("printf		j: %jd\n", 123456789);
	ft_printf("ft_printf	z: %zd\n", 123456789);
	printf("printf		z: %zd\n", 123456789);
	
	ft_printf("\n\x1B[34m=================\x1B[0m\n\n");
	ft_printf("\n\x1B[34m= o, u, x, X\x1B[0m\n\n");

	ft_printf("\n\x1B[34m=	Flag	d, i			o, u x, X\x1B[0m\n\n");
	ft_printf("	hh	Signed char		unsigned char\n");
	ft_printf("	h	short			unsigned short\n");
	ft_printf("	l	long			unsigned long\n");
	ft_printf("	ll	long long		unsigned long long\n");
	ft_printf("	j	intmax_t		uintmax_t\n");
	ft_printf("	z	N/A			size_t\n");
	
	
	
	ft_printf("\nNormal \e[4m Souligne \n");
	return (0);
}
