/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 14:13:14 by ajimenez          #+#    #+#             */
/*   Updated: 2023/01/08 15:46:52 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*
**Required Libraries
*/
# include <stdio.h>
# include <stdlib.h>
# include <sys/_types/_size_t.h>
# include <sys/_types/_ssize_t.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct s_dlist
{
	void			*content;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}				t_dlist;

typedef struct s_matrix_data
{
	ssize_t		line_count;
	ssize_t		*lenght_str;
	ssize_t		max;
	ssize_t		min;
}	t_matrix_data;

/*
**Dlst Library
*/
void	ft_dlstadd_back(t_dlist **dlst, t_dlist *new);
void	ft_dlstadd_front(t_dlist **lst, t_dlist *new);
void	ft_dlstclear(t_dlist **lst, void (*del)(void *));
void	ft_dlstdelone(t_dlist *lst, void (*del)(void *));
t_dlist	*ft_lstnew_struct(void *newcontent, size_t size);
t_dlist	*ft_dlstlast(t_dlist *lst);
t_dlist *ft_dlstnew(void *content);
int		ft_dlstsize(t_dlist *lst);

/*
**Is Library
*/
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_isalnum(int c);
int				ft_isspace(int c);
int				ft_str_have_space(char *av);

/*
**Str Library
*/
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *s);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
void			ft_strcpy(char *dst, const char *src);
unsigned int	ft_strlcat(char *dst, const char *src, size_t dstsize);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *haystack, const char *needle,
					size_t	len);
void			*ft_calloc(size_t num, size_t size);
char			*ft_strdup(const char *s1);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			**ft_split(char const *s, char c);
void			ft_free_matrix(char **matrix);
int				ft_iter_str_bool(char *str, int (*f)(int));
char			*get_next_line(int fd);
ssize_t			ft_max_int(ssize_t *str, ssize_t len);
ssize_t			ft_min_int(ssize_t *str, ssize_t len);
size_t			count_chars(char c, char *str);
/*
**Matrix Library
*/
int				ft_iter_matrix_bool(char **str, int (*f)(int));
size_t			ft_matrixlen(char **matrix);
t_matrix_data	ft_matrix_data(char **matrix);

/*
**To Library
*/
int				ft_atoi(const char *str);
int				ft_tolower(int c);
int				ft_toupper(int c);
char			*ft_itoa(int n);
long			ft_atob(const char *s);
int				ft_boti(long binary);

/*
** Put Library
*/
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putnbr_fd(int nb, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putmatrix(char **s, size_t lines);

/*
** LST - BONUS
*/

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

#endif
