/*usr/bin/cc -Wall -Wextra -Werror -g "$0" && exec ./a.out "$@"*/

int	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *str)
{

}	

