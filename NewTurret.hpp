#ifndef NEWTURRET_HPP_INCLUDED
#define NEWTURRET_HPP_INCLUDED
#include "Turret.hpp"

class NewTurret: public Turret {
public:
	static const int Price;
    NewTurret(float x, float y);
	void CreateBullet() override;
};

#endif // NEWTURRET_HPP_INCLUDED
