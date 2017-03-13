/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygokol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 18:31:10 by ygokol            #+#    #+#             */
/*   Updated: 2017/03/13 13:46:46 by ygokol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIBFT_H
# define _LIBFT_H
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
void				ft_foreach(int *tab, int length, void (*f)(int));
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_itoa(int n);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *str, const void *str2, int c, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *str, const void *str2, size_t len);
void				ft_memdel(void **ap);
void				*ft_memmove(void *str, const void *str2, size_t len);
void				*ft_memset(void *str, int c, size_t len);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char *str);
void				ft_putendl_fd(char *str, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char *str);
void				ft_putstr_fd(char *str, int fd);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dest, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *src);
int					ft_strequ(char *s1, char *s2);
void				ft_striter(char *s, void(*f)(char *));
void				ft_striteri(char *s, void(*f)(unsigned int i, char *));
char				*ft_strjoin(char *s1, const char *s2);
size_t				ft_strlcat(char *s1, const char *s2, size_t n);
size_t				ft_strlen(const char *str);
char				*ft_strmap(char *s, char (*f)(char));
char				*ft_strmapi(char *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dest, const char *src, size_t len);
int					ft_strnequ(char *s1, char *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *big, const char *little,\
		size_t len);
char				*ft_strrchr(const char *s, int c);
char				**ft_strsplit(const char *s, char c);
char				*ft_strstr(char *big, char *little);
char				*ft_strsub(const char *s, unsigned int start, size_t len);
char				*ft_strtrim(const char *s);
void				ft_swap(int *a, int *b);
int					ft_tolower(int c);
int					ft_toupper(int c);

int					ft_numlen(int nb);
int					ft_charblank(char c);
void				ft_thuglife(void);
int					ft_strblank(const char *s);
int					ft_tablen(int *tab);
#endif
