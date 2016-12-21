#ifndef CREATE_HERO
#define CREATE_HERO

#include <iostream>
#include <assert.h>

class Hero {
public:
    static Hero* create_hero(int id);
    virtual void info() = 0;
    virtual int getStrength() = 0;
    virtual void addToGroup(Hero* heroes_) {assert(false); }
    virtual ~Hero() {}
};

class Wizard: public Hero {
public:
    void info() { std::cout << "a wizard!" << std::endl; }
    int getStrength() { return 50; }
};

class Warrior: public Hero {
public:
    void info() { std::cout << "a warrior!" << std::endl; }
     virtual int getStrength() { return 150; }
};

class Hunter: public Hero {
public:
    void info() { std::cout << "a hunter!" << std::endl; }
     virtual int getStrength() { return 100; }
};

class Priest: public Hero {
public:
    void info() { std::cout << "a priest!" << std::endl; }
     virtual int getStrength() { return 50; }
};

Hero* Hero::create_hero(int id) {
    switch (id) {
    case 1:
        return new Wizard();
        break;
    case 2:
        return new Warrior();
        break;
    case 3:
        return new Hunter();
        break;
    case 4:
        return new Priest();
        break;
    default:
        break;
    }
}

#endif // CREATE_HERO

