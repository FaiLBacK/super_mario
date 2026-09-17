#include "flyable_enemy.hpp"

#include "map_movable.hpp"

using NovSev::FlyableEnemy;

FlyableEnemy::FlyableEnemy(const Coord& top_left, const int width, const int height) 
	: RectMapMovableAdapter(top_left, width, height) {
	vspeed = 0;
	hspeed = 0.2;
}

NovSev::Rect FlyableEnemy::get_rect() const noexcept {
	return {top_left, width, height};
}

NovSev::Speed FlyableEnemy::get_speed() const noexcept {
	return {vspeed, hspeed};
}

void FlyableEnemy::process_horizontal_static_collision(Rect* obj) noexcept {
	hspeed = -hspeed;
	move_horizontally();
}

void FlyableEnemy::process_mario_collision(Collisionable* mario) noexcept {
	if (mario->get_speed().v > 0 && mario->get_speed().v != V_ACCELERATION) {
		kill();
	} else {
		mario->kill();
	}
}

void FlyableEnemy::process_vertical_static_collision(Rect* obj) noexcept {

}

void FlyableEnemy::move_horizontally() noexcept {
    top_left.x += hspeed;
}

void FlyableEnemy::move_vertically() noexcept {
    top_left.y += vspeed;
}