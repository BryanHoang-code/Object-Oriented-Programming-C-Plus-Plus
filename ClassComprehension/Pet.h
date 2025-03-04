#ifndef Pet_H
#define Pet_H
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class pet {

public:

    pet();
    pet (string name, int age, string owner, bool isHouseTrained);

    //mutator functions
    void updateName (string new_name);
    void updateAge ();
    void updateOwner (string new_owner);
    void updateisHouseTrained ();

    //accessor functions
    string getName() const;
    int getAge() const;
    string getOwner () const;
    bool getisHouseTrained() const;

private:
    string name;
    int age;
    string owner;
    bool isHouseTrained;
};
#endif
