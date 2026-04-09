/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmouta-g <lmouta-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:48:18 by lm0uta            #+#    #+#             */
/*   Updated: 2026/02/19 12:08:25 by lmouta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/**
 * ft_isalpha - checks if c is a letter
 * @c: character to check
 * Return: 1 if letter, 0 otherwise
 */
int				ft_isalpha(int c);
/**
 * ft_isdigit - checks if c is a digit
 * @c: character to check
 * Return: 1 if digit, 0 otherwise
 */
int				ft_isdigit(int c);
/**
 * ft_isalnum - checks if c is alphanumeric
 * @c: character to check
 * Return: 1 if alphanumeric, 0 otherwise
 */
int				ft_isalnum(int c);
/**
 * ft_isascii - checks if c is ASCII
 * @c: character to check
 * Return: 1 if ASCII (0-127), 0 otherwise
 */
int				ft_isascii(int c);
/**
 * ft_isprint - checks if c is printable
 * @c: character to check
 * Return: 1 if printable (32-126), 0 otherwise
 */
int				ft_isprint(int c);
/**
 * ft_isspace - checks if c is whitespace
 * @c: character to check
 * Return: 1 if whitespace, 0 otherwise
 */
int				ft_isspace(int c);
/**
 * ft_tolower - converts uppercase to lowercase
 * @c: character to convert
 * Return: lowercase char or c unchanged
 */
int				ft_tolower(int c);
/**
 * ft_toupper - converts lowercase to uppercase
 * @c: character to convert
 * Return: uppercase char or c unchanged
 */
int				ft_toupper(int c);
/**
 * ft_atoi - converts string to int
 * @str: string to convert
 * Return: integer value
 */
int				ft_atoi(const char *str);
/**
 * ft_itoa - converts int to string
 * @n: integer to convert
 * Return: new allocated string or NULL
 */
char			*ft_itoa(int n);

/**
 * ft_strlen - calculates string length
 * @s: pointer to string
 * Return: number of chars before '\0', or 0 if s is NULL
 */
size_t			ft_strlen(const char *s);
/**
 * ft_strdup - duplicates string
 * @s: string to duplicate
 * Return: new allocated string or NULL
 */
char			*ft_strdup(const char *s);
/**
 * ft_substr - extracts substring from s
 * @s: source string
 * @start: start index
 * @len: max length
 * Return: new allocated substring or NULL
 */
char			*ft_substr(char const *s, unsigned int start, size_t len);
/**
 * ft_strjoin - joins two strings
 * @s1: first string
 * @s2: second string
 * Return: new allocated string or NULL
 */
char			*ft_strjoin(char const *s1, char const *s2);
/**
 * ft_strtrim - trims chars from set at start/end
 * @s1: string to trim
 * @set: chars to remove
 * Return: new trimmed string or NULL
 */
char			*ft_strtrim(char const *s1, char const *set);
/**
 * ft_strchr - finds first occurrence of c in s
 * @s: string to search
 * @c: character to find
 * Return: pointer to char or NULL
 */
char			*ft_strchr(const char *s, int c);
/**
 * ft_strrchr - finds last occurrence of c in str
 * @str: string to search
 * @c: character to find
 * Return: pointer to char or NULL
 */
char			*ft_strrchr(const char *s, int c);
/**
 * ft_strnstr - finds needle in haystack within len bytes
 * @haystack: string to search in
 * @needle: string to find
 * @len: max bytes to search
 * Return: pointer to match or NULL
 */
char			*ft_strnstr(const char *haystack,
					const char *needle, size_t len);
/**
 * ft_strncmp - compares n chars of two strings
 * @s1: first string
 * @s2: second string
 * @n: max chars to compare
 * Return: difference or 0 if equal
 */
int				ft_strncmp(const char *s1, const char *s2, size_t n);
/**
 * ft_strlcpy - copies src to dst with size limit
 * @dst: destination buffer
 * @src: source string
 * @dstsize: size of dst buffer
 * Return: length of src
 */
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
/**
 * ft_strlcat - concatenates src to dst with size limit
 * @dst: destination buffer
 * @src: source string
 * @dstsize: size of dst buffer
 * Return: total length attempted
 */
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
/**
 * ft_striteri - applies f to each char with index
 * @s: string to iterate
 * @f: function to apply
 */
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
/**
 * ft_strmapi - applies f to each char, returns new string
 * @s: source string
 * @f: function to apply
 * Return: new string or NULL
 */
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
/**
 * ft_split - splits string by delimiter
 * @s: string to split
 * @c: delimiter char
 * Return: array of strings or NULL
 */
char			**ft_split(char const *s, char c);

/**
 * ft_bzero - sets memory to zero
 * @b: pointer to memory
 * @len: number of bytes
 */
void			ft_bzero(void *b, size_t len);
/**
 * ft_memset - fills memory with byte c
 * @b: pointer to memory
 * @c: byte value to set
 * @len: number of bytes
 * Return: pointer to b
 */
