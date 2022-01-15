#ifndef MINILIBFT_H
# define MINILIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>

size_t				ft_strlen(const char *s);
void				*ft_memset(void *s, int c, size_t len);
void				*ft_calloc(size_t count, size_t size);
void				ft_bzero(void *s, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isspace(int c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				**ft_split(char const *s, char c);

#endif
