#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

int enemyRandomizer(int numberEnemies) {
    srand(time(NULL));
    int value = rand() % numberEnemies;
    return value;
}

void enemyName(int enemy, char name[]) {
    if (enemy == 0) {
        strcpy(name,"goblin");
    }
    if (enemy == 1) {
        strcpy(name,"bandit");
    }
    if (enemy == 2) {
        strcpy(name,"skeleton");
    }
    if (enemy == 3) {
        strcpy(name,"orc");
    }
    if (enemy == 4) {
        strcpy(name,"dragon");
    }
}

struct Enemy enemyLib(const char name[]) {

    struct Enemy enemy = {"XXXXX",0,0,0,0,true};

    // ========== normal foes =====
    if (name == "goblin") {
        struct Enemy goblin =             {"goblin", 48, 6, 12,2,true}; // enemy[0]
        enemy = goblin;
    }

    if (name == "bandit") {
        struct Enemy bandit =             {"bandit", 50, 9, 14,2,true}; // enemy[1]
        enemy = bandit;
    }

    // ========== hard foe ========
    if (name == "skeleton") {
        struct Enemy skeleton =           {"skeleton", 55, 11, 8,2,true}; // enemy[2]
        enemy = skeleton;
    }

    // ========== bosses ==========

    // only @ lvl =>  5
    if (name == "orc") {
        struct Enemy orc =                {"Orc", 70, 15,20,3,true}; // enemy[3]
        enemy = orc;
    }
    // only @ lvl => 15
    if (name == "dragon") {
        struct Enemy dragon =             {"Dragon", 100, 40, 20,4,true}; // enemy[4]
        enemy = dragon;
    }
    return enemy;
}

int actionRandomizer(int numberActions) {
    srand(time(NULL));
    int value = rand() % numberActions;
    return value;
}

int encounter(int playerlvl, int numberEnemiesOnGame) {
    const int value = enemyRandomizer(numberEnemiesOnGame);

    if (value == 0 || value == 1) {
        return value;
    }
    if (value == 2) {
        if (playerlvl < 4) {
            encounter(playerlvl, numberEnemiesOnGame - 1);
        } else return value;
    }
    if (value == 3) {
        if (playerlvl < 5) {
            encounter(playerlvl, numberEnemiesOnGame - 1);
        } else return value;
    }
    if (value == 4) {
        if (playerlvl < 15) {
            encounter(playerlvl, numberEnemiesOnGame - 1);
        } else return value;
    }
}
