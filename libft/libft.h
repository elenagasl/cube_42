/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:11:38 by danielji          #+#    #+#             */
/*   Updated: 2026/01/04 09:46:08 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdint.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_isspace(int c);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	**ft_push_str_to_arr(char **arr, char *str);
char	*ft_strchr(char *str, int c);
char	*ft_strrchr(char *str, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_atoi(const char *str);
double	ft_atod(char *str);
void	*ft_calloc(size_t nelem, size_t size);
char	*ft_strdup(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin3(char *str1, char *str2, char *str3);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

// Get Next Line
char	*get_next_line(int fd);

// ft_printf
int		ft_printf(char const *str, ...);
ssize_t	ft_putchar_r(char c);
ssize_t	ft_putstr_r(char *s);
ssize_t	ft_putnbr_r(int n);
ssize_t	ft_putnbr_u_r(unsigned int n);
ssize_t	ft_puthex_int_r(unsigned int num, char *base);
ssize_t	ft_putptr_r(void *ptr);

// ft_dprintf
int		ft_dprintf(int fd, char const *str, ...);
ssize_t	ft_dputchar_r(int fd, char c);
ssize_t	ft_dputstr_r(int fd, char *s);
ssize_t	ft_dputnbr_r(int fd, int n);
ssize_t	ft_dputnbr_u_r(int fd, unsigned int n);
ssize_t	ft_dputhex_ir(int fd, unsigned int num, char *base);
ssize_t	ft_dputptr_r(int fd, void *ptr);

#endif
