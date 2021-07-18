#include "philosophers.h"
int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long int	number;

	i = 0;
	sign = 1;
	number = 0;
	if (!str)
		return (0);
	while ((str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' '))
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (number == 0)
			number = str[i] - 48;
		else
			number = number * 10 + str[i] - 48;
		i++;
	}
	return (number * sign);
}

t_bool	is_number(char *line)
{
	int	i;

	i = 0;
	if (line[0] == '+' || line[0] == '-')
		i++;
	while (line[i])
	{
		if (!(line[i] >= '0' && line[i] <= '9'))
			return (false);
		i++;
	}
	return (true);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

t_bool	is_long_int(char *input)
{
	int		length;
	char	*cmp_str;

	while (input [0] == '+')
		input++;
	cmp_str = "2147483647";
	if (input[0] == '-')
	{
		input++;
		cmp_str = "2147483648";
	}
	length = 0;
	if (input)
		while (input[length])
			length++;
	if (length < 10)
		return (false);
	else if (length > 10)
		return (true);
	if (ft_strncmp(input, cmp_str, 10) > 0)
		return (true);
	return (false);
}

t_bool	check_number(int *nbr, char *str, t_bool check_zero)
{
	if (!is_long_int(str) && is_number(str))
	{
		*nbr = ft_atoi(str);
		if (!check_zero)
			return (true);
		if (*nbr)
			return(true);
	}
	return(false);
}
