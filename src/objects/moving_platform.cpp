#include "moving_platform.hpp"

#include <cmath>

using NovSev::MovingPlatform;

MovingPlatform::MovingPlatform(
	const Coord& top_left, const int width, const int height
) : RectMapMovableAdapter(top_left, width, height) {
	vspeed = 0.0f;
	hspeed = PLATFORM_SPEED;
	previous_x = top_left.x;
}

NovSev::Rect MovingPlatform::get_rect() const noexcept {
	return {top_left, width, height};
}

NovSev::Speed MovingPlatform::get_speed() const noexcept {
	return {vspeed, hspeed};
}

void MovingPlatform::undo_horizontal_step() noexcept {
	top_left.x = previous_x;
	hspeed = -hspeed;
	if (mario != nullptr && carried_mario_delta != 0.0f) {
		mario->move_horizontal_offset(-carried_mario_delta);
	}
	carried_mario_delta = 0.0f;
}

void MovingPlatform::process_horizontal_static_collision(Rect* obj) noexcept {
	if (obj == this || hspeed == 0.0f) {
		return;
	}

	const int previous_left = static_cast<int>(std::round(previous_x));
	const int previous_right = static_cast<int>(std::round(previous_x + width));
	const bool hit_from_left =
		hspeed > 0.0f && previous_right <= obj->get_left();
	const bool hit_from_right =
		hspeed < 0.0f && previous_left >= obj->get_right();

	if (hit_from_left || hit_from_right) {
		undo_horizontal_step();
	}
}

void MovingPlatform::process_mario_collision(Collisionable* other) noexcept {
	if (other != mario || mario_was_riding || hspeed == 0.0f) {
		return;
	}

	const Rect mario_rect = mario->get_rect();
	const int mario_left = mario_rect.get_left();
	const int mario_right = mario_rect.get_right();
	const int previous_left = static_cast<int>(std::round(previous_x));
	const int previous_right = static_cast<int>(std::round(previous_x + width));
	const bool hit_from_left = hspeed > 0.0f && previous_right <= mario_left;
	const bool hit_from_right = hspeed < 0.0f && previous_left >= mario_right;

	if (hit_from_left || hit_from_right) {
		undo_horizontal_step();
	}
}

void MovingPlatform::process_vertical_static_collision(Rect*) noexcept {}

void MovingPlatform::move_horizontally() noexcept {
	previous_x = top_left.x;
	mario_was_riding = false;
	carried_mario_delta = 0.0f;

	if (mario != nullptr && mario->is_active() && mario->get_speed().v == 0.0f) {
		const Rect mario_rect = mario->get_rect();
		const float mario_bottom = mario_rect.get_y() + mario_rect.get_height();
		const float mario_left = mario_rect.get_left();
		const float mario_right = mario_rect.get_right();

		mario_was_riding =
			std::abs(mario_bottom - get_y()) <= 1.0f &&
			mario_right > get_x() &&
			mario_left < get_x() + width;
	}

	top_left.x += hspeed;

	if (mario_was_riding) {
		carried_mario_delta = top_left.x - previous_x;
		mario->move_horizontal_offset(carried_mario_delta);
	}
}

void MovingPlatform::move_vertically() noexcept {}

void MovingPlatform::set_mario(Mario* mario) noexcept {
	this->mario = mario;
}