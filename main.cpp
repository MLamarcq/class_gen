#include "file.hpp"

int main(int argc, char **argv, char **envp)
{
	if (argc > 1)
	{
		std::cout << "Don't need argument !" << std::endl;
		return (0);
	}
	directory dir;
	file fil;
	init_struct_dir_and_file(&dir, &fil, envp);
	try
	{
		program(&dir, &fil);
	}
	catch (GetLineException &e)
	{
		std::cout << std::endl << e.what() << std::endl;
		free_all(&dir, &fil);
		return (0);
	}
	catch (FailDirectoryException &e)
	{
		std::cout << std::endl << e.what() << std::endl;
		free_all(&dir, &fil);
		return (0);
	}
	catch (FailChdirException &e)
	{
		std::cout << std::endl << e.what() << std::endl;
		free_all(&dir, &fil);
		return (0);
	}
	free_all(&dir, &fil);
	(void)argv;
	(void)argc;
	return (0);
}