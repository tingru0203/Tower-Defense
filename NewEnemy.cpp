#include <string>

#include "NewEnemy.hpp"

NewEnemy::NewEnemy(int x, int y) : Enemy("play/enemy-4.png", x, y, 10, 100, 50, 100) {
	// TODO 2 (6/8): You can imitate the 2 files: 'SoldierEnemy.hpp', 'SoldierEnemy.cpp' to create a new enemy.
}

void NewEnemy::Update(float deltaTime) {
    if(hp < 20) {
        ChangeSpeed(2);
    }
    Enemy::Update(deltaTime);
}
