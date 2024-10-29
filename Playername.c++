#include <iostream>
#include <string>

std::string getPlayerName(){
std::string name;
std::cout << "Please enter your name: ";
std::getline(std::cin, name);

    return name;
}