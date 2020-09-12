#include "vector_strings.hpp"

#include <iostream>
#include <vector>

enum command {
    ADD,
    PRINT,
    REMOVE,
    QUIT,
};

command str2cmd(std::string input_cmd){
    if (input_cmd == "PRINT")
        return PRINT;
    else if (input_cmd == "ADD")
        return ADD;
    else if (input_cmd == "REMOVE")
        return REMOVE;
    else
        return QUIT;
}

void Adder(std::vector<std::string>& names) {
    std::string name;
    std:: cout << "Enter a name:" << std::endl;
    std::cin >> name;
    names.push_back(name);
    std::cout << "Number of names in the vector:" << std::endl;
    std::cout << names.size() << std::endl;
}

void Remover(std::vector<std::string>& names) {
    std::cout << "Removing the last element:" << std::endl;
    std::cout << names.back() << std::endl;
    names.pop_back();
}

void Printer(std::vector<std::string>& names) {
    for (std::string name : names)
        std::cout << name << std::endl;
}

void CMDReader() {
    std::vector<std::string> name_list;
    std::string input_cmd;
    command cmd;

    std::cout << "Commands: ADD, PRINT, REMOVE, QUIT" << std::endl;
    while (cmd != QUIT) {
        std::cout << "Enter a command:" << std::endl;
        std::cin >> input_cmd;
        cmd = str2cmd(input_cmd);
        switch (cmd) {
            case ADD:
                Adder(name_list);
                break;
            case REMOVE:
		Remover(name_list);
                break;
            case PRINT:
		Printer(name_list);
                break;
            case QUIT:
	        return;
	}
    }
}

