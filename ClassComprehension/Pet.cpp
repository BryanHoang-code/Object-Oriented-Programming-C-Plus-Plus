#include <iostream>
#include "Pet.h"
using namespace std;

    pet::pet() {
        name = "N'A";
        age = 0;
        owner = "N/A";
        isHouseTrained = false;
    }
    pet::pet(string name, int age, string owneer, bool isHouseTrained){
        this->name = name;
        this->age = age;
        this->owner = owner;
        this ->isHouseTrained = isHouseTrained;
    }

    string pet::getName() const {
        return name;
    };
    int pet::getAge() const {
        return age;
    }
    string pet::getOwner() const{
        return owner;
    }
    bool pet::getisHouseTrained() const {
        return isHouseTrained;
    }

    void pet::updateName (string new_name){
        name = new_name;
    }
    void pet::updateAge () {
       age++;
    }
    void pet::updateOwner (string new_owner){
        owner = new_owner;
    }
    void pet:: updateisHouseTrained() {
        isHouseTrained = true;
    }
