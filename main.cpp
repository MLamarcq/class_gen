#include "file.hpp"

int main(int argc, char **argv, char **envp)
{
	if (argc < 2)
	{
		std::cout << "Need argument !" << std::endl;
		return (0);
	}
	directory dir;
	init_struct_dir(&dir, envp);
	try
	{
		create_directory(&dir);
	}
	catch (GetLineException &e)
	{
		std::cout << std::endl << e.what() << std::endl;
		delete [] dir.env;
		return (0);
	}
	catch (FailDirectoryException &e)
	{
		std::cout << std::endl << e.what() << std::endl;
		delete [] dir.env;
		return (0);
	}
	catch (FailChdirException &e)
	{
		std::cout << std::endl << e.what() << std::endl;
		delete [] dir.env;
		return (0);
	}
	// file file;
	// final_moove(&file, argv, argc);
	delete [] dir.env;
	(void)argv;
	return (0);
}