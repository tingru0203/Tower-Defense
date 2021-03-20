#ifndef NEWBULLET_HPP_INCLUDED
#define NEWBULLET_HPP_INCLUDED
#include "Bullet.hpp"

class Enemy;
class Turret;
namespace Engine {
struct Point;
}  // namespace Engine

class NewBullet : public Bullet {
public:
	explicit NewBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent);
	void Update(float deltaTime) override;
	void OnExplode(Enemy* enemy) override;
};


#endif // NEWBULLET_HPP_INCLUDED
