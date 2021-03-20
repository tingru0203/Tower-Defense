#ifndef NEWENEMY_HPP_INCLUDED
#define NEWENEMY_HPP_INCLUDED
#include "Enemy.hpp"

class NewEnemy : public Enemy {
public:
	NewEnemy(int x, int y);
	void Update(float deltaTime) override;
};

#endif // NEWENEMY_HPP_INCLUDED
