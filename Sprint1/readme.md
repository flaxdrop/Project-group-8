# Blackjack Game Development

This project is a command-line Blackjack game developed in C++ as part of a multi-sprint project. Each sprint focuses on developing and refining core features, improving the game’s functionality, and implementing game logic.

## Project Overview
The game simulates a Blackjack card game with player and dealer mechanics, including options to hit, stand, and reset the game for a new round. The goal is to develop a playable and interactive experience with each sprint focusing on different aspects of the game.

---

## Sprint 1: Initial Setup and Basic Functionality

**Goal**: Set up the initial project structure and implement basic game functionality to play a simple round of Blackjack.

### Tasks:
- **Project Initialization**:
  - Create the repository, set up project files, and write an initial `README.md`.
  - Display Blackjack rules on startup using `displayBlackjackRules()` function.

- **Basic Game Mechanics**:
  - Implement core card struct (`Card`) with values for face cards, number cards, and Ace.
  - Implement `shuffleDeck()` function to shuffle the deck randomly.
  - Develop a `dealCard()` function to deal cards to the player and dealer.
  - Create basic game flow for player and dealer turns:
    - **Player actions**: hit or stand.
    - **Dealer actions**: hit until reaching a minimum score of 17.

- **Basic Win/Loss Logic**:
  - Implement basic logic to determine round winners based on hand values.
  - Display results and prompt the player to start a new round or quit.