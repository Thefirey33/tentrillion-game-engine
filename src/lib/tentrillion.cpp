#include "tentrillion.hpp"
#include "SDL3/SDL_init.h"
#include "SDL3/SDL_log.h"
#include "services/renderingService.hpp"
#include <cstdio>
#include <cstdlib>
#include <memory>
#include <ostream>
#include <stdbool.h>

namespace TenTrillionGameEngine {
TentrillionEngine::TentrillionEngine() {
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) == false) {
		SDL_LogError(
			SDL_LOG_CATEGORY_APPLICATION,
			"couldn't create context for rendering and audio. exiting.\n");
		exit(1);
	}
}

void TentrillionEngine::init(const int windowWidth, const int windowHeight,
							 const char *windowTitle) {
	this->addTenTrillionService(
		new RenderingService(windowWidth, windowHeight, windowTitle, this));
}

void TentrillionEngine::quit() {
	for (auto &[fst, snd] : this->TenTrillionServices) {
		snd->quitService();
		delete snd;
	}
}

void TentrillionEngine::addTenTrillionService(TenTrillionService *service) {
	this->TenTrillionServices.try_emplace(service->getServiceName(), service);
}

TenTrillionService *
TentrillionEngine::getTenTrillionServiceByName(const std::string &name) {
	if (const auto &iterator = this->TenTrillionServices.find(name);
		iterator != this->TenTrillionServices.end()) {
		return iterator->second;
	}
	return nullptr;
}

} // namespace TenTrillionGameEngine