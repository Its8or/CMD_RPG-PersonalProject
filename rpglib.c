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
    int attack;
    int defense;
    int action;
    bool isAlive;
};

typedef struct {
    char* name;
    int lvl;
    int hp;
    int attack;
    int defense;
    bool isAlive;
} Player;

int rollDice() {
    srand(time(NULL));
    int value = (rand() % 20)+1;
    return value;
}

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

struct Enemy enemyLib(const char name[], struct Enemy *enemy) {
    // ========== normal foes =====
    if (strcmp(name, "goblin") == 0) { // Usar strcmp para comparação de strings
        enemy->name = 'g'; // Atribuir o primeiro caractere ou usar um ponteiro para string
        enemy->hp = 48;
        enemy->attack = 6;
        enemy->defense = 12;
        enemy->action = 2;
        enemy->isAlive = true;
    }
    else if (strcmp(name, "bandit") == 0) { // Usar strcmp
        enemy->name = 'b';
        enemy->hp = 50;
        enemy->attack = 9;
        enemy->defense = 14;
        enemy->action = 2;
        enemy->isAlive = true;
    }
    // ========== hard foe ========
    else if (strcmp(name, "skeleton") == 0) { // Usar strcmp
        enemy->name = 's';
        enemy->hp = 55;
        enemy->attack = 11;
        enemy->defense = 8;
        enemy->action = 2;
        enemy->isAlive = true;
    }
    // ========== bosses ==========
    // only @ lvl => 5
    else if (strcmp(name, "orc") == 0) { // Usar strcmp
        enemy->name = 'o';
        enemy->hp = 70;
        enemy->attack = 15;
        enemy->defense = 20;
        enemy->action = 3;
        enemy->isAlive = true;
    }
    // only @ lvl => 15
    else if (strcmp(name, "dragon") == 0) { // Usar strcmp
        enemy->name = 'd';
        enemy->hp = 100;
        enemy->attack = 40;
        enemy->defense = 20;
        enemy->action = 4;
        enemy->isAlive = true;
    }
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
