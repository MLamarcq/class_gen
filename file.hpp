#ifndef FILE_HPP
# define FILE_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <cstdlib>
#include <sys/stat.h>

struct directory
{
	std::string path;
	std::string *env;
	int		env_size;
};

struct file
{
	std::string first_file;
	std::string *other_file;
	int			tab_index;
};

class GetLineException : public std::exception
{
	public :
			const char *what() const throw();
};

class FailDirectoryException : public std::exception
{
	public :
			const char *what() const throw();
};

class FailChdirException : public std::exception
{
	public :
			const char *what() const throw();
};


int main(int argc, char **argv, char **envp);
char *to_upper(char *str);
void	init_struct(file *data, char **argv, int argc);
void	create_first_file(file *file, char **argv);
void	create_other_file(file *file, char **argv, int i);
void free_file(file *file);
void	final_moove(file *file, char **argv, int argc);
void	init_struct_dir(directory *dir, char **envp);
void	set_path(directory *dir);
void	create_directory(directory *dir);
void	go_Home(directory *dir);



#endif