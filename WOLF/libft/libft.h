/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 13:48:50 by vtiterin          #+#    #+#             */
/*   Updated: 2016/11/24 15:02:53 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 24
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_gnl
{
	char			*buf;
	int				fd;
	struct s_gnl	*next;
}					t_gnl;

int					get_next_line(const int fd, char **line);
void				ft_bzero(void *str, size_t lenght);
void				*ft_memset(void *memptr, int val, size_t num);
void				*ft_memccpy(void *destt, const void *s, int c, size_t n);
void				*ft_memcpy(void *destptr, const void *srcptr, size_t num);
void				*ft_memchr(const void *str, int ch, size_t num);
void				*ft_memmove(void *dest, const void *s, size_t num);
char				*ft_strcpy(char *destptr, const char *srcptr);
char				*ft_strncpy(char *destptr, const char *srcptr, size_t num);
char				*ft_strcat(char *destptr, const char *srcptr);
char				*ft_strncat(char *destptr, char *srcptr, size_t num);
char				*ft_strchr(const char *string, int symbol);
char				*ft_strrchr(const char *string, int symbol);
char				*ft_strstr(const char *str1, const char *str2);
char				*ft_strdup(const char *src);
char				*ft_strnstr(const char *big, const char *l, size_t len);
size_t				ft_strlen(const char *string);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
int					ft_memcmp(const void *dest, const void *source, size_t num);
int					ft_strcmp(const char *str1, const char *str2);
int					ft_strncmp(const char *str1, const char *str2, size_t num);
int					ft_atoi(const char *str);
int					ft_isalpha(int ch);
int					ft_isdigit(int ch);
int					ft_isalnum(int ch);
int					ft_isprint(int ch);
int					ft_isascii(int c);
int					ft_toupper(int ch);
int					ft_tolower(int ch);
void				ft_putstr(char const *s);
void				ft_putchar(char c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **ap);
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
char				*ft_itoa(int n);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstmap(t_list *list, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);

#endif
