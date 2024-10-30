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

void displayBlackjackRules(){


    std::cout << "Welcome to Blackjack!\n";
    std::cout << "Rules!\n";
    std::cout << "1. The goal of the game is to get as close to 21 as possible without going over.\n";
    std::cout << "2. The number cards are worth their face value.\n";
    std::cout << "3. Face cards (Jack, Queen and King) Are worth 10.\n";
    std::cout << "4. Aces are either 1 or 11 depending on whats more favorable.\n";
    std::cout << "5. You can either hit (draw a card) or stand (End your turn).\n";
    std::cout << "6. If your hand exceeds 21, you bust and lose the round.\n";
    std::cout << "7. The dealer must hit until their total is atleast 17.\n";
    std::cout << "8. Whoever is closest to 21 without busting wins the round!\n";
    std::cout << "Good luck!\n";
}


#endif
