#include "console_flyable_enemy.hpp"

using NovSev::ConsoleFlyableEnemy;

ConsoleFlyableEnemy::ConsoleFlyableEnemy(const Coord& top_left, const int width, const int height) 
	: FlyableEnemy(top_left, width, height) {}

char ConsoleFlyableEnemy::get_brush() const noexcept {
	return 'f';
}