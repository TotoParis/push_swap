/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:51:20 by tbarret           #+#    #+#             */
/*   Updated: 2024/03/01 18:28:40 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include <signal.h>
# include <bits/types/siginfo_t.h>
# include <stdio.h>
# include <limits.h>

# ifndef ERROR_MSG
#  define NO_ARGS "Error\nNo arguments.\n"
#  define NO_STACK "Error\nSyntaxe: ./push_swap <number>\n"
#  define NO_DOUBLE "Error\nDouble number.\n"
# endif

typedef struct s_stack
{
	int				id;
	int				nb;
	struct s_stack	*next;
}	t_stack;

t_stack	*parse_args(char **args);
t_stack	*ft_stklast(t_stack *stack);
void	ft_stkadd_front(t_stack **stack, t_stack *new);
void	ft_stkadd_back(t_stack **stack, t_stack *new);
int		check_args(char **tab);
int		check_double(t_stack *stack);
int		set_arg(char **tab, t_stack **stack, int *j);
int		clear_tab(char **tab);
int		already_sorted(t_stack *stack);
void 	update_id(t_stack **stack);
void	swap(t_stack **stack);
void	swap_a(t_stack **a);
void	swap_b(t_stack **b);
void	swap_both(t_stack **a, t_stack **b);
void	push(t_stack **from, t_stack **to);
void	push_a(t_stack **a, t_stack **b);
void	push_b(t_stack **a, t_stack **b);
void 	rotate_a(t_stack **a);
void	rotate_b(t_stack **b);
void	rotate_both(t_stack **a, t_stack **b);
void	reverse(t_stack **stack);
void	reverse_a(t_stack **a);
void	reverse_b(t_stack **b);
void	reverse_both(t_stack **a, t_stack **b);
void	print_stack(t_stack *stack);

#endif
