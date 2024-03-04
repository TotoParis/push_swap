/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:51:20 by tbarret           #+#    #+#             */
/*   Updated: 2024/03/04 12:21:12 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include "./get_next_line/get_next_line.h"
# include <signal.h>
# include <bits/types/siginfo_t.h>
# include <stdio.h>
# include <limits.h>

# ifndef ERROR_MSG
#  define NO_STACK "Error\n"
#  define NO_DOUBLE "Error\n"
# endif

typedef struct s_stack
{
	int				id;
	int				nb;
	struct s_stack	*next;
}	t_stack;

typedef struct s_cost
{
	int	ra_rb;
	int	rra_rrb;
	int	rra_rb;
	int	ra_rrb;
}					t_cost;

t_stack	*parse_args(char **args);
t_stack	*ft_stklast(t_stack *stack);
void	ft_stkadd_front(t_stack **stack, t_stack *new);
void	ft_stkadd_back(t_stack **stack, t_stack *new);
void	ft_stkclear(t_stack **stack);
int		check_args(char **tab);
int		check_double(t_stack *stack);
int		set_arg(char **tab, t_stack **stack, int *j);
int		clear_tab(char **tab);
int		already_sorted(t_stack *stack);
int		get_max(t_stack **stack);
int		get_max_id(t_stack **stack);
int		get_min(t_stack **stack);
int		get_min_id(t_stack **stack);
int		median(t_stack **stack);
int		target_nbr_b(int nbr, t_stack **b);
void	cost(t_stack **a, t_stack **b, int *nbr_a, int *nbr_b);
int		min_cost(t_stack **a, t_stack **b, int nbr_a, int nbr_b);
int		compare_cost(int a, int b);
int		cheaper_move(t_cost cost);
void	sort(t_stack **a, t_stack **b);
void	sort_five(t_stack **stack_a, t_stack **stack_b);
void	sort_three(t_stack **stack_a);
void	double_rotation(t_stack **a, t_stack **b, int id_a, int id_b);
void	move_to_top_b(t_stack **b, int id);
int		reverse_id(t_stack **stack, int id);
void	rotate(t_stack **stack);
void	reverse(t_stack **stack);
void	swap(t_stack **stack);
void	update_id(t_stack **stack);
int		get_id(t_stack **stack, int id);
int		max_id(t_stack **stack);
void	swap(t_stack **stack);
void	swap_a(t_stack **a);
void	swap_b(t_stack **b);
void	swap_both(t_stack **a, t_stack **b);
void	push(t_stack **from, t_stack **to);
void	push_a(t_stack **a, t_stack **b);
void	push_b(t_stack **a, t_stack **b);
void	rotate_a(t_stack **a);
void	rotate_b(t_stack **b);
void	rotate_both(t_stack **a, t_stack **b);
void	reverse_a(t_stack **a);
void	reverse_b(t_stack **b);
void	reverse_both(t_stack **a, t_stack **b);
void	print_stack(t_stack *stack);
void	push_swap(t_stack **stack_a, t_stack **stack_b);
void	rra_rrb(t_stack **a, t_stack **b, int id_a, int id_b);
void	rra_rb(t_stack **a, t_stack **b, int id_a, int id_b);
void	ra_rrb(t_stack **a, t_stack **b, int id_a, int id_b);
void	ra_rb(t_stack **a, t_stack **b, int id_a, int id_b);

#endif