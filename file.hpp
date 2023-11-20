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
	std::string dir;
	bool		barrier;
	int		env_size;
};

struct file
{
	std::string first_file;
	std::string *other_file;
	int			tab_index;
	int			nbr_file;
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


std::string to_upper(std::string str);
int	is_digit(std::string str);
void free_all(directory *dir, file *file);

void	set_nbr_file(file *file);
void	init_struct(file *data);
void	create_first_file(file *file);
void	create_other_file(file *file);
void free_file(file *file);
void	final_moove(file *file);


void	init_struct_dir_and_file(directory *dir, file *file, char **envp);
void	set_path(directory *dir);
void	create_directory_first_time(directory *dir);
void	go_Home_or_Stay(directory *dir);
void	go_to_dir(directory *dir);
bool	create_directory(directory *dir);
void	program(directory *dir, file *file);



#endif