#include "RPG.h"
#include <iostream>
#include <algorithm>  // For std::max

// Default constructor for RPG
RPG::RPG() {
    name = "NPC";
    health = 100;
    strength = 10;
    defense = 10;
    type = "warrior";
    skills = { "slash", "parry" };  // Initialize skills with default values
}

// Overloaded constructor to initialize RPG with custom values
RPG::RPG(std::string name, int health, int strength, int defense, std::string type)
    : name(name), health(health), strength(strength), defense(defense), type(type) {
    setSkills();
}

// Accessor functions
std::string RPG::getName() const {
    return name;
}

int RPG::getHealth() const {
    return health;
}

int RPG::getStrength() const {
    return strength;
}

int RPG::getDefense() const {
    return defense;
}

const std::vector<std::string>& RPG::getSkills() const {
    return skills;
}

// Function to set skills based on the character's type
void RPG::setSkills() {
    if (type == "mage") {
        skills = { "fire", "thunder" };
    }
    else if (type == "thief") {
        skills = { "pilfer", "jab" };
    }
    else if (type == "archer") {
        skills = { "parry", "crossbow" };
    }
    else {
        skills = { "slash", "parry" };
    }
}

// Attack function to apply damage to the target based on the selected skill
void RPG::attack(RPG& target, int skillIndex) {
    if (skillIndex < 0 || skillIndex > 1) {
        std::cerr << "Invalid skill index!\n";
        return;
    }

    int damage = 0;
    if (skillIndex == 0) {
        damage = strength + 5;  // Skill 0 damage
    }
    else if (skillIndex == 1) {
        damage = strength + 7;  // Skill 1 damage
    }

    // Apply damage to the target
    target.updateHealth(target.getHealth() - damage);
}

// Function to update health
void RPG::updateHealth(int new_health) {
    health = std::max(0, new_health);  // Prevent negative health
}

// Function to check if the character is still alive (health > 0)
bool RPG::isAlive() const {
    return health > 0;
}

// Function to print out the action taken (e.g., skill used)
void RPG::printAction(const std::string& skill, RPG& target) {
    std::cout << name << " used " << skill << " on " << target.getName() << "\n";
}
