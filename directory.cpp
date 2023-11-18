#include "file.hpp"

void	init_struct_dir(directory *dir, char **envp)
{
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

void	set_path(directory *dir)
{
	int i = 0;
	while (i < dir->env_size)
	{
		if (dir->env[i].compare(0, 5, "HOME=") == 0)
			dir->path = dir->env[i];
		i++;
	}
	if (dir->path.empty())
	{
		std::cout << "Home not find, end of program" << std::endl;
		return ;
	}
	size_t pos = dir->path.find("/");
	std::string temp = dir->path.substr(pos, std::string::npos);
	dir->path = temp;
	return ;
}

void	go_Home(directory *dir)
{
	char *pwd = getcwd(NULL, 0);
	std::string check(pwd);
	if (check.compare(dir->path) == 0)
	{
		free(pwd);
		return ;
	}
	bool check_2 = false;
	std::cout << "Before creating directory, do you want to start at home or stay where you are? ('Home' or 'Stay') : ";
	while (check_2 == false)
	{
		std::string input;
		if (!(std::getline(std::cin, input)))
		{
			free(pwd);
			throw(GetLineException());
			return ;
		}
		if (input.compare("Home") == 0)
		{
			std::cout << "dir_path = " << dir->path << std::endl;
			if (chdir(dir->path.c_str()) == 0)
				std::cout << "You are starting at Home : " << dir->path << std::endl;
			else
			{
				free(pwd);
				throw(FailChdirException());
			}
			check_2 = true;
		}
		else if (input.compare("Stay") == 0)
		{
			std::cout << "We stay here" << std::endl;
			dir->path = check; // pas bon, refaire le chemin
			std::cout << dir->path << std::endl;
			check_2 = true;
		}
		else
			std::cout << "Wrong input, please try again : ";
	}
	free(pwd);
	return ;
}

void	create_directory(directory *dir)
{
	bool toggle = false;
	bool create = false;
	std::string input;
	
	set_path(dir);
	go_Home(dir);
	
	while (toggle == false)
	{
		std::cout << "You are about to create a directory. ";
		std::cout << "Want you to do it? Type 'Yes' or 'No : ";
		while (create == false)
		{
			if (!(std::getline(std::cin, input)))
			{
				throw(GetLineException());
				return ;
			}
			if (input.compare("No") == 0)
			{
				std::cout << "No directory created" << std::endl;
				break ;
			}
			else if (input.compare("Yes") == 0)
			{
				std::string name;
				std::cout << "Choose a name for your directory : ";
				if (!(std::getline(std::cin, name)))
				{
					throw(GetLineException());
					return ;
				}
				if (name.empty())
					std::cout << "Name is empty : please try again." << std::endl;
				else
				{
					if (mkdir(name.c_str(), 0777) == 0)
					{
						std::cout << "Directory created with success !" << std::endl;
						create = true;
					}
					else
						throw(FailDirectoryException());
				}
			}
			else
				std::cout << "Wrong input. Please try again : ";
		}
		toggle = true;
	}
	return ;
}

const char *GetLineException::what() const throw()
{
	return ("EOF called. End of program");
}

const char *FailDirectoryException::what() const throw()
{
	return ("Failure to open directory. End of program");
}

const char *FailChdirException::what() const throw()
{
	return ("Failure to change directory. End of program");
}