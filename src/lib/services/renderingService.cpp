#include "services/renderingService.hpp"

#include "SDL3/SDL.h"
#include "SDL3/SDL_init.h"
#include "SDL3/SDL_log.h"
#include "SDL3/SDL_render.h"
#include "SDL3/SDL_video.h"
#include "SDL3/SDL_vulkan.h"
#include "services/vulkanBackendManagerService.hpp"
#include "tentrillion.hpp"
#include "tentrillionService.hpp"

#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <vulkan/vulkan.h>
#include <vulkan/vulkan_core.h>

namespace TenTrillionGameEngine {
RenderingService::RenderingService(
	int windowWidth, int windowHeight, const char *windowTitle,
	TenTrillionGameEngine::TentrillionEngine *engine)
	: TenTrillionService("WindowService", engine) {
	this->windowWidth = windowWidth;
	this->windowHeight = windowHeight;
	SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,
				"starting ten-trillion rendering service...");
	this->windowInstance = SDL_CreateWindow(
		windowTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		SDL_WINDOW_VULKAN | SDL_WINDOW_OPENGL);
	this->engine->addTenTrillionService(
		new VulkanBackendManagerService(this, this->engine));
}

void RenderingService::quitService() { SDL_Quit(); }
} // namespace TenTrillionGameEngine