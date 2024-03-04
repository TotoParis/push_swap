/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:01:47 by tbarret           #+#    #+#             */
/*   Updated: 2024/03/04 12:27:38 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static	int	movement(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (ft_strncmp(line, "sa\n", 4) == 0)
		return (swap(stack_a), 1);
	else if (ft_strncmp(line, "sb\n", 4) == 0)
		return (swap(stack_b), 1);
	else if (ft_strncmp(line, "ss\n", 4) == 0)
		return (swap(stack_a), swap(stack_b), 1);
	else if (ft_strncmp(line, "pa\n", 4) == 0)
		return (push(stack_b, stack_a), 1);
	else if (ft_strncmp(line, "pb\n", 4) == 0)
		return (push(stack_a, stack_b), 1);
	else if (ft_strncmp(line, "ra\n", 4) == 0)
		return (rotate(stack_a), 1);
	else if (ft_strncmp(line, "rb\n", 4) == 0)
		return (rotate(stack_b), 1);
	else if (ft_strncmp(line, "rr\n", 4) == 0)
		return (rotate(stack_a), rotate(stack_b), 1);
	else if (ft_strncmp(line, "rra\n", 5) == 0)
		return (reverse(stack_a), 1);
	else if (ft_strncmp(line, "rrb\n", 5) == 0)
		return (reverse(stack_b), 1);
	else if (ft_strncmp(line, "rrr\n", 5) == 0)
		return (reverse(stack_a), \
		reverse(stack_b), 1);
	return (0);
}

static int	checker(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (movement(stack_a, stack_b, line))
			free(line);
		else
			return (free(line), 0);
		line = get_next_line(0);
	}
	if (!already_sorted(*stack_a) || *stack_b)
		return (0);
	return (ft_printf("OK\n"), 1);
}

static void	end(t_stack **stack_a, t_stack **stack_b)
{
	ft_stkclear(stack_a);
	if (*stack_b)
		ft_stkclear(stack_b);
	ft_putstr_fd("KO\n", 2);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = NULL;
	if (argc < 2)
		return (0);
	stack_a = parse_args(argv);
	if (!stack_a)
		return (ft_putstr_fd(NO_STACK, 2), 0);
	if (!check_double(stack_a))
		return (ft_stkclear(&stack_a), ft_putstr_fd(NO_DOUBLE, 2), 0);
	if (already_sorted(stack_a))
		return (ft_stkclear(&stack_a), 0);
	if (!checker(&stack_a, &stack_b))
		end(&stack_a, &stack_b);
	ft_stkclear(&stack_a);
	return (0);
}
