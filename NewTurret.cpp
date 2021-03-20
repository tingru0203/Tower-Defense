#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "NewBullet.hpp"
#include "Group.hpp"
#include "NewTurret.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"

const int NewTurret::Price = 400;
NewTurret::NewTurret(float x, float y) :
	Turret("play/tower-base.png", "play/turret-7.png", x, y, 400, Price, 1) {
	Anchor.y += 8.0f / GetBitmapHeight();
}
void NewTurret::CreateBullet() {
	Engine::Point diff = Engine::Point(cos(Rotation - ALLEGRO_PI / 2), sin(Rotation - ALLEGRO_PI / 2));
	float rotation = atan2(diff.y, diff.x);
	Engine::Point normalized = diff.Normalize();
	Engine::Point normal = Engine::Point(-normalized.y, normalized.x);
	// Change bullet position to the front of the gun barrel.
	getPlayScene()->BulletGroup->AddNewObject(new NewBullet(Position + normalized * 36 - normal * 6, diff, rotation, this));
	getPlayScene()->BulletGroup->AddNewObject(new NewBullet(Position + normalized * 36 + normal * 6, diff, rotation, this));
	AudioHelper::PlayAudio("gun.wav");
}
