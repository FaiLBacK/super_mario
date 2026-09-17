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
	ui_factory->create_mario({40, 10}, 3, 3);

	ui_factory->create_ship({30, 5}, 20, 2);
	ui_factory->create_ship({60, 10}, 20, 2);
}
