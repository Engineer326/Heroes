#ifndef CREATE_H
#define CREATE_H

#endif // CREATE_H

#include <iostream>

enum Character_id { Wizard, Warrior, Priest, Hunter, Warlock, Paladin };

class Character {
    public:
    virtual void info();
    virtual ~Character() {}
    static Character* create(Character_id);
};

class Wizard: public Character {
public:
    void info () {
        std::cout << "You created a wizard! " << std::endl;
    }
};

class Warrior: public Character {
public:
    void info () {
        std::cout << "You created a Warrior! " << std::endl;
    }
};

class Priest: public Character {
public:
    void info () {
        std::cout << "You created a Priest! " << std::endl;
    }
};

class Hunter: public Character {
public:
    void info () {
        std::cout << "You created a Hunter! " << std::endl;
    }
};

class Warlock: public Character {
public:
    void info () {
        std::cout << "You created a Warlock! " << std::endl;
    }
};

class Paladin: public Character {
public:
    void info () {
        std::cout << "You created a Paladin! " << std::endl;
    }
};
