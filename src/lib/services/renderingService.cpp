#include "services/renderingService.hpp"
#include "SDL3/SDL.h"
#include "SDL3/SDL_init.h"
#include "SDL3/SDL_log.h"
#include "SDL3/SDL_render.h"
#include "SDL3/SDL_video.h"
#include "SDL3/SDL_vulkan.h"
#include "tentrillionService.hpp"
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <vulkan/vulkan.h>
#include <vulkan/vulkan_core.h>

namespace TenTrillionGameEngine {
RenderingService::RenderingService(int windowWidth, int windowHeight,
								   const char *windowTitle)
	: TenTrillionService("WindowService") {

	this->windowWidth = windowWidth;
	this->windowHeight = windowHeight;

	// TODO: Use VULKAN API.
	SDL_CreateWindowAndRenderer(windowTitle, windowWidth, windowHeight,
								SDL_WINDOW_VULKAN, &this->windowInstance,
								&this->rendererInstance);
}

void RenderingService::quitService() {
	SDL_DestroyWindow(this->windowInstance);
	SDL_Quit();
}
} // namespace TenTrillionGameEngine