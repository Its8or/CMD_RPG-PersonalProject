#include <stdio.h>
#include <stdbool.h>
#include "rpglib.h"

int main() {
    Player player = {"none", 1, 20, 10, 16,true,};
    Inventory inv = {50, 0, 0};

    int playerAction;
    int counterEncounter = 1; // starts in combat

    // double hpModifier = 1.6;
    struct Enemy foo = {"XXX", 0, 0, 0, 0,true};
    char encounterFoo[20] = "";
    int enemy = 0;

    // Todo:
    //   [   ] remaining modifiers;
    //   [ x ] system to LevelUp;
    //   [   ] combat mechanic;
    //   [   ] shopping system;
    //   [ x ] return naming system;
    //   [ x ] encounter System;

    printf("Welcome to RPGiC!\n");

    while (player.isAlive == true) {
        enemy = encounter(player.lvl, 5);
        // Tells what enemy player will encounter
        enemyName(enemy, encounterFoo);
        enemyLib(encounterFoo, &foo);

        // level up logic: each 3 encounters player increases a level.
        if (counterEncounter % 3 == 0) player.lvl++;

        if (player.hp <= 0) {
            player.isAlive = false;
        }

        while (foo.isAlive == true) {
            printf("You encounter a %s.\n", encounterFoo);
            printf("Lvl: %d | HP: %d\n", player.lvl, player.hp);
            printf("%s life: %d\n", encounterFoo, foo.hp);

            // todo: player actions
            printf("Make an action:\n");
            printf("1. Attack\n"
                "2. Block\n"
                "3. Use potion\n"
                ">  ");

            scanf(" \n", &playerAction);

            switch (playerAction) {
                case 1:
                    // todo player attack foo
                    // roll d20
                    int roll = rollDice();
                    (roll > foo.defense) ? foo.hp -= player.attack : foo.hp;
                    break;
                case 2:
                    // todo player blocks foo attack
                    // roll d20
                    rollDice();
                // roll > enemy.attack ? player takes half-damage: player.hp -= enemy.attack
                    break;
                case 3:
                    if (inv.healPotion <= 0) {
                        printf("You don't have enough potions\n");
                    } else {
                        player.hp += 20;
                        inv.healPotion -= 1;
                        printf("You used one potion,you current hp is %d and "
                               "you have %d potion\n", player.hp, inv.healPotion);
                    }
                    break;
                default:
                    printf("invalid action, choose again\n");
                    break;
            }
        }

        if (foo.hp <= 0) {
            foo.isAlive = false;
            printf("%s defeated!\n", encounterFoo);
        }

        counterEncounter++;

        //todo: farming time
        printf("== Buying Phase ==\n");

        if (player.lvl == 3) {
            player.isAlive = false;
        }

    }

    printf("\nYou're DEAD!");

    return 0;
}
