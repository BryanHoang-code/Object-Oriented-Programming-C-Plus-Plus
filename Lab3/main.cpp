#include <iostream>
#include "RPG.h"

// Function to display skills of a character
void displaySkills(const RPG& character) {
    const std::vector<std::string>& skills = character.getSkills();
    for (int i = 0; i < skills.size(); ++i) {
        std::cout << "Skill " << i << ": " << skills[i] << "\n";
    }
}

// Function to allow the user to select the opponent's type
std::string chooseOpponentClass() {
    std::string opponentType;
    std::cout << "Choose the character to fight:\n";
    std::cout << "1. Mage\n";
    std::cout << "2. Thief\n";
    std::cout << "3. Archer\n";
    std::cout << "4. Warrior\n";
    std::cout << "Enter your choice (1-4): ";

    int choice;
    std::cin >> choice;

    // Set the opponent class based on the user's choice
    switch (choice) {
    case 1: opponentType = "mage"; break;
    case 2: opponentType = "thief"; break;
    case 3: opponentType = "archer"; break;
    case 4: opponentType = "warrior"; break;
    default:
        std::cout << "Invalid choice, defaulting to Warrior.\n";
        opponentType = "warrior";
        break;
    }

    return opponentType;
}

int main() {
    // NPC is the player's character (fixed as "NPC")
    RPG player("NPC", 100, 15, 10, "warrior");  // Player character is always NPC as a "warrior"

    // Allow user to choose the opponent class
    std::string opponentClass = chooseOpponentClass();
    RPG opponent("Enemy", 100, 15, 5, opponentClass);  // Opponent character based on user's choice

    // Display initial health of both characters
    std::cout << "NPC health: " << player.getHealth() << "  " << opponentClass << " health: " << opponent.getHealth() << "\n";

    // Start the battle loop
    while (player.isAlive() && opponent.isAlive()) {
        std::cout << "\nNPC's turn\n";
        displaySkills(player);

        int choice;
        std::cout << "Choose a skill to use (0 or 1): ";
        std::cin >> choice;

        if (choice < 0 || choice > 1) {
            std::cout << "Invalid skill choice! Using skill 0.\n";
            choice = 0;
        }

        const std::vector<std::string>& playerSkills = player.getSkills();
        player.attack(opponent, choice);
        player.printAction(playerSkills[choice], opponent);

        // Print health after NPC's attack
        std::cout << "NPC health: " << player.getHealth() << "  " << opponentClass << " health: " << opponent.getHealth() << "\n";
        std::cout << "------------------------------------------\n";

        if (opponent.isAlive()) {
            std::cout << "\n" << opponentClass << "'s turn\n";  // Using opponent's type (e.g., Mage, Thief)
            displaySkills(opponent);

            // Simulate opponent choosing a random skill
            int opponentChoice = rand() % 2;
            const std::vector<std::string>& opponentSkills = opponent.getSkills();
            opponent.attack(player, opponentChoice);
            opponent.printAction(opponentSkills[opponentChoice], player);

            // Print health after opponent's attack
            std::cout << "NPC health: " << player.getHealth() << "  " << opponentClass << " health: " << opponent.getHealth() << "\n";
            std::cout << "------------------------------------------\n";
        }
    }

    // Check who won
    if (player.isAlive()) {
        std::cout << "NPC wins!\n";
    }
    else {
        std::cout << opponentClass << " wins!\n";  // Show the name of the opponent type (Mage, Thief, etc.)
    }

    return 0;
}
