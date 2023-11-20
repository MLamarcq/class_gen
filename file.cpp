#include "file.hpp"

void	set_nbr_file(file *file)
{
	bool toggle = false;
	std::string input;
	std::cout << "How many files do you need ? (max 10) : ";
	while (toggle == false)
	{
		if (!(std::getline(std::cin, input)))
		{
			throw(GetLineException());
			return ;
		}
		if (is_digit(input) == 0)
		{
			std::cout << "Wrong input please try again : ";
			input.erase();
		}
		if (std::atoi(input.c_str()) > 10 || std::atoi(input.c_str()) <= 0)
		{
			std::cout << "Wrong number of files, please try again : ";
			input.erase();
		}
		else
		{
			file->nbr_file = std::atoi(input.c_str());
			toggle = true;
		}
	}
	return ;
}

void	init_struct(file *data)
{
	int i = 0;
	int j = 0;
	set_nbr_file(data);
	data->other_file = new std::string[data->nbr_file];
	while (i < data->nbr_file)
	{
		if (i == 0)
		{
			std::string input;
			while (input.empty())
			{
				std::cout << "Name your first file : ";
				if (!(std::getline(std::cin, input)))
				{
					throw(GetLineException());
					return ;
				}
			}
			data->first_file = input;
			input.erase();
		}
		else
		{
			std::string input;
			while (input.empty())
			{
				std::cout << "Name file n* " << i + 1 << " : ";
				if (!(std::getline(std::cin, input)))
				{
					throw(GetLineException());
					return ;
				}
			}
			data->other_file[j] = input;
			input.erase();
			j++;
		}
		i++;
	}
	return ;
}

void	create_first_file(file *file)
{
	std::string temp = file->first_file;
	std::string for_upper = file->first_file;
	temp.append(".class.hpp");
	std::cout << temp << std::endl;
	std::ofstream file_1(temp.c_str());
	if (file_1.fail())
	{
		std::cerr << "Error during opening file_1" << std::endl;
		return ;
	}
	std::string name = to_upper(for_upper);

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

void	create_other_file(file *file)
{
	std::string temp = file->other_file[file->tab_index];
	std::string for_upper = file->other_file[file->tab_index];
	std::cout << "temp = " << temp << std::endl;
	temp.append(".class.hpp");
	std::cout << temp << std::endl;
	std::ofstream file_1(temp.c_str());
	if (file_1.fail())
	{
		std::cerr << "Error during opening file_1" << std::endl;
		return ;
	}
	std::string name(to_upper(for_upper.c_str()));
	
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

void	final_moove(file* file)
{
	int i = 0;
	init_struct(file);
	while (i < file->nbr_file)
	{
		if (i == 0)
			create_first_file(file);
		else
			create_other_file(file);
		i++;
	}
	return ;
}