/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltombell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:23:10 by ltombell          #+#    #+#             */
/*   Updated: 2022/10/14 16:23:17 by ltombell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_toprint
{
	va_list	list;
	int		wdt;
	int		zero;
	int		sign;
	int		dash;
	int		space;
	int		count;
	int		pos;
	int		hasflags;
	int		minus;
	int		point;
	int		prec;
	int		d;
	long	tmpd;
}	t_toprint;

t_toprint	*ft_initialise_toprint(t_toprint *tab);
t_toprint	*ft_reset_toprint(t_toprint *tab);
size_t		ft_strlen(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_atoi(const char *nptr);
int			ft_strcmp(const char *s1, const char *s2);
int			checkdoubles(char c, char *s);
int			count_nbr(long n, int base);
int			count_unsigned(unsigned int n, unsigned int base);
int			count_ptr(uintptr_t num);
t_toprint	*ft_count_numb(const char *s, t_toprint *tab, char c);
t_toprint	*writeflags(t_toprint *tab, int num, char t);
t_toprint	*checkflags(const char *s, t_toprint *tab);
void		ft_write_prec(t_toprint *tab, int howlong);
t_toprint	*checknprint(const char *s, t_toprint *tab);
t_toprint	*ftx_hexnb(const char *s, t_toprint *tab);
t_toprint	*ftx_d(t_toprint *tab);
t_toprint	*ftx_u(t_toprint *tab);
t_toprint	*ftx_ptr(t_toprint *tab);
t_toprint	*ftx_chars(const char *s, t_toprint *tab);
t_toprint	*ftx_str(t_toprint *tab);
void		ft_put_ptr(uintptr_t num);
int			ft_put_ptr_txt(uintptr_t num);
int			ft_putchar(char c);
int			ft_putstr(char *s);
int			ft_putnbru(unsigned int n);
int			ft_putnbr(long n);
int			ft_puthex(int n, char flag);
int			ft_writezerox(char c);
t_toprint	*writenormalchar(const char *s, t_toprint *tab);
int			ft_printf(const char *s, ...);
#endif
