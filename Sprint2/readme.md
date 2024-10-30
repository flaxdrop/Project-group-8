## Sprint 2: Enhanced Game Mechanics and Game Flow

**Goal**: Add enhancements to gameplay, ensure fair shuffling,twists and improve game interactivity and robustness.

### Tasks:
- **Improved Game Flow**:
  - Add the ability to reset hands, reshuffle the deck, and start a new round seamlessly.
  - Implement `startNewRound()` function to clear player and dealer hands at the start of each new round.
  - Create a `promptNewRoundOrQuit()` function to ask the player if they want to start a new round or quit the game.

- **Deck and Hand Management**:
  - Ensure the deck reshuffles at the beginning of each round for fairness.
  - Refactor `calculateHandValue()` to properly handle Ace values for both player and dealer.

- **Player and Dealer Enhancements**:
  - Refine dealer AI to follow Blackjack rules, such as stopping at a total of 17 or higher.
  - Implement game prompts to provide a clearer user experience, including feedback on each card dealt and updated hand values.
  - Add twists to the game
  
- **Code Review and Refactoring**:
  - Conduct a code review to improve code readability, modularity, and maintainability.
  - Add comments to clarify the purpose of each function and improve documentation.