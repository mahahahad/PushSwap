/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdull <maabdull@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:00:55 by maabdull          #+#    #+#             */
/*   Updated: 2024/02/12 12:08:40 by maabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Joins two strings with a space in between
static char	*strjoin(char *s1, char *s2)
{
	char	*final_str;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	final_str = malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	if (!final_str)
		return (exit(1), NULL);
	while (s1[++i])
		final_str[i] = s1[i];
	if (s1[i] == '\0')
		final_str[i++] = ' ';
	while (s2[j])
		final_str[i++] = s2[j++];
	final_str[i] = '\0';
	return (final_str);
}

// Joins arguments separating them with a space
static char	*join_args(char *argv[])
{
	int		i;
	char	*joined_args;
	char	*temp;

	i = 0;
	joined_args = malloc(1);
	if (!joined_args)
		return (exit(1), NULL);
	joined_args[0] = '\0';
	temp = NULL;
	while (argv[i])
	{
		temp = joined_args;
		joined_args = strjoin(joined_args, argv[i]);
		free(temp);
		temp = NULL;
		i++;
	}
	return (joined_args);
}

// Frees the double pointer containing the string arguments
void	free_args(char **arguments)
{
	int	i;

	i = 0;
	while (arguments[i])
		free(arguments[i++]);
	free(arguments);
	arguments = NULL;
}

// Validates arguments by checking for non-integers and duplicates
// Frees and exits if invalid arguments found
void	validate_args(char **arguments)
{
	char	*temp;
	int		i;

	i = 0;
	temp = NULL;
	while (arguments[i])
	{
		if (!extract_num(arguments[i]))
			return (free_args(arguments), show_err());
		temp = arguments[i];
		arguments[i] = ft_itoa(ft_atoi(arguments[i]));
		free(temp);
		i++;
	}
	check_long_dup_args(arguments);
}

// Converts arguments to array of strings
// Joins and splits from [1, 2, 3, "4 5"] -> [1, 2, 3, 4, 5]
char	**process_args(char *argv[], int *size)
{
	char	**arguments;
	char	*joined_args;
	int		i;

	i = 0;
	arguments = NULL;
	joined_args = join_args(++argv);
	arguments = ft_split(joined_args, ' ');
	while (arguments[i])
		i++;
	*size = i;
	free(joined_args);
	joined_args = NULL;
	return (arguments);
}
