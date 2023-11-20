#include "file.hpp"

std::string	to_upper(std::string str)
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - 32;
		}
	}
	return (str);
}
int	is_digit(std::string str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

void free_all(directory *dir, file *file)
{
	if (dir->env)
		delete [] dir->env;
	free_file(file);
}

