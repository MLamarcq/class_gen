#include "file.hpp"


void	init_struct(file *data, char **argv, int argc)
{
	int i = 1;
	int j = 0;
	data->other_file = new std::string[argc - 2];
	while (i < argc)
	{
		std::string temp(argv[i]);
		if (i == 1)
		{
			data->first_file = temp;
		}
		else
		{
			data->other_file[j] = temp;
			std::cout << data->other_file[j] << std::endl;
			j++;
		}
		temp.erase();
		i++;
	}
	data->tab_index = 0;
	return ;
}

void	create_first_file(file *file, char **argv)
{
	std::string temp = file->first_file;
	temp.append(".class.hpp");
	std::cout << temp << std::endl;
	std::ofstream file_1(temp.c_str());
	if (file_1.fail())
	{
		std::cerr << "Error during opening file_1" << std::endl;
		return ;
	}
	std::string name(to_upper(argv[1]));

	file_1 << "#ifndef " << name.append("_CLASS_HPP") << std::endl;
	file_1 << "#define " << name << std::endl << std::endl;
	
	file_1 << "#include <string>" << std::endl;
	file_1 << "#include <iostream>" << std::endl;
	file_1 << "#include <fstream>" << std::endl << std::endl;

	file_1 << "class " << file->first_file << std::endl;
	file_1 << "{" << std::endl;
	file_1 << "\tpublic : " << std::endl;
	file_1 << "\t\t\t" << file->first_file << "(void);" << std::endl;
	file_1 << "\t\t\t" << file->first_file << "(" << file->first_file << " const &src);" << std::endl;
	file_1 << "\t\t\t" << "~" << file->first_file << "(void);" << std::endl << std::endl;
	file_1 << "\t\t\t" << file->first_file << " &operator=(" << file->first_file << " const &rhs);" << std::endl << std::endl;
	file_1 << "\tprivate : " << std::endl;
	file_1 << "}" << std::endl << std::endl;
	file_1 << "#endif";
	return ;
}

void	create_other_file(file *file, char **argv, int i)
{
	std::string temp = file->other_file[file->tab_index];
	temp.append(".class.hpp");
	std::cout << temp << std::endl;
	std::ofstream file_1(temp.c_str());
	if (file_1.fail())
	{
		std::cerr << "Error during opening file_1" << std::endl;
		return ;
	}
	std::string name(to_upper(argv[i]));
	
	file_1 << "#ifndef " << name.append("_CLASS_HPP") << std::endl;
	file_1 << "#define " << name << std::endl << std::endl;
	
	file_1 << "#include <string>" << std::endl;
	file_1 << "#include <iostream>" << std::endl;
	file_1 << "#include <fstream>" << std::endl << std::endl;

	file_1 << "class " << file->other_file[file->tab_index] << " : public " << file->first_file << std::endl;
	file_1 << "{" << std::endl;
	file_1 << "\tpublic : " << std::endl;
	file_1 << "\t\t\t" << file->other_file[file->tab_index] << "(void);" << std::endl;
	file_1 << "\t\t\t" << file->other_file[file->tab_index] << "(" << file->other_file[file->tab_index] << " const &src);" << std::endl;
	file_1 << "\t\t\t" << "~" << file->other_file[file->tab_index] << "(void);" << std::endl << std::endl;
	file_1 << "\t\t\t" << file->other_file[file->tab_index] << " &operator=(" << file->other_file[file->tab_index] << " const &rhs);" << std::endl << std::endl;
	file_1 << "\tprotected : " << std::endl;
	file_1 << "}" << std::endl << std::endl;
	file_1 << "#endif";
	file->tab_index++;
	return ;
}

void free_file(file *file)
{
	if (file->other_file)
	{
		delete [] file->other_file;
	}
	return ;
}

void	final_moove(file* file, char **argv, int argc)
{
	int i = 1;
	init_struct(file, argv, argc);
	while (argv[i])
	{
		if (i == 1)
			create_first_file(file, argv);
		else
			create_other_file(file, argv, i);
		i++;
	}
	free_file(file);
	return ;
}