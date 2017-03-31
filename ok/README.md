Our fourth project in UNIT Factory.

Our task was to recode printf functions using this functions:
◦ write,
◦ malloc,
◦ free,
◦ exit,
◦ The functions of man 3 stdarg

And our libft.

ft_printf(const char *format, )

My printf can manage the following 20 conversions: s, S, p, d, D, i, o, O, u, U, x, X, c, C, e, E, f, F, g, G, b(binary).

Also it can manage the flags #, 0, -, + and space.

Also you can use width and precision, passed in string or as argument by using '*' in string.

And modificators such as: hh, h, l, ll, j, z.

Also you can use colors for example:

ft_printf("{red}This text will be red{eoc}");

{eoc} - end color.

Avialable such colors:

black, red, green, yellow, blue, magenta, cyan, d_gray, l_red, l_green, l_yellow, l_blue.

And this text decorations: bold, underlined.
