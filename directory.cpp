#include "file.hpp"

void	init_struct_dir(directory *dir, char *path, char **envp)
{
	std::string tmp(path);
	dir->path = tmp;
	dir->env_size = 0;
	int i = 0;
	while (envp[i])
	{
		dir->env_size++;
		i++;
	}
	dir->env = new std::string[dir->env_size];
	for (int j = 0; envp[j]; j++)
		dir->env[j] = envp[j];
	return ;
}

void	choose_path(directory *dir)
{
	// size_t pos = dir->path.find("l/");
	// std::string tmp = dir->path.substr(0, pos);
	int i = 0;
	while (i < dir->env_size)
	{
		if (dir->env[i].compare(0, 5, "HOME=") == 0)
		{
			std::cout << "Trouve !" << std::endl;
			std::cout << dir->env[i] << std::endl;
		}
		i++;
	}
	//std::cout << tmp << std::endl;
	delete [] dir->env;
	return ;
}