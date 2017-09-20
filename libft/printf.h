/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 17:23:10 by adubedat          #+#    #+#             */
/*   Updated: 2016/05/11 20:09:34 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H

# define PRINTF_H
# include "libft.h"
# include <stdarg.h>
# include <wchar.h>

typedef struct				s_flags
{
	int						j;
	int						diese;
	int						zero;
	int						moins;
	int						space;
	int						plus;
	int						width;
	int						precision;
	int						modifier;
	int						null;
	char					conversion;
	char					*param;
}							t_flags;

typedef struct				s_modifier
{
	int						i;
	short int				si;
	long int				li;
	long long int			lli;
	intmax_t				imt;
	size_t					st;
	unsigned int			ui;
	unsigned short int		usi;
	unsigned long int		uli;
	unsigned long long int	ulli;
	uintmax_t				uimt;
	char					c;
	unsigned char			uc;
	wint_t					wit;
	char					*str;
	wchar_t					*wstrt;
	void					*v;
}							t_modifier;

void						initialize_m(t_modifier *m);
int							ft_printf(const char *str, ...);
char						*get_param(const char *str, int *i,
		char *c, char *param);
int							print_var(const char *str, int *i, va_list args);
int							distrib(const char *str, int i, va_list args,
		int result);
int							string_conv(va_list args, t_flags f);
t_flags						init_flags(t_flags f);
t_flags						check_first_flag(t_flags f, va_list args);
t_flags						check_first_flag2(t_flags f);
t_flags						check_second_flag(t_flags f, va_list args);
t_flags						check_third_flag(t_flags f, va_list args);
t_flags						check_fourth_flag(t_flags f, va_list args);
int							signed_conv(va_list args, t_flags f);
char						*signed_conv2(char *str, va_list args, t_flags f,
		t_modifier m);
int							unsigned_conv(va_list args, t_flags f);
char						*unsigned_conv2(char *str, va_list args, t_flags f,
		t_modifier m);
char						*unsigned_conv3(char *str, va_list args, t_flags f,
		t_modifier m);
char						*unsigned_conv4(char *str, va_list args, t_flags f,
		t_modifier m);
int							char_conv(va_list args, t_flags f);
int							pointer_conv(va_list args, t_flags f);
char						*apply_flags(char *str, t_flags f);
char						*apply_precision(char *str, t_flags f);
char						*apply_precision2(char *str, t_flags f);
char						*apply_width(char *str, t_flags f);
char						*char_conv2(va_list args, t_flags f, char *str);
void						ft_putstr_0(char *str);
char						*apply_width2(char *str, t_flags f);
int							check_s_flags(char *param);

#endif
