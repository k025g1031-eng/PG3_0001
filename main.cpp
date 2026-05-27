#include "Enemy.h"

int main() {

    Enemy enemy;

    enemy.Initialize();

    for (int i = 0; i < 6; i++) {

        enemy.Update();

        enemy.Draw();
    }

    return 0;
}