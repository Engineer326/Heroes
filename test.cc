#include <iostream>
#include "adapted.h"
#include "create.h"
#include "group.h"
#include "main.cpp"
#include <vector>

/* Binary
   #define EXPECT_EQ(expr1, expr2) EXPECT_TRUE((expr1) == (expr2))
   #define EXPECT_NE(expr1, expr2) EXPECT_TRUE((expr1) != (expr2))
   #define EXPECT_LT(expr1, expr2) EXPECT_TRUE((expr1) < (expr2))
   #define EXPECT_LE(expr1, expr2) EXPECT_TRUE((expr1) <= (expr2))
   #define EXPECT_GT(expr1, expr2) EXPECT_TRUE((expr1) > (expr2))
   #define EXPECT_GE(expr1, expr2) EXPECT_TRUE((expr1) >= (expr2))
   */


#include "limo/test_main.hpp"

    LTEST (main_win_lose) {
        int bossH_ = 1200;
        int heroesAttack_ = 800;
        EXPECT_NE("You LOSE!", winner(bossH_, heroesAttack_));
    };

    LTEST (main_win_win) {
        int bossH_ = 800;
        int heroesAttack_ = 1200;
        EXPECT_NE("You won!", winner(bossH_, heroesAttack_));
    };

    LTEST (adapter_after) {
        WizardS w_ = new WizardS;
        int attack_ = w.getStrength();
        int attack_m = w.toAttack();
        EXPECT_LT(attack_, attack_m);
    };

    LTEST (group_attack) {
        CompositeGroup group_ = new CompositeGroup;
        group_.addToGroup(new WizardS);
        group_.addToGroup(new WarriorS);
        group_.addToGroup(new HunterS);
        group_.addToGroup(new PriestS);
        int group_attack = group_.getStrength();
        EXPECT_EQ(350, group_attack);
    };
