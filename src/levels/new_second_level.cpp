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

	ui_factory->create_ship({24, 24}, 30, 2);
	ui_factory->create_ship({59, 21}, 22, 2);
	ui_factory->create_ship({85, 24}, 20, 2);
	ui_factory->create_ship({111, 21}, 20, 2);
	ui_factory->create_ship({135, 24}, 13, 2);

	ui_factory->create_enemy({36, 22}, 3, 2);
	ui_factory->create_enemy({116, 19}, 3, 2);
	ui_factory->create_jumpable_enemy({88, 22}, 2, 2);

	ui_factory->create_ship({150, 16}, 2, 6);
	ui_factory->create_ship({180, 16}, 2, 6);
	ui_factory->create_moving_platform({152, 20}, 12, 2);
	ui_factory->create_flyable_enemy({160, 17}, 2, 2);

	ui_factory->create_ship({185, 24}, 15, 2);
}
