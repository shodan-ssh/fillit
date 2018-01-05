/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: almalfoy <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/05 15:23:48 by almalfoy     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/05 15:23:49 by almalfoy    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef __FT_LIBFT_H
# define __FT_LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;
int				ft_isprint(int c);
int				ft_isdigit(int c);
int				ft_isascii(int c);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
void			ft_strclr(char *s);
char			*ft_strchr(char *s, int c);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_atoi(char *str);
void			ft_putchar(char c);
size_t			ft_strlen(char *str);
char			*ft_strdup(char *s1);
void			ft_putstr(char *str);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strcpy(char *src, char *dest);
char			*ft_strncpy(char *dest, char *src, size_t len);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strchr(char *s, int c);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strncat(char *dest, char *src, int n);
int				ft_tolower(int c);
int				ft_toupper(int c);
char			*ft_strrchr(char *s, int c);
int				ft_strncmp(char *s1, char *s2, int n);
char			*ft_strstr(char *haystack, char *needle);
char			*ft_strnstr(char *haystack, char *needle, size_t len);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memcpy(void *dst, void *src, size_t n);
void			*ft_memccpy(void *dst, void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(void *s, int c, size_t n);
void			*ft_memalloc(size_t size);
void			ft_bzero(void *s, size_t n);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *str, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putendl(char const *s);
void			ft_putnbr(int nb);
void			ft_putnbr_fd(int nb, int fd);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
void			ft_striter(char *s, void (*f)(char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

#endif
