#pragma once

#include "game_level.hpp"

namespace NovSev {
	class NewSecondLevel : public GameLevel {
		public:
			NewSecondLevel(UIFactory* ui_factory);
			
			GameLevel* get_next() override;
			bool is_final() const noexcept override;
			
		private:
			void init_data() override;
	};
}