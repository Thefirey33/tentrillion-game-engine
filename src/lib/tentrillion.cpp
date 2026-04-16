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
	this->displayTenTrillionInformation();
	tenTrillionInstance = this;
}

void TentrillionEngine::initializeInstance(Vector windowSize,
										   const char *windowTitle) {
	this->renderingService =
		std::make_unique<RenderingService>(windowSize, windowTitle, this);
}

void TentrillionEngine::displayTenTrillionInformation() {
#ifdef TENTRILLION_DEFAULT_RUNTIME
	SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,
				"TenTrillion, Made by Thefirey33");
#else
	SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,
				"TenTrillion Compatibility for older Platforms");
#endif
}

void TentrillionEngine::exitInstance() { SDL_Quit(); }

TentrillionEngine *TentrillionEngine::getTenTrillionInstance() {
	return tenTrillionInstance;
}

} // namespace TenTrillionGameEngine