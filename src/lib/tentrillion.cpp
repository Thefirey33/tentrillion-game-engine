#include "tentrillion.hpp"
#include "SDL3/SDL_init.h"
#include "services/renderingService.hpp"
#include <cstdio>
#include <cstdlib>
#include <memory>
#include <stdbool.h>

namespace TenTrillionGameEngine {
TentrillionEngine::TentrillionEngine() {
	this->displayInformation();

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) == false) {
		fprintf(stderr, "failed to initialize sdl context.");
		exit(1);
	}
}

void TentrillionEngine::init() {
	this->windowService = std::make_unique<RenderingService>(800, 600, "Test");
}

void TentrillionEngine::quit() { this->windowService->quitService(); }

void TentrillionEngine::displayInformation() {
	printf("== tentrillion game engine ==\n");
	printf("version: %s\n", BUILD_VERSION);
}

} // namespace TenTrillionGameEngine