#ifndef ADAPTED
#define ADAPTED

#include "create.h"
#include "group.h"

class FromMagicPower {
  public:
    virtual int toAttack() = 0;
    virtual ~FromMagicPower() {}
};

class Adapter: public FromMagicPower {
public:
    Adapter( WizardS* w) : wizard_(w) {}
    ~Adapter() {delete wizard_; }
    int toAttack() {
        return wizard_ -> getStrength() + 100;
    }
private:
    WizardS* wizard_;
};

#endif // ADAPTED