void			*ft_memset(void *b, int c, size_t len);
/**
 * ft_memcpy - copies memory (no overlap)
 * @dst: destination
 * @src: source
 * @len: number of bytes
 * Return: pointer to dst
 */
void			*ft_memcpy(void *dst, const void *src, size_t len);
/**
 * ft_memmove - copies memory (handles overlap)
 * @dest: destination
 * @src: source
 * @n: number of bytes
 * Return: pointer to dest
 */
void			*ft_memmove(void *dst, const void *src, size_t len);
/**
 * ft_memchr - finds byte in memory
 * @s: memory to search
 * @c: byte to find
 * @n: number of bytes to search
 * Return: pointer to byte or NULL
 */
void			*ft_memchr(const void *s, int c, size_t n);
/**
 * ft_memcmp - compares memory
 * @s1: first memory block
 * @s2: second memory block
 * @n: number of bytes
 * Return: difference or 0 if equal
 */
int				ft_memcmp(const void *s1, const void *s2, size_t len);
/**
 * ft_calloc - allocates and zeroes memory
 * @count: number of elements
 * @size: size of each element
 * Return: pointer to memory or NULL
 */
void			*ft_calloc(size_t count, size_t size);
/**
 * ft_get_bit - returns the value of a specific bit in an integer
 * @num: the number from which to extract the bit
 * @bit: position of the bit to get (starting from the right, 0-based)
 * Return: 0 or 1, returns 0 for an invalid bit index
 */
int				ft_get_bit(int num, int bit);


/**
 * ft_putchar_fd - writes char to fd
 * @c: character to write
 * @fd: file descriptor
 */
void			ft_putchar_fd(char c, int fd);
/**
 * ft_putstr_fd - writes string to fd
 * @s: string to write
 * @fd: file descriptor
 */
void			ft_putstr_fd(char *s, int fd);
/**
 * ft_putendl_fd - writes string + newline to fd
 * @s: string to write
 * @fd: file descriptor
 */
void			ft_putendl_fd(char *s, int fd);
/**
 * ft_putnbr_fd - writes integer to fd
 * @n: integer to write
 * @fd: file descriptor
 */
void			ft_putnbr_fd(int n, int fd);
/**
 * ft_printf - prints formatted output to stdout
 * @format: format string
 * Return: number of bytes written
 */
int				ft_printf(const char *format, ...);
/**
 * ft_putchar - writes one character to stdout
 * @c: character to write
 * Return: number of bytes written
 */
int				ft_putchar(char c);
/**
 * ft_putstr - writes a string to stdout
 * @str: string to write
 * Return: number of bytes written
 */
int				ft_putstr(char *str);
/**
 * ft_putnbr - writes a signed integer to stdout
 * @n: number to write
 * Return: number of bytes written
 */
int				ft_putnbr(int n);
/**
 * ft_putunsigned - writes an unsigned integer to stdout
 * @n: number to write
 * Return: number of bytes written
 */
int				ft_putunsigned(unsigned int n);
/**
 * ft_puthexa - writes an unsigned number in hexadecimal
 * @form: hexadecimal letter case selector
 * @nbr: number to write
 * Return: number of bytes written
 */
int				ft_puthexa(char form, unsigned long long nbr);
/**
 * ft_putpointer - writes a pointer to stdout
 * @ptr: pointer value
 * Return: number of bytes written
 */
int				ft_putpointer(unsigned long long ptr);

/**
 * ft_lstnew - creates new list node
 * @content: content for the node
 * Return: new node or NULL
 */
t_list			*ft_lstnew(void *content);
/**
 * ft_lstadd_front - adds node at list start
 * @lst: pointer to list head
 * @new_node: node to add
 */
void			ft_lstadd_front(t_list **lst, t_list *new_node);
/**
 * ft_lstsize - counts list nodes
 * @lst: list head
 * Return: number of nodes
 */
int				ft_lstsize(t_list *lst);
/**
 * ft_lstlast - returns last node
 * @lst: list head
 * Return: last node or NULL
 */
t_list			*ft_lstlast(t_list *lst);
/**
 * ft_lstadd_back - adds node at list end
 * @lst: pointer to list head
 * @new_node: node to add
 */
void			ft_lstadd_back(t_list **lst, t_list *new_node);
/**
 * ft_lstdelone - deletes one node
 * @lst: node to delete
 * @del: function to delete content
 */
void			ft_lstdelone(t_list *lst, void (*del)(void *));
/**
 * ft_lstclear - deletes entire list
 * @lst: pointer to list head
 * @del: function to delete content
 */
void			ft_lstclear(t_list **lst, void (*del)(void *));
/**
 * ft_lstiter - applies f to each node content
 * @lst: list head
 * @f: function to apply
 */
void			ft_lstiter(t_list *lst, void (*f)(void *));
/**
 * ft_lstmap - creates new list by applying f
 * @lst: source list
 * @f: function to apply
 * @del: function to delete on error
 * Return: new list or NULL
 */
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

/**
 * ft_gnl - reads a line from file descriptor
 * @fd: file descriptor to read from
 * Return: line read or NULL if EOF/error
 */
char			*ft_gnl(int fd);

#endif
