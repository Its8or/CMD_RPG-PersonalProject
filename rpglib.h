//
// Created by Heitor on 07/08/2025.
//

#ifndef RPGLIB_H
#define RPGLIB_H

typedef struct {
    int storageLimit;
    int healPotion;
    int armor;
} Inventory;

struct Enemy {
    char name;
    int hp;
    int atack;
    int defense;
    int action;
    bool isAlive;
};

typedef struct {
    char* name;
    int lvl;
    int hp;
    int atack;
    int defense;
    bool isAlive;
    Inventory backpack;
} Player;


int enemyRandomizer(int numberEnemies);

void enemyName(int enemy, char name[]);

struct Enemy enemyLib(const char name[]);

int actionRandomizer(int numberActions);

int encounter(int playerlvl, int numberEnemiesOnGame);

#endif //RPGLIB_H
