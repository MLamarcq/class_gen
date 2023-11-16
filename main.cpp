#include "file.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "Need argument !" << std::endl;
        return (0);
    }

    std::string file_1(argv[1]);
    std::string temp = file_1;
    file_1.append(".class.hpp");
    std::ofstream file(file_1.c_str());

    if (file.fail())
	{
		std::cerr << "Error during opening file" << std::endl;
		return (0);
	}

    std::string name(to_upper(argv[1]));

    file << "#ifndef " << name.append("_CLASS_HPP") << std::endl;
    file << "#define " << name << std::endl << std::endl;
    
    file << "#include <string>" << std::endl;
    file << "#include <iostream>" << std::endl;
    file << "#include <fstream>" << std::endl << std::endl;

    file << "class " << temp;

    return (0);
    (void)argc;
    (void)argv;
}