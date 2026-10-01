#include "jumpable_enemy.hpp"

#include "map_movable.hpp"

using NovSev::JumpableEnemy;

JumpableEnemy::JumpableEnemy(const Coord& top_left, const int width, const int height) 
	: RectMapMovableAdapter(top_left, width, height) {
	vspeed = 0;
	hspeed = 0.2;
}

NovSev::Rect JumpableEnemy::get_rect() const noexcept {
	return {top_left, width, height};
}

NovSev::Speed JumpableEnemy::get_speed() const noexcept {
	return {vspeed, hspeed};
}

void JumpableEnemy::process_horizontal_static_collision(Rect* obj) noexcept {

}

void JumpableEnemy::process_mario_collision(Collisionable* mario) noexcept {
	const Rect mario_rect = mario->get_rect();
	const float mario_bottom = mario_rect.get_y() + mario_rect.get_height();
	const float previous_mario_bottom =
		mario_bottom - mario->get_speed().v;
	const float enemy_top = get_rect().get_y();
	const float previous_enemy_top = enemy_top - get_speed().v;

	const bool mario_landed_on_top =
		mario->get_speed().v > 0 &&
		previous_mario_bottom <= previous_enemy_top;

	if (mario_landed_on_top) {
		kill();
	} else {
		mario->kill();
	}
}

void JumpableEnemy::process_vertical_static_collision(Rect* obj) noexcept {
	if (vspeed > 0) {
		top_left.y -= vspeed;
		vspeed = 0;
	}
	else if (vspeed < 0) {
		top_left.y -= vspeed;
		vspeed = 0;
	}
}

void JumpableEnemy::move_horizontally() noexcept {
    
}

void JumpableEnemy::move_vertically() noexcept {
    if (!is_active()) {
		Movable::move_vertically();
		return;
	}
	
    if (vspeed == 0) {
        jump();
    }

    Movable::move_vertically();

}


