/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabed <yaabed@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 15:07:10 by yaabed            #+#    #+#             */
/*   Updated: 2026/10/24 17:18:53 by yaabed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stddef.h>

int	is_strategy(char *arg)
{
	if (ft_strcmp("--simple", arg) == 0)
		return (1);
	else if (ft_strcmp("--medium", arg) == 0)
		return (1);
	else if (ft_strcmp("--complex", arg) == 0)
		return (1);
	else if (ft_strcmp("--adaptive", arg) == 0)
		return (1);
	else if (ft_strcmp("--bench", arg) == 0)
		return (1);
	else
		return (0);
}

int	parse_strategy(char *arg, t_data *data, int *flag)
{
	if (*flag || !arg || !data)
		return (0);
	if (ft_strcmp("--simple", arg) == 0)
		data->strategy = SIMPLE;
	else if (ft_strcmp("--medium", arg) == 0)
		data->strategy = MEDIUM;
	else if (ft_strcmp("--complex", arg) == 0)
		data->strategy = COMPLEX;
	else if (ft_strcmp("--adaptive", arg) == 0)
		data->strategy = ADAPTIVE;
	else if (ft_strcmp("--bench", arg) == 0)
		data->bench->disorder = 1;
	else
		return (0);
	*flag = 1;
	return (1);
}

int	edite_stack(char *arg, t_data *data, int *number)
{
	if (convert_number(arg, number))
	{
		if (has_duplicate(data->a, *number) || !add_number(&data->a, *number))
		{
			remove_stack(&data->a);
			remove_stack(&data->b);
			return (1);
		}
	}
	else
	{
		remove_stack(&data->a);
		remove_stack(&data->b);
		return (1);
	}
	return (0);
}

int	process_arg(char *arg, t_data *data, int *flags, int *number)
{
	if (is_strategy(arg))
		return (parse_strategy(arg, data, &flags[0]));
	if (ft_strcmp("--bench", arg) == 0 && !flags[1])
	{
		data->bench->enable = 1;
		flags[1] = 1;
		return (1);
	}
	return (!edite_stack(arg, data, number));
}

int	read_input(int argc, char **argv, t_data *data)
{
	int	index;
	int	flags[2];
	int	number;

	index = 1;
	flags[0] = 0;
	flags[1] = 0;
	number = 0;
	if (argc < 2)
		return (0);
	while (index < argc)
	{
		if (!process_arg(argv[index], data, flags, &number))
			return (0);
		index++;
	}
	return (1);
}
