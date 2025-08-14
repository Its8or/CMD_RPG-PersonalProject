#include <stdio.h>
#include <stdbool.h>
#include "rpglib.h"

int main() {
    Player player= {"none",1,20,10,16,true};

    int playerAction;
    int counterEncounter = 1; // starts in combat

    // double hpModifier = 1.6;

    char encounterFoo[] = "";
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
        enemyLib(encounterFoo);

        // level up logic: each 3 encounters player increase a level.
        if ( counterEncounter % 3 == 0 ) player.lvl++;

        // if (player.hp <= 0) {
        //     player.isAlive = false;
        // }

        // todo: Combat

        printf("You encounter a %s.\n", encounterFoo);

        printf("Lvl: %d | HP: %d\n", player.lvl, player.hp);

        // todo: player actions
        printf("Make an action:\n");
        printf("1. Attack\n"
               "2. Block\n"
               "3. Use Item\n"
               ">  ");

        scanf(" \n", &playerAction);

        switch (playerAction) {
            case 1:
                // todo player attack foo

            case 2:
                // todo player blocks foo attack
            case 3:
                // todo player item (show inventory);
            default:
                printf("invalid action, choose again\n");
        }

        //todo: farming time
        printf("== Buying Phase ==\n");

        if (player.lvl == 3) {
            player.isAlive = false;
        }

        counterEncounter++;
    }

    printf("\nYou're DEAD!");

    return 0;
}