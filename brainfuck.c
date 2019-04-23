#include <stdlib.h>
#include <unistd.h>

void	brainfuck(char *str)
{
	int	tab[2048] = {0};
	int count;
	int	*ptr;

	ptr = tab;
	count = 0;
	while (*str)
	{
		if (*str == '>')
			ptr++;
		else if (*str == '<')
			ptr--;
		else if (*str == '+')
			++(*ptr);
		else if (*str == '-')
			--(*ptr);
		else if (*str == '.')
			write(1, ptr, 1);
		else if (*str == '[' && *ptr == 0)
		{
			count = 1;
			while (count != 0)
			{
				str++;
				if (*str == ']')
					--count;
				if (*str == '[')
					++count;
			}
		}
		else if (*str == ']' && *ptr != 0)
		{
			count = 1;
			while (count != 0)
			{
				str--;
				if (*str == '[')
					--count;
				if (*str == ']')
					++count;
			}
		}
		str++;
	}
}

int		main(int argc, char *argv[])
{
	if (argc == 2)
		brainfuck(argv[1]);
	return (0);
}
