#ifndef GROUP
#define GROUP

#include "create.h"
#include <assert.h>
#include <vector>

class Group {
public:
    virtual int getStrength() = 0;
    virtual void addToGroup( Group* group_) {assert(false); }
    virtual ~Group() {}
};

class WizardS: public Group {
public:
    virtual int getStrength() { return 50; }
};

class WarriorS: public Group {
public:
    virtual int getStrength() { return 150; }
};

class HunterS: public Group {
public:
    virtual int getStrength() { return 100; }
};

class PriestS: public Group {
public:
    virtual int getStrength() { return 50; }
};

class CompositeGroup: public Group {
private:
    std::vector<Group*> g;
public:
    int getStrength() {
        int total = 0;
        for ( auto i :  g ) {
            total += i -> getStrength();
        }
        return total;
    }
    void addToGroup(Group* group_) {
        g.push_back( group_);
    }
    ~CompositeGroup() {
        for ( auto i :  g ) {
            delete i;
        }
    }
};

CompositeGroup* toRaid() {
    CompositeGroup* squad = new CompositeGroup;
    int amount = rand() % 5;
    for (int i = 0; i < amount; i++ ) { squad -> addToGroup(new WizardS);}
    for (int i = 0; i < amount; i++ ) { squad -> addToGroup(new WarriorS);}
    for (int i = 0; i < amount; i++ ) { squad -> addToGroup(new HunterS);}
    for (int i = 0; i < amount; i++ ) { squad -> addToGroup(new PriestS);}
    return squad;
}

#endif // GROUP

