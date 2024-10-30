// For initial setup, player details, and displaying rules.

#ifndef GAMESETUP_H
#define GAMESETUP_H

#include <string>
#include <vector>
#include <iostream>

std::string getPlayerName(){
std::string name;
std::cout << "Please enter your name: ";
std::getline(std::cin, name);

    return name;
}

// Denna funktion gör bara så att funktionen getplayername kan kallas med variabeln playerName
//använd playerName för att skriva ut namnet som man hämtade.

int main(){

    std::string playerName = getPlayerName();
}

#endif
