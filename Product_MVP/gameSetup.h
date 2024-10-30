// For initial setup, player details, and displaying rules.
#include <string>
#include <vector>
#include <iostream>

std::string getPlayerName()
{
    std::string name;
    std::cout << "Please enter your name: ";
    std::getline(std::cin, name);

    return name;
}

// Denna funktion gör bara så att funktionen getplayername kan kallas med variabeln playerName
// använd playerName för att skriva ut namnet som man hämtade.

void displayBlackjackRules()
{

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
    std::cout << "This is not your usual blackjack game, there will be some twists when you least expect it Such as : LOREM IPSUM DOLER";
    std::cout << "Good luck!\n";
}

void displayTwistRules()
{
    std::cout << "1. Free Hit Twist:\n";
    std::cout << "   - Drawn cards that trigger this twist allow you to take a 'free hit' without the risk of busting.\n";
    std::cout << "   - You can only use this twist once per turn when it's triggered.\n\n";

    std::cout << "2. Reset Hand Value Twist:\n";
    std::cout << "   - If this twist is triggered, it resets the hand value of either the player or dealer to 10.\n";
    std::cout << "   - Useful for avoiding a bust or getting a strategic advantage.\n\n";

    std::cout << "3. Card Swap Twist:\n";
    std::cout << "   - This twist allows you to swap one card from your hand with one of the dealer’s cards.\n";
    std::cout << "   - Choose wisely, as this twist can change the outcome significantly!\n\n";

    std::cout << "4. Double Bet Twist:\n";
    std::cout << "   - Triggering this twist automatically doubles the current bet, adding extra excitement and risk.\n";
    std::cout << "   - You must have enough balance to cover the doubled bet, or the twist will be canceled.\n\n";

    std::cout << "5. Twist Cards:\n";
    std::cout << "   - Specific cards like the Ace of Spades or Queen of Hearts are designated as twist cards.\n";
    std::cout << "   - When a twist card is drawn by either the player or dealer, it triggers one of the twists above.\n\n";

    std::cout << "Good luck! Keep an eye out for twist cards and use them strategically to gain an advantage.\n";
}
