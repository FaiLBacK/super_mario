#include "new_second_level.hpp"

using NovSev::NewSecondLevel;

NewSecondLevel::NewSecondLevel(UIFactory* ui_factory) : GameLevel(ui_factory) {
	init_data();
}

bool NewSecondLevel::is_final() const noexcept {
	return true;
}

NovSev::GameLevel* NewSecondLevel::get_next() {
	return next;
}

// ----------------------------------------------------------------------------
// 									PROTECTED
// ----------------------------------------------------------------------------
void NewSecondLevel::init_data() {
	ui_factory->create_mario({35, 10}, 3, 3);

	ui_factory->create_ship({30, 26}, 20, 2);
	ui_factory->create_ship({60, 20}, 10, 2);
    ui_factory->create_ship({75, 25}, 20, 2);
      ui_factory->create_ship({105, 20}, 15, 2);

    ui_factory->create_flyable_enemy({45, 15}, 2, 2);
	ui_factory->create_jumpable_enemy({80, 15}, 2, 2);
}
