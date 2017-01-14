#include <stdio.h>

int main()
{
	void *p_pointer = (void*)12345;
	
	printf("\x1B[32m======= TEST  PRINTF =======\n");
	printf("= Conversions sSpdDioUxXcC = \x1B[0m\n\n");
	printf("s: %s - Affichage d'une string oklm\n", "string");
	//printf("S: %S\n", string);
	printf("p: %p - Pointeur void * en hexa\n", p_pointer);
	printf("d: %d - Decimale oklm\n", 123);
	printf("D: %D - Convertit le long int en signed decimal\n", -123);
	printf("i: %i - int to signed decimal\n", 123);
	printf("o: %o - int to unsigned octal\n", 123);
	printf("O: %O - Convertit le long int en unsigned octal\n", -123);
	printf("u: %i - int to unsigned decimal\n", 123);
	printf("U: %U - Convertit le long int en unsigned decimal \n", -123);
	printf("x: %x - int to unsigned hexadecimal\n", 123);
	printf("X: %X - int to unsigned hexadecimal\n", 123);
	printf("C: %C - int to unsigned wchar_t\n", 123);
	printf("c: %c - int to unsigned char\n", 123);
	printf("%%: %% - Affichage de %%\n");
	printf("\n\x1B[32m= Flags # 0 - + et space = \x1B[0m\n\n");
	printf("#: %#o - Ajoute un 0 a gauche\n", 123);
	printf("0: %0d - N/A\n", 123);
	printf("-: %-d - N/A\n", 123);
	printf("+: %+d - Place un signe sur une conversion signed\n", 123);
	printf("space: % d - Ajoute un space a gauche d'une conversion signed\n", 123);
	printf("\n\x1B[32m= Flags hh h l ll j z = \x1B[0m\n\n");
	printf("\n\x1B[34m=	Flag	d, i			o, u x, X			n = \x1B[0m\n\n");
	printf("	hh	Signed char		unsigned char		signed char *\n");
	printf("	h	short			unsigned short		short *\n");
	printf("	l	long			unsigned long		long *\n");
	printf("	ll	long long		unsigned long long	long long *\n");
	printf("	j	intmax_t		uintmax_t		intmax_t *\n");
	printf("	z	N/A			size_t			N/A\n");
	return (0);
}
