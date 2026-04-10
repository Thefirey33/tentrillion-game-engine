#include "tentrillion.hpp"
#include "SDL3/SDL_init.h"
#include "SDL3/SDL_log.h"
#include "services/renderingService.hpp"
#include <cstdlib>
#include <memory>

TenTrillionGameEngine::TentrillionEngine
	*TenTrillionGameEngine::TentrillionEngine::tenTrillionInstance;

namespace TenTrillionGameEngine {
TentrillionEngine::TentrillionEngine() {
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_GAMEPAD) == false) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
					 "Couldn't initialize SDL context.\n");
		exit(1);
	}
	tenTrillionInstance = this;
}

void TentrillionEngine::initializeInstance(const int windowWidth,
										   const int windowHeight,
										   const char *windowTitle) {
	this->renderingService = std::make_unique<RenderingService>(
		windowWidth, windowHeight, windowTitle, this);
}

void TentrillionEngine::exitInstance() {}

TentrillionEngine *TentrillionEngine::getTenTrillionInstance() {
	return tenTrillionInstance;
}

} // namespace TenTrillionGameEngine