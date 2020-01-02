/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:45:31 by fhenrion          #+#    #+#             */
/*   Updated: 2019/11/13 10:48:37 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef enum		e_bool
{
	false,
	true
}					t_bool;

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t len);
void				*ft_memccpy(void *dst, const void *src, int c, size_t len);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t len);
int					ft_memcmp(const void *s1, const void *s2, size_t len);
size_t				ft_strlen(const char *s);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t len);
size_t				ft_strlcpy(char *dst, const char *src, size_t len);
size_t				ft_strlcat(char *dst, const char *src, size_t len);
char				*ft_strnstr(const char *str, const char *sub, size_t len);
int					ft_atoi(const char *str);
void				*ft_calloc(size_t len, size_t size);
char				*ft_strdup(const char *s1);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int nb, int fd);
t_list				*ft_lstnew(void const *content);
void				ft_lstadd_front(t_list **alst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstclear(t_list **lst, void (*del)(void*));
void				ft_lstiter(t_list *lst, void (*f)(void *elem));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *elem), \
					void (*del)(void *));
t_list				*ft_lstat(t_list *lst, size_t index);
void				ft_putstrlst_fd(t_list *lst, char separator, int fd);
void				ft_putnbrlst_fd(t_list *lst, char separator, int fd);
void				ft_lstreverse(t_list **lst);
void				ft_lstmerge(t_list *lst1, t_list *lst2);
int					ft_isspace(int c);
void				ft_memdel(void **ap);
void				ft_putchar(char c);
void				ft_putendl(char const *s);
void				ft_putnbr(int nb);
void				ft_putstr(char const *s);
int					ft_strchri(const char *s, int c);
int					ft_strrchri(const char *s, int c);
char				*ft_substrchr(const char *s, char c);
char				*ft_substrrchr(const char *s, char c);
int					ft_strcmp(const char *s1, const char *s2);
void				ft_tabstrsort(char **tab);
void				ft_tabstrrsort(char **tab);
t_list				*ft_lstchrsplit(const char *s, char c);
void				ft_lststrsort(t_list *lst);
void				ft_lststrrsort(t_list *lst);
void				ft_putstrtab_fd(char **tab, char separator, int fd);

#endif
