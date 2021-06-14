#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_flg
{
	int	flag[2];
	int	width;
	int	pre;
}		t_flg;

int		ft_printf(const char *format, ...);
int		ft_actual_len(int n, t_flg *flg);
int		ft_count_digits(long n);
int		ft_count_digits_u(unsigned int n);
int		ft_get_adr_len(unsigned long long ptr, t_flg *flg);
int		ft_count_digits_sixt(unsigned long long n);
int		ft_actual_ulen(unsigned int n, t_flg *flg);
int		ft_lower(int a, int b);
int		ft_bigger(int a, int b);
int		ft_actual_hex_len(unsigned int num, t_flg *flg);
void	ft_write_str(const char *start, const char **format, int *i);
void	ft_format_processing(const char **format, int *i, va_list ap);
void	ft_flg_init(t_flg *flg);
void	ft_get_width(const char **format, t_flg *flg, va_list ap);
void	ft_get_pre(const char **format, t_flg *flg, va_list ap);
void	ft_print_format(const char **format, int *i, t_flg *flg, va_list ap);
void	ft_print_per(const char **format, int *i, t_flg *flg);
void	ft_print_char(const char **format, int *i, t_flg *flg, va_list ap);
void	ft_print_int(const char **format, int *i, t_flg *flg, va_list ap);
void	ft_print_zero_minus(int *i, t_flg *flg);
void	ft_print_zero(int *i, t_flg *flg);
void	ft_putnnbr(int n, int len);
void	ft_put_same_char(char c, int n);
void	ft_print_str(const char **format, int *i, t_flg *flg, va_list ap);
void	ft_print_str_minus(char *str, int *i, t_flg *flg);
void	ft_fill_flg(t_flg *flg, int len);
void	ft_print_adr(const char **format, int *i, t_flg *flg, va_list ap);
void	ft_print_adr_minus(int *i, t_flg *flg, va_list ap);
void	ft_putadr_pre(unsigned long long adr, t_flg *flg);
void	ft_print_uint(const char **format, int *i, t_flg *flg, va_list ap);
void	ft_putnnbr_u(unsigned int n, int len);
void	ft_put_same_char(char c, int n);
void	ft_print_hex_low(const char **format, int *i, t_flg *flg, va_list ap);
void	ft_print_hex_up(const char **format, int *i, t_flg *flg, va_list ap);
void	ft_puthex_pre(unsigned int num, int up_sign, int len);
void	ft_putnbr_base(unsigned long long nbr, char *base);
void	ft_print_char_minus(char c, t_flg *flg, int *i);
size_t	ft_power(size_t base, int n);

#endif