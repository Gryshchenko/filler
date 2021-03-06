/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:51:05 by vgryshch          #+#    #+#             */
/*   Updated: 2018/03/27 18:22:17 by vgryshch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFF_SIZE 1
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_cord
{
	int				x;
	int				y;
	struct s_cord	*next;
}					t_cord;

typedef struct		s_data
{
	int				fd;
	char			buff[BUFF_SIZE + 1];
	char			*p;
	struct s_data	*next;
}					t_data;

int					get_next_line(const int fd, char **line);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void*dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
size_t				ft_strwlen(const wchar_t *s);
int					ft_wcslen(wchar_t c);
char				*ft_strdup(const char *str);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *lit, size_t len);
int					ft_strcmp(const char *string1, const char *string2);
int					ft_strncmp(const char *string1, const char *str2, size_t n);
char				*ft_strncat(char *destprt, const char *srcptr, size_t num);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strcat(char *destprt, const char *srcptr);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_arraydell(char **array);
void				ft_arraydell_u(unsigned char **array);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
void				ft_putchar(char c);
void				ft_putchar_u(unsigned char c);
void				ft_putwchar(wchar_t chr);
void				ft_putstr(char const *s);
void				ft_putwstr(wchar_t *s);
void				ft_putarray(char **array);
void				ft_putarray_u(unsigned char **array);
void				ft_putendl(char const *s);
char				*ft_itoa(int n);
char				*ft_itoa_long(long long n);
char				*ft_itoa_unsigned(unsigned int n);
char				*ft_itoa_unsigned_long(unsigned long long n);
char				*ft_itoa_base_16(unsigned long long nb);
char				*ft_itoa_base_up_16(unsigned long long nb);
char				*ft_itoa_base_8(unsigned long long nbr);
char				*ft_itoa_base(int value, int base);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
t_cord				*ft_lstnew_fill(int y, int x);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_listprint(t_list *alst);
t_list				*ft_listlast(t_list *alst);
int					ft_listlen(t_list *alst);
void				ft_free(t_list *head);
int					ft_counter_int(int n);
char				*ft_strrev(char *str);
int					ft_counter_bits(unsigned long long nbr);
unsigned char		*ft_wchartostring(wchar_t chr);
#endif
