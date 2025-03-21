#ifndef RPG_H
#define RPG_H

#include <string>
#include <vector>

class RPG {
private:
    std::string name;
    int health;
    int strength;
    int defense;
    std::string type;
    std::vector<std::string> skills;

public:
    // Constructors
    RPG();  // Default constructor
    RPG(std::string name, int health, int strength, int defense, std::string type);  // Overloaded constructor

    // Accessor functions
    std::string getName() const;
    int getHealth() const;
    int getStrength() const;
    int getDefense() const;
    const std::vector<std::string>& getSkills() const;  // Const reference for skills

    // Functions for setting skills
    void setSkills();

    // Functions for the battle system
    void attack(RPG& target, int skillIndex);
    void updateHealth(int new_health);
    bool isAlive() const;
    void printAction(const std::string& skill, RPG& target);
};

#endif
