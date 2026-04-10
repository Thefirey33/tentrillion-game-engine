#include "services/renderingService.hpp"

#include "SDL3/SDL_init.h"
#include "SDL3/SDL_log.h"
#include "SDL3/SDL_video.h"
#include "SDL3/SDL_vulkan.h"
#include "services/vulkanBackendManagerService.hpp"
#include "tentrillion.hpp"
#include "tentrillionService.hpp"

#include <memory>
#include <vulkan/vulkan.h>
#include <vulkan/vulkan_core.h>

namespace TenTrillionGameEngine {
RenderingService::RenderingService(const int windowWidth,
								   const int windowHeight,
								   const char *windowTitle,
								   TentrillionEngine *engine)
	: TenTrillionService("WindowService", engine) {
	this->windowWidth = windowWidth;
	this->windowHeight = windowHeight;
	this->backend = VULKAN;

	const bool isVulkanLoaded = SDL_Vulkan_LoadLibrary(nullptr);
	backend = isVulkanLoaded ? VULKAN : OPENGL;

	this->windowInstance = SDL_CreateWindow(windowTitle, SDL_WINDOWPOS_CENTERED,
											SDL_WINDOWPOS_CENTERED,
											(backend ? SDL_WINDOW_VULKAN : 0));

	switch (backend) {
	case VULKAN:
		this->vulkanBackendManagerService =
			std::make_unique<VulkanBackendManagerService>(this, engine);
		break;
	case OPENGL:
		break;
	}
}

SDL_Window *RenderingService::getWindowInstance() const {
	return this->windowInstance;
}

void RenderingService::executeOnVulkanOnly(
	const std::function<void()> &callback) const {
	if (this->backend == VULKAN)
		callback();
}

void RenderingService::executeOnOpenGlOnly(
	const std::function<void()> &callback) const {
	if (this->backend == OPENGL)
		callback();
}

void RenderingService::quitService() { SDL_Quit(); }
} // namespace TenTrillionGameEngine