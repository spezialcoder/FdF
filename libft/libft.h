/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsorg <lsorg@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 19:55:52 by lsorg             #+#    #+#             */
/*   Updated: 2024/04/17 20:59:56 by lsorg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

typedef unsigned long long	t_size_t;

typedef struct s_list
{
	void					*content;
	struct s_list			*next;
}							t_list;

struct						s_flags
{
	int						b;
	int						u;
	int						p;
};

int							ft_isalpha(int c);
int							ft_isdigit(int c);
int							ft_isalnum(int c);
int							ft_isascii(int c);
int							ft_isprint(int c);
t_size_t					ft_strlen(const char *s);
void						*ft_memset(void *b, int c, t_size_t len);
void						ft_bzero(void *s, t_size_t n);
void						*ft_memcpy(void *dst, const void *src, t_size_t n);
void						*ft_memmove(void *dst, const void *src,
								t_size_t len);
t_size_t					ft_strlcpy(char *dst, const char *src,
								t_size_t dstsize);
t_size_t					ft_strlcat(char *dst, const char *src,
								t_size_t dstsize);
int							ft_toupper(int c);
int							ft_tolower(int c);
char						*ft_strchr(const char *s, int c);
char						*ft_strrchr(const char *s, int c);
int							ft_strncmp(const char *s1, const char *s2,
								t_size_t n);
void						*ft_memchr(const void *s, int c, t_size_t n);
int							ft_memcmp(const void *s1, const void *s2,
								t_size_t n);
char						*ft_strnstr(const char *haystack,
								const char *needle, t_size_t len);
int							ft_atoi(const char *str);
void						*ft_calloc(t_size_t count, t_size_t size);
char						*ft_strdup(const char *s1);
char						*ft_substr(char const *s, unsigned int start,
								t_size_t len);
char						*ft_strjoin(char const *s1, char const *s2);
char						*ft_strtrim(char const *s1, char const *set);
char						**ft_split(char const *s, char c);
char						*ft_itoa(int n);
char						*ft_strmapi(char const *s, char (*f)(unsigned int,
									char));
void						ft_striteri(char *s, void (*f)(unsigned int,
									char *));
void						ft_putchar_fd(char c, int fd);
void						ft_putstr_fd(char *s, int fd);
void						ft_putendl_fd(char *s, int fd);
void						ft_putnbr_fd(int n, int fd);
t_list						*ft_lstnew(void *content);
void						ft_lstadd_front(t_list **lst, t_list *new);
int							ft_lstsize(t_list *lst);
t_list						*ft_lstlast(t_list *lst);
void						ft_lstadd_back(t_list **lst, t_list *new);
void						ft_lstdelone(t_list *lst, void (*del)(void *));
void						ft_lstclear(t_list **lst, void (*del)(void *));
void						ft_lstiter(t_list *lst, void (*f)(void *));
t_list						*ft_lstmap(t_list *lst, void *(*f)(void *),
								void (*del)(void *));
int							ft_printf(const char *format, ...);
int							pt_printstr(char *s);
int							pt_printchar(char c);
void						pt_printn(unsigned long long n, int *len,
								char *charset, struct s_flags flags);