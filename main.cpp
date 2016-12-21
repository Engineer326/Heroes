#include "create.h"
#include "group.h"
#include "adapted.h"
#include <vector>

std::string winner (int x, int y) {

    if (x <= y) {
       return "You won!";
    }
    else {
       return "You LOSE!";
    }
}

int main()
{
    std::vector<Hero*> heroes_;
    int id;
    std::cout << "1.Wizard 2.Warrior 3.Hunter 4.Priest 0.Exit" << std::endl;
    do {
       std::cin >> id;
       heroes_.push_back(Hero::create_hero(id));
    } while (0 != id);
    std::cout << "Now you have to take part in a raid! Create a group!" << std::endl;
    std::cout << "Could your group win the Boss?... " << std::endl;
    int bossH =  rand() % 1750;
    std::cout << "Boss's level " << bossH << std::endl;
    CompositeGroup* new_group = new CompositeGroup;
    new_group -> addToGroup(toRaid());
    int heroesAttack = new_group -> getStrength();
    std::cout << heroesAttack << std::endl;
    std:: string result = winner(bossH, heroesAttack);
    if (result == "You LOSE!") {
        std::cout<< "but if you use magic power... " << std::endl;
        FromMagicPower* new_wizard = new Adapter(new WizardS);
        heroesAttack = heroesAttack + new_wizard -> toAttack();
        std::cout << winner(bossH, heroesAttack);
    }
    else {
        std::cout << "Congrats!!" << result << std::endl;
    }
    std::cout << "" << std::endl;
    delete new_group;
    return 0;
}
