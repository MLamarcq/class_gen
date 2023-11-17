#include "file.hpp"

int main(int argc, char **argv, char **envp)
{
	if (argc < 2)
	{
		std::cout << "Need argument !" << std::endl;
		return (0);
	}
	directory dir;
	char *new_path = getcwd(NULL, 0);
	std::cout << "Path = " << new_path << std::endl;
	init_struct_dir(&dir, new_path, envp);
	choose_path(&dir);
	// file file;
	// final_moove(&file, argv, argc);
	free (new_path);
	(void)argv;
	return (0);
}