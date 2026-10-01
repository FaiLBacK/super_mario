#pragma once

#include "collisionable.hpp"
#include "mario.hpp"
#include "movable.hpp"
#include "rect_map_movable_adapter.hpp"

namespace NovSev {
	class MovingPlatform : public RectMapMovableAdapter, public Movable, public Collisionable {
		private:
			static constexpr float PLATFORM_SPEED = 0.5f;
			Mario* mario = nullptr;
			float previous_x = 0.0f;
			float carried_mario_delta = 0.0f;
			bool mario_was_riding = false;

			void undo_horizontal_step() noexcept;

		public:
			MovingPlatform(
				const Coord& top_left, const int width, const int height
			);

			Rect get_rect() const noexcept override;
			Speed get_speed() const noexcept override;

			void process_horizontal_static_collision(Rect*) noexcept override;
			void process_mario_collision(Collisionable*) noexcept override;
			void process_vertical_static_collision(Rect*) noexcept override;

			void move_horizontally() noexcept override;
			void move_vertically() noexcept override;

			void set_mario(Mario* mario) noexcept;
	};
}